#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 2) //first parameter is always program name
    {
        printf("usage: two_args_calc <operation>\n");
        return 1;
    }
    else
    {
        if(strcmp(argv[1], "sum") == 0)
        {
            printf("Inserire i due addendi\n");
            int a = 0, b = 0;
            int n = scanf("%d, %d", &a, &b);
            if( n == 2)
            {
                printf("%d\n", a + b);
            }
            else
            {
                printf("Errore di input\n");
                return 1;
            }
        }
        else if(strcmp(argv[1], "mul") == 0)
        {
            printf("Inserire i due fattori\n");
            int a = 0, b = 0;
            int n = scanf("%d, %d", &a, &b);
            if( n == 2)
            {
                printf("%d\n", a * b);
            }
            else
            {
                printf("Errore di input\n");
                return 1;
            }
        }
        else
        {
            printf("Operazione non supportata\n");
            return 1;
        }
    }
    return 0;
}

