#include <stdio.h>

#define SIZE 8

int sum(int *);

int main()
{
    int input[SIZE] = { };
    int value = 0;
    for(int *p = input; p < input + SIZE; p++)
    {
        printf("Invia un addendo\n");
        scanf("%d", &value);
        *p = value;

    }
    printf("Somma = %d\n", sum(input));
    return 0;
}
int sum(int *array)
{
    int temp = 0;
    for(int i = 0; i < SIZE; i++)
    {
        temp += array[i];
    }
    return temp;
}

