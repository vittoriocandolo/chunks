#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 14

int main()
{
    int pipes[2] = { };
    if(pipe(pipes) == -1)
    {
        perror("pipe call");
        return 1;
    }
    char msg[MSGSIZE] = { };
    pid_t pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork call");
            return 2;
        case 0:
            close(pipes[0]); // prima chiudere l'altro capo
            write(pipes[1], "Hello, world!", MSGSIZE); // monodirezionale [ 1 -> 0 ]
            break;
        default:
            close(pipes[1]);
            read(pipes[0], msg, MSGSIZE);
            printf("%s\n", msg);
            wait(NULL);
    }
    return 0;
}

