#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>

struct data_t {
  int *data;
  size_t len;
};

struct data_t read_nums(FILE *file);
int max_in_data(int *data, size_t len);
void *compute_max(void *ptr);

int main(int argc, char **argv)
{
  if(argc < 3) {
    fprintf(stderr, "Specificare il numero di thread e il nome di un file\n");
    return 1;
  }

  char *endp = NULL;
  long n_threads = strtol(argv[1], &endp, 10);
  if(*endp != 0) {
    fprintf(stderr, "Specificare il numero di thread e il nome di un file\n");
    return 1;
  }

  if(n_threads < 1) {
    fprintf(stderr, "Il numero di thread richiesti deve essere positivo\n");
    return 1;
  }

  FILE *file = fopen(argv[2], "rb");
  if(!file) {
    perror("fopen()");
    return 2;
  }

  struct data_t data = read_nums(file);
  printf("Letti %zu numeri interi.\n", data.len);

  /*
   * Divido i dati in n blocchi
   */
  struct data_t *blocks = calloc(n_threads, sizeof(struct data_t));
  int blocksize = data.len / n_threads;

  // Calcolo i puntatori all'inizio di ogni blocco
  for(int i = 0; i < n_threads; ++i) {
    blocks[i].data = data.data + i * blocksize;
    blocks[i].len = blocksize;
  }
  blocks[n_threads - 1].len += data.len % n_threads;

  /*
   * Faccio partire i thread
   */
  pthread_t *threads = calloc(n_threads, sizeof(pthread_t));
  for(int i = 0; i < n_threads; ++i) {
    pthread_create(&threads[i], NULL, compute_max, &blocks[i]);
  }

  /*
   * Aspetto la fine di ogni thread e ottengo i risultati parziali
   */
  int max = INT_MIN;
  for(int i = 0; i < n_threads; ++i)
  {
    // Aspetto il thread
    void *resultptr = NULL;
    pthread_join(threads[i], &resultptr);

    // Copio il risultato e libero la memoria usata per restituirlo
    int result = *(int*)resultptr;
    free(resultptr);

    // confronto con il massimo parziale
    if(result > max)
      max = result;
  }

  free(threads);
  free(blocks);

  printf("Il massimo numero trovato è %d\n", max);

  return 0;
}

void *compute_max(void *ptr) {
  struct data_t data = *(struct data_t *)ptr;

  int *result = malloc(sizeof(int));
  *result = max_in_data(data.data, data.len);

  return result;
}

int max_in_data(int *data, size_t len) {
  printf("max_in_data(%p, %zu)\n", data, len);
  int max = INT_MIN;
  for(int i = 0; i < len; ++i) {
    if(data[i] > max)
      max = data[i];
  }
  return max;
}

#define NITEMS 2000
struct data_t read_nums(FILE *file)
{
  size_t size = NITEMS;
  struct data_t data = {
    .len = 0,
    .data = malloc(sizeof(int) * size)
  };

  int r = 0;
  while((r = fread(data.data + data.len, sizeof(int), NITEMS, file)) == NITEMS)
  {
    data.len += r;
    size += NITEMS;
    data.data = realloc(data.data, sizeof(int) * size);
  }

  return data;
}

