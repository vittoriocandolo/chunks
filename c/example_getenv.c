#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
    if(argc < 2)
    {
        while(*envp)
        {
            printf("%s\n", *envp);
            ++envp;
        }
    }
    else
    {
        printf("%s=%s\n", argv[1], getenv(argv[1]));
    }
    return 0;
}

