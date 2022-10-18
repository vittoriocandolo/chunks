#include <stdio.h>
#include <stdlib.h>

#define SIZE 512 //needed?

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
