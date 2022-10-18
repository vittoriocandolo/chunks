#include <stdio.h>
#include <stdlib.h>

#define MAX_length 64

char msg[MAX_length], enc[MAX_length], dec[MAX_length];
int key;

void getString(){

    printf("Enter a string: ");
    scanf("%s", msg);
    //scanf("%[^\n]s", msg);

}

void getKey(){

    printf("Enter a key: ");
    scanf("%d", &key);

}

void cipher(int option){

    char c;

    if(option == 0){
        
        for(int i = 0; msg[i] != '\0'; i++){

        c = msg[i];
        c += key;
        enc[i] = c;

        }

        printf("%s", enc);
        
    }else{

        for(int i = 0; msg[i] != '\0'; i++){

            c = msg[i];
            c -= key;
            dec[i] = c;

        }

        printf("\n%s", dec);
        
    }

}

int main(){

    getString();
    getKey();
    printf("Enter 0 to encrypt or enter 1 to decrypt: ");
    int op = 0;
    scanf("%d", &op);
    cipher(op);
    return 0;

}

