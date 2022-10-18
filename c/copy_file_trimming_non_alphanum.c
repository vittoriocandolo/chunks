#include <stdio.h>
#include <stdlib.h>

#define LEN 1024 // compiler issue

int main(int argc, char **argv)
{
    char line[150];
    int i, j;
    FILE *f1, *f2;

    if(argc < 2)
    {
        fprintf(stderr, "usage: filter filename\n"); // posticcio
        return 1;
    }

    f1 = fopen(argv[1], "r");

    if(f1 == NULL)
    {
        fprintf(stderr, "error opening %s\n", argv[1]);
        return 2;
    }

    f2 = fopen("MyTmp.txt", "w"); // nome brutto

    if(f2 == NULL)
    {
        fprintf(stderr, "error opening output file\n");
        return 2;
    }

    while(fgets(line, LEN - 1, f1) != NULL)
    {
        for(i = 0; line[i] != '\0'; i++)
        {
            while (!(line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || (line[i] == '\0'))
            {
                for(j = i; line[j] != '\0'; j++)
                {
                    line[j] = line[j + 1];
                }
                line[j] = '\0';
            }
        }
        fputs(line, f2);
    }

    fclose(f2);
    fclose(f1);
    return 0;
}

