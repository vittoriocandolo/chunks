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

struct pair sumBetween(int *array, int k, int length){
    struct pair temp;
    temp.first = -1;
    temp.second = -1;
    int c = 0;
    int i = 0;
    int j = 1;
    int sum = array[i];
    while(j < length - 1){
        if(sum == k){
            temp.first = c;
            temp.second = j;
        }else if(sum < k){
            j++;
        }else if(sum > k){
            c++;
            i = c;
            j = i + 1;
            sum = array[i];
        }
        i++;
        sum += array[i];
        }
    return temp;
}

int main(){
    int inputArray[SIZE];
    int size = scanArray(inputArray);
    int key;
    scanf("%d", &key);
    struct pair out = sumBetween(inputArray, key, size);
    printf("%d", out.first);
    printf(" %d", out.second);
    return 0;
}

