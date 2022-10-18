#include <stdio.h>
#include <stdlib.h>
#include "dico_search.h"

#define SIZE 256

struct pair{
    int first;
    int second;
};

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

struct pair quadraticSumFinder(int *array, int key, int length){
    struct pair temp;
    temp.first = -1;
    temp.second = -1;
    for(int i = 0; i < length - 1; i++){
        for(int j = length - 1; j > i; j--){
            if(array[i] + array[j] == key){
                temp.first = i;
                temp.second = j;
                return temp;
            }
        }
    }
    return temp;
}

struct pair logSumFinder(int *array, int key, int length){
    struct pair temp;
    temp.first = -1;
    temp.second = -1;
    for(int i = 0; i < length - 1; i++){
        int target = dichotomousResearch(array, key - array[i], 0, length);
        if(target != -1){
            temp.first = i;
            temp.second = target;
            return temp;
        }
    }
    return temp;
}

struct pair linearSumFinder(int *array, int key, int length){
    int i = 0;
    int j = length - 1;
    struct pair temp;
    temp.first = -1;
    temp.second = -1;
    while(array[i] < array[j]){
        if(array[i] + array[j] == key){
            temp.first = i;
            temp.second = j;
            break;
        }else if(array[i] + array[j] == key){
            i++;
        }else{
            j--;
        }
    }
    return temp;
}

int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    int key;
    scanf("%d", &key);
    struct pair quadraticOut = quadraticSumFinder(inputArray, key, size);
    struct pair logOut = logSumFinder(inputArray, key, size);
    struct pair out = linearSumFinder(inputArray, key, size);
    //printf("%d", quadraticOut.first);
    //printf(" %d", quadraticOut.second);
    printf("%d", logOut.first);
    printf(" %d", logOut.second);
    //printf("%d", out.first);
    //printf(" %d", out.second);
    return 0;
}

