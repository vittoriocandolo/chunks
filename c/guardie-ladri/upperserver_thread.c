#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/un.h> // per struct sockaddr_un
#include <sys/socket.h>
#include <pthread.h>

#include "common.h"

void upperlines(int in, int out);
void *connection(void *arg);

int main (int argc, char **argv)
{
  // configuro il processo per ignorare SIGPIPE
  signal(SIGPIPE, SIG_IGN);

  // apro il socket di ascolto
  int sock = socket(AF_LOCAL, SOCK_STREAM, 0);
  check(sock, 1, "socket()");

  // imposto l'indirizzo del socket
  struct sockaddr_un addr = {
    .sun_family = AF_LOCAL,
    .sun_path = SOCKADDR
  };

  // mi preoccupo di rimuovere il file del socket in caso esista già.
  // se è impegnato da un altro server non si potrà rimuovere, ma bind()
  // successivamente mi darà errore
  unlink(SOCKADDR);
  // lego l'indirizzo al socket di ascolto
  check(bind(sock, (struct sockaddr *)&addr, sizeof addr), 2, "bind()");

  // Abilito effettivamente l'ascolto, con un massimo di 5 client in attesa
  listen(sock, 5);

  fprintf(stderr, "In ascolto.\n");

  // continuo all'infinito ad aspettare client
  while (1)
  {
    struct sockaddr_un client_addr;
    socklen_t client_len = sizeof(client_addr);

    /*
     * ogni volta che il server accetta una nuova connessione,
     * quest'ultima viene gestita da un nuovo thread
     */
    int *fd = malloc(sizeof(int));
    *fd = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    check(*fd, 3, "accept()");

    pthread_t thread;
    pthread_create(&thread, NULL, connection, fd);

    // Informiamo il sistema del fatto che non verrà mai chiamata pthread_join()
    pthread_detach(thread);
  }
}

void *connection(void *arg) {
  int fd = *(int *)arg;
  free(arg);

  fprintf(stderr, "Aperta connessione...\n");

  char greet[] = "Benvenuto all'UpperServer 1.0!\n";
  int greetlen = strlen(greet) + 1;
  send(fd, &greetlen, sizeof(greetlen), 0); // Invio lunghezza del messaggio
  send(fd, greet, greetlen, 0); // Invio il messaggio

  upperlines(fd, fd);

  close(fd); // Alla fine chiudiamo la connessione

  fprintf(stderr, "Chiusa connessione.\n");

  return NULL;
}

#define BLOCKSIZE 40

void upperlines(int in, int out)
{
  char inputline[BLOCKSIZE];
  ssize_t len = 0;

  while ((len = recv(in, inputline, BLOCKSIZE, 0)) > 0) {
    for (int i = 0; i < len; i++)
      inputline[i] = toupper(inputline[i]);
    send(out, inputline, len, 0);
  }
}

