#include <stdio.h>

#define LOW 0
#define STEP 20
#define UP 300
#define COEFF 5.0/9.0

int main()
{
    for(float fahr = LOW; fahr <= UP; fahr = fahr + STEP)
    {
        float celsius = COEFF * (fahr - 32.0);
        printf("%3.0f °F -> %3.1f °C\n", fahr, celsius);
    }
    return 0;
}

