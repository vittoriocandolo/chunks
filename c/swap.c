#include <stdio.h>

void swap(int *, int *);
int main()
{
    int x = 42, y = 0;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

