#include <stdio.h>
#include <string.h>

#define SIZE 64

int quadFractionalPeriod(char *s){
    int n = strlen(s);
    for(int p = 1; p <= n; p++){
        int guard = 1;
        for(int i = 0; (i < n) && guard; i++){
            if(s[i] != s[i % p]){
                guard = 0;
            }
        }
        if(guard){
            return p;
        }
    }
    return 0;
}

int maxBorder(char *s){
    int n = strlen(s);
    int r[n + 1];
    memset(r, 0, (n + 1)*sizeof(int));
    for(int i = 1; i < n; i++){
        int z = r[i];
        while((s[z] != s[i]) && (z > 0)){
            z = r[z];
        }
        if(s[z] == s[i]){
            r[i + 1] = z + 1; 
        }else{
            r[i + 1] = 0;
        }
    }
    return r[n];
}

int maxPeriod(char *s){
    int n = strlen(s);
    int r[n + 1];
    memset(r, 0, (n + 1)*sizeof(int));
    for(int i = 1; i < n; i++){
        int z = r[i];
        while((s[z] != s[i]) && (z > 0)){
            z = r[z];
        }
        if(s[z] == s[i]){
            r[i + 1] = z + 1; 
        }else{
            r[i + 1] = 0;
        }
    }
    return n - r[n];
}

int main(){
    char word[SIZE];
    scanf("%s", word);
    //printf("%d", quadFractionalPeriod(word));
    //printf("%d", maxBorder(word));
    printf("%d", maxPeriod(word));
}
