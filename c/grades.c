#include <stdio.h>

#define N_ESAMI 12
int main() {
    int voti[N_ESAMI] = { 18, 30, 27, 20, 22, 28, 25, 25, 30, 27, 18, 26 };
    int crediti[N_ESAMI] = { 12, 12, 12, 12, 6, 6, 6, 6, 6, 6, 6 };
    int somma = 0, totale = 0;
    for(int i = 0; i < N_ESAMI; ++i) {
        somma += voti[i] * crediti[i];
        totale += crediti[i];
    }
    float media = (float) somma / totale; // Notare il cast esplicito a float
    printf("La mia media pesata e’: %2.2f\n", media);
    return 0;
}

