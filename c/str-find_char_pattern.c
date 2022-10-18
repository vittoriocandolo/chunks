#include <stdio.h>
#include <string.h>

#define SIZE 32

char *find_char(char *, char);
char *find_pattern(char *, char *);
int main()
{
    char input[] = "lorem ipsum dolor sit ames";
    char c = 'o';
    char pattern[] = "sum";
    printf("%s\n", find_char(input, c));
    printf("%s\n", find_pattern(input, pattern));
    return 0;
}
char *find_char(char *str, char c)
{
    for(char *p = str; *p; p++)
    {
        if(*p == c)
        {
            return p;
        }
    }

    return NULL; // segnala fine stringa
}
char *find_pattern(char *str, char *pattern)
{
    char temp[3] = "";
    for(char *p = str; *p; p++)
    {
        strncpy(temp, p, 3);
        if(strncmp(temp, pattern, 3) == 0) // con strcmp dava segmentatio fault
        {
            return p;
        }
    }
    return NULL;
}

