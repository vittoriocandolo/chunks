#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

int scanArray(int *inputArray){
    char line[SIZE];
    scanf("%[^\n]s", line);
    int size = 0, offset = 0, numFilled, n;
    do{
        numFilled = sscanf(line + offset, "%d%n", &(inputArray[size]), &n);
        if(numFilled > 0){
            size++;
            offset += n;
        }
    }while(numFilled > 0);
    return size;
}

void negativesFirst(int *array, int length){
    int temp;
    for(int i = 0; i < length; i++){
        if(array[i] >= 0){
            temp = array[i];
            array[i] = array[length - 1];
            array[length - 1] = temp;
        }
    }
}

int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    negativesFirst(inputArray, size);
    for(int i = 0; i < size; i++){
        printf("%d", inputArray[i]);
    }
    return 0;
}

