#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    pid_t pid;

    pid=fork();

    switch(pid)
    {
        case -1:

            fprintf(stderr, "fork failed!\n");
            return 1;

        case 0:

            if(argc == 2)
            {
                execlp("ps", "ps", argv[1], NULL);
            }
            else
            {
                execlp("ps", "ps", NULL);
            }
            fprintf(stderr, "execlp failed!\n");
            return 1;

        default :

            waitpid(pid, NULL, 0);
    }
    return 0;
}

