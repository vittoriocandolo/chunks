#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *str1, char *str2)
{
    int len = strlen(str1) + strlen(str2);
    char *result = malloc(len + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main()
{
    char input1[] = "Ciao ";
    char input2[] = "Gatto";
    printf("%s\n", concat(input1, input2));
    return 0;
}

