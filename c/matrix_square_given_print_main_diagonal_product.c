#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a;
    int r, p, i, j;

    printf("Enter rows and columns of a square matrix: ");
    scanf("%d", &r);

    a = (int **)malloc(sizeof(int *) * r);

    for(i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * r);
    }

    printf("Enter elements of matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Entered the matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", a[i][j]);

            if(j == r - 1)
            {
                printf("\n");
            }
        }
    }

    p = 1;
    for(i = 0; i < r; i++)
    {
        p = p * a[i][i];
    }

    printf("Prodotto degli elementi della diagonale principale: \n%d\n", p);

    return 0;
}

