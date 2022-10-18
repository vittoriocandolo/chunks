#include <stdio.h>
#include <string.h>

void capitalize(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] -= 32;
    }
}
int main(){
    char stringa[] = "prova";
    capitalize(stringa);
    printf("%s", stringa);
    return 0;
}

