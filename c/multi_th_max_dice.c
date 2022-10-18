#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int max = 0;

void number_generator(void *);

int main(int argc, char **argv)
{
    int threads_number = 0;

    pthread_t *threads;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    //MUTEX

    if(argc != 2)
    {
        fprintf(stderr, "wrong number of arguments for %s\n", argv[0]);

        return 1;
    }
    else if(atoi(argv[1]) < 1)
    {
        fprintf(stderr, "argument must be a number greater than 1");

        return 2;
    }
    else
    {
        srandom(time(NULL));

        threads_number = atoi(argv[1]);

        threads = (pthread_t *)malloc(sizeof(pthread_t) * threads_number);

        for(int i = 0; i < threads_number; i++)
        {
            pthread_create(&threads[i], NULL, &number_generator, &mutex);
        }

        for(int i = 0; i < threads_number; i++)
        {
            pthread_join(threads[i], NULL);
        }

        free(threads);
    }

    return 0;
}

void number_generator(void *mtx)
{
    long int r;

    pthread_mutex_t *mutex = (pthread_mutex_t *) mtx;

    int guardia = 1;

    while(guardia)
    {
        r = random() %6 + 1;

        pthread_mutex_lock(mutex);

        if(r > max)
        {
            max = r;

            if(r == 6)
            {
                printf("È stato raggiunto il punteggio massimo!");
                guardia = 0;
            }

        }

        pthread_mutex_unlock(mutex);

        sleep(5);
    }

}
