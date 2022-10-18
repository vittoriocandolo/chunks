#include <stdio.h>
#include <string.h>

void capitalize(char *);

int main()
{
    char input[] = "lorem ipsum dolor sit ames";
    capitalize(input);
    printf("%s\n", input);
    return 0;
}
void capitalize(char *str)
{
    int len = strlen(str);
    str[0] += -32;
    for(int i = 1; i < len - 1; i++)
    {
        if(str[i] == ' ')
        {
            str[i + 1] += -32;
        }
    }
}

