#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, j;
    char *temp;

    if(argc < 2)
    {
        fprintf(stderr, "usage: %s str1 str2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc - 1; i++)
    {
        for(j = i + 1; j < argc; j++)
        {
            if(strcasecmp(argv[i], argv[j]) > 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }

    printf("\nIn lexicographical order:\n\n");

    for(i = 1; i < argc; i++)
    {
        puts(argv[i]);
    }

    printf("\n");

    return 0;
}

