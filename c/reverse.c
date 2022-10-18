#include <stdio.h>

#define SIZE 11

void swap(int *, int *);

void reverse(int *, int);

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void reverse(int *begin, int size){
  for(int i = 0; i < size / 2; ++i){
    swap(begin + i, begin + size - i - 1);
  }
}

int main(){
  int array[SIZE] = { };
  int read = 0;
  int n = 0;
  while(read < SIZE && scanf("%d", &n) == 1){
    array[read] = n;
    read++;
  }
  reverse(array, read);
  for(int i = 0; i < read; i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}

