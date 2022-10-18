#include <stdio.h>
#include <string.h>

#define SIZE 64

char word[SIZE];
int main(){
    scanf("%[^\n]s", word);
    int c = strlen(word);
    for(int i = 0; i < c; i++){
        printf("%s\n", &word[i]);
    }
    return 0;
}

