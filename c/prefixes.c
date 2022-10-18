#include <stdio.h>
#include <string.h>

#define SIZE 64

char word[SIZE];
int main(){
    scanf("%[^\n]s", word);
    int c = strlen(word);
    char temp[c + 1];
    for(int i = c; i > 0; i--){
        memset(temp, '\0', sizeof(temp));
        strncpy(temp, word, i);
        printf("%s\n", temp);
    }
    return 0;
}

