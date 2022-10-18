#include <stdio.h>

int main() //close enough
{
    int n = 0;
    for(int c = getchar(); c != EOF; c = getchar())
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            for(int i = 0; i < n; i++)
            {
                printf("-");
            }
            printf("\n");
            n = 0;
        }
        else
        {
            n++;
        }
    }
    return 0;
}

