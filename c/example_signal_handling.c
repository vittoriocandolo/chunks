#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ahah(int);

int main()
{
    signal(SIGINT, ahah);
    signal(SIGTERM, ahah);
    signal(SIGKILL, ahah); //CTRL+C non termina ma chiama void ahah
    while(1)
    {
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}

void ahah(int x)
{
    printf("you can't terminate me\n");
}

