#include <stdio.h>
#include <stdlib.h>
#include "dico_search.h"

#define SIZE 512

/**int scanArray(int *inputArray){
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
}**/

int dicoSearch(int *array, int key, int from, int to){
    int middle = (from + to) / 2;
    while (from <= to){
        if (array[middle] < key){
          from = middle + 1;
        }else if(array[middle] == key){
          return middle;
        }else{
          to = middle - 1;
        }
        middle = (from + to) / 2;
    }
    if(from > to){
    return -1;
    }
}

/**int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    int key;
    scanf("%d", &key);
    printf("%d", dicoSearch(inputArray, key, 0, size));
    return 0;
}**/
