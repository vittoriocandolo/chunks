#include <stdio.h>

#define SIZE 32

int main()
{
    char line[SIZE] = "";
    int i = 0, c = getchar();
    while(c != EOF && c != '\n' && i < SIZE -1)
    {
            line[i] = c;
            i++;
            c = getchar();
    }
    line[i] = 0;
    printf("%s\n", line);
    return 0;
}

/*
#include <stdio.h>
#define SIZE 32
int main()
{
    char line[SIZE] = "";
    int i = 0;
    for(int c = getchar(); c != EOF && c != '\n'; c = getchar())
    {
        if(i == SIZE - 1)
        {
            break;
        }
            line[i] = c;
            i++;
    }
    line[i] = 0;
    printf("%s\n", line);
    return 0;
}
*/

// Si può fare con lo scorrimento a puntatori?

