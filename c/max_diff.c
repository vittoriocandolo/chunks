#include <stdio.h>
#include <stdlib.h>

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

struct pair maxDiff(int *array, int length){
    struct pair temp;
    temp.first = 0;
    temp.second = length - 1;
    int i = 0;
    int j = length - 1;
    int delta = -array[i] + array[j];
    while(i <= j){
        if(-array[i] + array[j] > delta){
            delta = -array[i] + array[j];
            temp.first = i;
            temp.second = j;
        }
        j--;
        if(i == j){
            i++;
            j = length - 1;
        }
    }
    return temp;
}

int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    struct pair out = maxDiff(inputArray, size);
    printf("%d", out.first);
    printf(" %d", out.second);
    return 0;
}

