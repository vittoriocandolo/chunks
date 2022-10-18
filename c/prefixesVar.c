#include <stdio.h>
#include <string.h>

#define SIZE 64

char word[SIZE];
int main(){
    scanf("%[^\n]s", word);
    int c = strlen(word);
    for(int i = c; i >= 0; i--){
        for(int j = 0; j < i; j++){
            printf("%c", word[j]);
        }
       printf("\n");
    }
    return 0;
}

