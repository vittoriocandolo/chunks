#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    pid_t pid;
    FILE *f;
    char c;

    if(argc != 2)
    {
        fprintf(stderr, "wrong number of arguments!\n");
        return 1;
    }

    f = fopen(argv[1], "r");

    if(f == NULL)
    {
        fprintf(stderr, "fopen failed!\n");
    }

    pid = fork();

    switch(pid)
    {
        case -1:

            fprintf(stderr, "fork failed!\n");
            return 1;

        case 0:

            while((c = fgetc(f)) != EOF)
            {
                printf("%c", c);
            }
            fclose(f);

            return 0;

        default :

            waitpid(pid, NULL, 0);
    }

    return 0;
}

