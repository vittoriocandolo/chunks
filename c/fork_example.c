#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Un solo processo con PID %d.\n", (int)getpid());
    printf("Chiamata a fork...\n");
    pid_t pid = fork();
    if(pid == 0)
        printf("Sono il processo figlio con PID %d.\n", (int)getpid());
    else if(pid > 0)
        printf("Sono il processo padre con PID %d.\n", (int)getpid());
    else
        printf("Si è verificato un errore");
    return 0;
}

