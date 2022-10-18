#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//reasonable length for a password
#define MAX_length 128

//subset of ASCII printable charachters
#define LOWER_bound 33
#define UPPER_bound 126

char msg[MAX_length];

void getString(){
    
    printf("Enter a string:\t");
    scanf("%s", msg);
    //scanf("%[^\n]s", msg);
    
}

void cipher(){
    
    char c;
    int k;
    
    for(int i = 0; msg[i] != '\0'; i++){
    
        if(i == MAX_length + 1){
        
            msg[i] = '\0';
            
            break;
            
        }
        
        k = random();
        c = msg[i];
        c += k;
        
        if((LOWER_bound > c) || (UPPER_bound < c)){
            
            
            c = (rand() % (UPPER_bound - LOWER_bound + 1)) + LOWER_bound;
            
        }
        
        msg[i] = c;
        
    }
    
    printf("%s", msg);
    
}

int main(){
    
    srandom((unsigned) time(0) * getpid());
    getString();
    srand(time(0));
    cipher();
    return 0;
    
}

