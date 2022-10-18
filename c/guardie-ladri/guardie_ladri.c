#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <curses.h>
#include <sys/types.h>
#include <signal.h>

#define PASSO     1 /* entita' dello spostamento del ladro */

#define MAXX     80 /* Numero di colonne dello schermo */
#define MAXY     24 /* Numero di righe dello schermo */

/*
 * Struttura per la comunicazione tra figli e padre
 */
#define GUARDIA 0
#define LADRO 1

struct pos {
  int who;      // soggetto che invia il dato: ladro o guardia
  int x;        // coordinata x
  int y;        // coordinata y
};

// Funzioni di utilità
int processo(int *pipes, void (*f)(int));
void quit(int ret);
void message(char *msg);

// Funzioni di controllo del gioco
void ladro(int pipeout);
void guardia(int pipeout);
void controllo(int pipein);

int main()
{
  // Funzioni fornite da ncurses
  initscr();   // inizializzazione dello schermo
  noecho();    // disabilita la visualizzazione dei tasti premuti
  keypad(stdscr, 1); // abilito la gestione dei tasti freccia
  curs_set(0); // nasconde il cursore

  int pipes[2] = { 0 };
  if(pipe(pipes) == -1) {
    perror("Errore nella creazione della pipe.");
    return 1;
  }

  int pid_ladro = processo(pipes, ladro);
  int pid_guardia = processo(pipes, guardia);

  controllo(pipes[0]);

  // Chiediamo la terminazione dei processi del ladro e della guardia.
  kill(pid_ladro,1);
  kill(pid_guardia,1);

  // Comunichiamo la vincita e usciamo quando l'utente preme 'q'
  message("Hai vinto!");
  for(int c = 0; c != 'q'; c = getch());
  quit(0);
}

/*
 * Crea un processo figlio ed esegue nel figlio la funzione 'f' fornita come
 * argomento.
 */
int processo(int *pipes, void (*f)(int))
{
  pid_t pid = fork();
  switch(pid) {
    case -1:
      perror("fork()");
      exit(1);
    case 0:
      close(pipes[0]);
      f(pipes[1]);
  }
  return pid;
}

/*
 * Funzione chiamata per terminare il processo stando sicuri di dismettere
 * sempre ncurses correttamente
 */
void quit(int ret) {
  endwin(); // termina l'uso di ncurses
  exit(ret);
}

/*
 * Funzione di coordinazione del processo padre
 */
void controllo (int pipein)
{
  struct pos ladro = { LADRO, -1, -1 };
  struct pos guardia = { GUARDIA, -1, -1 };

  do
  {
    struct pos input_pos;
    // leggo la nuova posizione di uno dei due giocatori
    read(pipein, &input_pos, sizeof(struct pos));

    if(input_pos.who == LADRO)
      ladro = input_pos;
    else
      guardia = input_pos;

    // pulisco lo schermo e ridisegno la posizione dei due giocatori
    clear();
    mvaddch(ladro.y, ladro.x, '$');
    mvaddch(guardia.y, guardia.x, '#');

    // questa funzione mostra effettivamente le modifiche fatte allo schermo
    refresh();
  } while (guardia.x != ladro.x || guardia.y != ladro.y);
}

/*
 * Mostra una scritta in mezzo allo schermo
 */
void message(char *msg) {
  int x = MAXX / 2 - strlen(msg) / 2;
  int y = MAXY / 2;

  clear();
  for(int i = 0; msg[i]; ++i, ++x) {
    mvaddch(y, x, msg[i]);
  }
  refresh();
}

void ladro(int pipeout)
{
  struct pos pos_ladro = {
    .x = 0,
    .y = 0,
    .who = LADRO
  };

  // comunico la posizione iniziale del ladro
  write(pipeout, &pos_ladro, sizeof(struct pos));

  // inizializzo il seme della generazione di numeri casuali
  srandom(time(NULL));
  while(1)
  {
    int dx = PASSO;
    if(random() >= RAND_MAX / 2)
      dx = -PASSO;

    if(pos_ladro.x + dx < 0 || pos_ladro.x + dx >= MAXX)
      dx = -dx;

    pos_ladro.x += dx;

    int dy = PASSO;
    if(random() >= RAND_MAX / 2)
      dy = -PASSO;

    if(pos_ladro.y + dy < 0 || pos_ladro.y + dy >= MAXY)
      dy = -dy;

    pos_ladro.y += dy;

    write(pipeout, &pos_ladro, sizeof(struct pos));

    usleep(500000); // aspetto mezzo secondo
  }
}

void guardia(int pipeout)
{
  struct pos pos_guardia = {
    .who = GUARDIA,
    .x = MAXX - 1,
    .y = MAXY - 1
  };

  write(pipeout, &pos_guardia, sizeof(struct pos));

  while(1) {
    int c = getch(); // funzione di ncurses

    switch(c) {
      case KEY_UP:
        if(pos_guardia.y > 0)
          pos_guardia.y -= 1;
        break;
      case KEY_DOWN:
        if(pos_guardia.y < MAXY - 1)
          pos_guardia.y += 1;
        break;
      case KEY_LEFT:
        if(pos_guardia.x > 0)
          pos_guardia.x -= 1;
        break;
      case KEY_RIGHT:
        if(pos_guardia.x < MAXX - 1)
          pos_guardia.x += 1;
        break;
    }

    write(pipeout, &pos_guardia, sizeof(pos_guardia));
  }
}

