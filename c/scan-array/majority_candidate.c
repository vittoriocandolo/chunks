#include <stdio.h>
#include "scan_array.h"

#define SIZE 512

int majorityCandidate(int *array, int length){
    int mc = array[0];
    int c = 1;
    for(int i = 1; i < length - 1; i++){
        if(array[i] == mc){
            c ++;
        }else{
            c --;
        }
        if(c <= 0){
            mc = array[i];
        }
    }
    return mc;
}
void majority(int *array, int length, int mc){
    int c = 0;
    for(int i = 0; i < length - 1; i++){
        if(array[i] == mc){
            c++;
        }
    }
    if(c > length / 2){
        printf("%d", mc);
    }else{
        printf("No majority");
    }
}
int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    majority(inputArray, size, majorityCandidate(inputArray, size));
    return 0;
}

