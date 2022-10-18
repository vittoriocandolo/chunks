#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "specificare un pattern da cercare\n");
        return 1;
    }
    int pipes[2] = { };
    if(pipe(pipes) == -1)
    {
        perror("pipe()");
        return 1;
    }
    pid_t ls = fork();
    switch(ls)
    {
        case -1:
            perror("fork()");
            exit(2); //termina il processo, 2 = exit status
        case 0:
            dup2(pipes[1], 1); //redirigo a stdout
            close(pipes[0]);
            execlp("ls", "ls", "-l", NULL);
            perror("ls");
            return 2;
    }
    pid_t less = fork();
    switch(less) {
        case -1:
            perror("fork()");
            exit(2);
        case 0:
            close(pipes[1]);
            dup2(pipes[0], 0);
            execlp("grep", "grep", argv[1], NULL);
            perror("grep");
    }
    close(pipes[0]);
    close(pipes[1]);
    waitpid(ls, NULL, 0);
    waitpid(less, NULL, 0);
    return 0;
}

