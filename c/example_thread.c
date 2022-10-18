#include <stdio.h>
#include <pthread.h>

void *print_msg(void *ptr);

int main()
{
    char msg1[] = "Thread 1";
    char msg2[] = "Thread 2";
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_msg, (void *)msg1);
    pthread_create(&thread2, NULL, print_msg, (void *)msg2);
    pthread_join(thread1, NULL); // aspetta la fine dell'altro
    pthread_join(thread2, NULL);
    //escono da soli, oppure void pthread_exit(void *retval);
    return 0;
}

void *print_msg(void *ptr)
{
    char *arg = (char *) ptr;
    while(1)
    {
        printf("%s\n", arg);
    }
    return NULL;
}

