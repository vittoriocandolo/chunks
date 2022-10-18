#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h> // extra
#include <unistd.h>
#include <fcntl.h>

#define SIZE 10

int main()
{
    //FILE *file = fopen("/dev/urandom", "rb");
    int file = open("/dev/urandom", O_RDONLY);
    /*if(!file)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }*/
    int values[SIZE] = { };
    //fread(values, sizeof(int), SIZE, file); // no fscanf in rb
    //int bytes = read(file, values, sizeof(int) * SIZE);
    read(file, values, sizeof(int) * SIZE);
    /*if(bytes != sizeof(int) * SIZE)
    {
        perror("Errore durante la lettura del file /dev/urandom");
        return 1;
    }*/
    for(int i = 0; i < SIZE; i++)
    {
        //printf("%d\n", values[i]);
        printf("%d\n", abs(values[i]));
    }
    return 0;
}

