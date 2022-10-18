#include <stdio.h>

#define N_ESAMI 7

int main()
{
    int voti[N_ESAMI] = { 18, 22, 18, 21, 28, 23, 22 };
    int crediti[N_ESAMI] = { 12, 12, 12, 12, 6, 6, 6 };
    int somma = 0, totale = 0;
    for(int i = 0; i < N_ESAMI; i++)
    {
        somma += voti[i] * crediti[i];
        totale += crediti[i];
    }
    float media = (float) somma / totale;
    printf("La mia media pesata è: %2.2f\n", media);
    return 0;
}

