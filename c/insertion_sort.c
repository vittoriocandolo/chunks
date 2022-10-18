#include <stdio.h>

#define SIZE 12

int main(){
    int voti[SIZE] = {40, 30, 27, 20, 22, 28, 25, 25, 30, 27, 18, 26};
    int j, k;
    for(int i = 1; i < SIZE; i++){
        j = i - 1;
        k = voti[i];
        while(j >= 0 && voti[j] > k){
            voti[j + 1] = voti[j];
            j--;
        }
        voti[j + 1] = k;
    }
    for(int i = 0; i < SIZE; ++i) {
        printf("%d\n", voti[i]);
    }
    return 0;
}

