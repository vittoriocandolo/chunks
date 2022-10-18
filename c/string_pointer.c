#include <stdio.h>

int main() {
    char msg[] = "Ciao";
    printf("Stringa: \"%s\" \n", msg);
    printf("Caratteri: ");
    for(char *p = msg; *p; p++)
    {
        printf("'%c' ", *p);
    }
    putchar('\n');
    return 0;
}

