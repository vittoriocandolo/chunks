#include <stdio.h>

#define SIZE 10
int result[2] = {-1, -1};
void naiveContainsSum(int k, int *arr){
    for(int i = 0; i < SIZE; i++){
        for(int j = 1; j < SIZE; j++){
            if(k == arr[i] + arr[j]){
                result[0] = arr[i];
                result[1] = arr[j];
                j = SIZE;
                i = SIZE;
            }
        }
    }
}

int main(){
    int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    naiveContainsSum(10, array);
    printf("%d, %d", result[0], result[1]);
}

