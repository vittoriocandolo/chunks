#include <stdio.h>

int main()
{
    int n = 0;
    for(int c = getchar(); c != EOF; c = getchar())
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            n++;
        }
    }
    printf("%d", n);
    return 0;
}

