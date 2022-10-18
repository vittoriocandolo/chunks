#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

/*
 * Dato in input il numero di pseudo casuali da generare ne genera uno ogni 5 secondi, li stampa quando ha finito e stampa il massimo tra essi
 * Mentre lo fa, alla pressione di CTRL+C viene stampato un risultato parziale che indica il numero di numeri generati fin ora e il massimo tra questi
 * */

int compute_max = 0; // used as a boolean, CTRL+C activates the handler that sets it to 1 ( see * )

void handler(int);

int main()
{
    int last_index, current_index, n;
    last_index = current_index = n = 0;

    long int max = -1;
    long int *buffer = NULL;

    srandom(time(NULL));

    signal(SIGINT, handler);

    printf("Inserisci il numero di interi da generare: ");
    scanf("%d", &n);

    buffer = malloc(n * sizeof(long int));

    while(current_index < n)
    {
        if(compute_max) // *
        {
            for(int i = last_index; i < current_index; i++)
            {
                if(max < buffer[i])
                {
                    max = buffer[i];
                }
            }
            printf("\n");
            printf("Generated: %d\n", current_index);
            printf("Max = %ld\n", max);
            last_index = current_index;
            compute_max = 0;
        }
        else
        {
            buffer[current_index]=random();
            current_index++;
        }
        sleep(5);
    }
    printf("Final results:\n");
    for(int i = 0; i < n; i++)
    {
        if(i >= last_index)
        {
            if(max < buffer[i])
            {
                max = buffer[i];
            }
        }
        printf("Random[%d] = %ld\n", i, buffer[i]);
    }
    printf("Max = %ld\n", max);
    free(buffer);
    return 0;
}

void handler(int sig)
{
    compute_max = 1;
}

