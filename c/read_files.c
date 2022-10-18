#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("usage: read_files <file_1> ... <file_n>\n");

    }
    char *filename = NULL;
    FILE *file = NULL;
    for(int i = 1; i < argc; i++)
    {
        filename = argv[i];
        file = fopen(filename, "r");
        if(!file)
        {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
        for(char c = fgetc(file); c != EOF; c = fgetc(file))
        {
            putchar(c);
        }
        fclose(file);
    }
    return 0;
}

