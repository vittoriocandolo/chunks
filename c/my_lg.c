#include <stdio.h>

#define BASE 10
#define PARAM 100

int my_lg(int);

int main()
{
    printf("%d\n", my_lg(PARAM));
    return 0;
}
int my_lg(int value)
{
    int c = 0, temp = 1;
    while(temp * BASE <= value)
    {
        temp = temp * BASE;
        c++;
    }
    return c;
}

