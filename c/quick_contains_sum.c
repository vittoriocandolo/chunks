#include <stdio.h>

#define SIZE 10

int result[2] = {-1, -1};

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

int cmpFun(const void *a,const void *b){
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

void ContainsSum(int k, int *arr){
    qsort(arr, SIZE, sizeof(int), cmpFun);
    for(int i = 0; i < SIZE; i++){
        for(int j = SIZE - 1; j > 0; j--){
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
    ContainsSum(10, array);
    printf("%d, %d", result[0], result[1]);
}

