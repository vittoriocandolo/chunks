#include <stdio.h>

#define SIZE 8

int main()
{
    int input[SIZE] = { };
    int value = 0;
    printf("Inserisci un valore: ");
    scanf("%d", &value);
    for(int *p = input; p < input + SIZE; p++) //base + length
    {
        *p = value;
    }
    for(int i = 0; i < SIZE; i++)
    {
        printf("input[%d] = %d\n", i, input[i]);
    }
    return 0;
}

