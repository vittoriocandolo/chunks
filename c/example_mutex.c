#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int n = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *count(void *);

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, count, NULL);
    pthread_create(&th2, NULL, count, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("n: %d\n", n);
    return 0;
}

void*count(void*arg)
{
    int local_n = 0;
    do
    {
        usleep(500000);
        pthread_mutex_lock(&mutex);
        n += 1;
        local_n = n;
        pthread_mutex_unlock(&mutex);
        printf("n: %d\n", local_n);
    }
    while(local_n < 42);
    return NULL;
}

