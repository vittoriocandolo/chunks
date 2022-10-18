#include <stdio.h>

#define SIZE 8

int main()
{
    int input[8] = { };
    int value = 0;
    for(int *p = input + 7; p >= input; p--)
    {
        printf("Inserisci un valore\n");
        scanf("%d", &value);
        *p = value;
    }
    for(int i = 0; i < SIZE; i++)
    {
        printf("input[%d] = %d\n", i, input[i]);
    }
    return 0;
}

