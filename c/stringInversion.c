#include <stdio.h>
#include <string.h>

#define SIZE 64

char word[SIZE];
int main(){
    scanf("%[^\n]s", word);
    int c = strlen(word);
    for(int i = c - 1; i >= 0; i--){
       printf("%c", word[i]);
    }
    return 0;
}

