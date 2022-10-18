#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

int signaled = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void handler(int x)
{
    pthread_mutex_lock(&m);
    signaled = 1;
    pthread_mutex_unlock(&m);
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while(1)
    {
        pthread_mutex_lock(&m);
        if(signaled)
        {
            printf("You cannot terminate me!\n");
        }
        signaled = 0;
        pthread_mutex_unlock(&m);
        printf("Hey!\n");
        sleep(1);
    }
    return 0;
}

