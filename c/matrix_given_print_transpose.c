#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a, **transpose;
    int r, c, i, j;

    printf("Enter rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    a = (int **)malloc(sizeof(int *) * r);
    transpose = (int **)malloc(sizeof(int *) * c);

    for(i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(sizeof(int *) * c);
    }
    for(i = 0; i < c; i++)
    {
        transpose[i] = (int *)malloc(sizeof(int *) * c);
    }

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("Enter elemnt a[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEntered matrix:\n");
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);

            if( j == c - 1)
            {
                printf("\n");
            }
        }
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }

    printf("\nTransposed matrix:\n");
    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", transpose[i][j]);

            if(j == r - 1)
            {
                printf("\n");
            }
        }
    }

    printf("\n");

    return 0;

}

