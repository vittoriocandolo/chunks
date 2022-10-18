#include <stdio.h>

int main() {
    char msg[] = "Ciao";
    printf("Stringa: \"%s\" \n", msg);
    printf("Caratteri: ");
    for(int i = 0; msg[i]; i++)
    {
        printf("'%c' ", msg[i]);
    }
    putchar('\n');
    return 0;
}

