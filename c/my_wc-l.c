#include <stdio.h>

int main()
{
    long nc = 1;
    for(int c = getchar(); c != EOF; c = getchar())
    {
        if(c == '\n')
        {
            nc++;
        }
    }
    printf("%ld\n", nc);
    return 0;
}

/*
#include <stdio.h>
int main()
{
    long nc = 1;
    int c;
    while(getchar() != EOF)
    {
        if(getchar() == '\n') #non conta a capo di seguito
        {
            nc++;
        }
    }
    printf("%ld\n", nc);
    return 0;
}
*/

