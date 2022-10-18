#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SIZE 256

int main(int argc. char **argv[])
{
    if(argc != 3)
    {
        printf("usage: my_cmp <file1> <file2>");
        return 1;
    }
    char *filename_1 = argv[1];
    char *filename_2 = argv[2];
    FILE *file_1 = fopen(filename_1, "r");
    FILE *file_2 = fopen(filename_2, "r");
    if(!file_1 || !file_2)
    {
        fprintf(stderr, "%s\n", strerror(errno)); // ~
    }
    char str_1[SIZE] = "";
    char str_2[SIZE] = "";
    fgets(str_1, SIZE, file_1);
    fgets(str_2, SIZE, file_2);
    char *p_1 = NULL;
    char *p_2 = NULL;
    while(*p_1 && *p_2)
    {
        if(*p_1 == *p_2)
        {
            p_1++;
            p_2++;
        }
        else
        {
            printf("%s\n", p_1);
            printf("%s\n", p_2);
        }
    }
    fclose(file_1);
    fclose(file_2);
    return 0;
}

