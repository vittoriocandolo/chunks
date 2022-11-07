#include <string.h>
#include <stdio.h>

#define SIZE 64

int editd(char *w1, char *w2, int l1, int l2){

  int m[l1 + 1][l2 + 1];
  int i;

  for (i = 0; i <= l1; i++){
    m[i][0] = i;
  }

  for (i = 0; i <= l2; i++){
    m[0][i] = i;
  }

  for (i = 1; i <= l1; i++){
      
    int j;
    char c1 = w1[i - 1];
    
    for (j = 1; j <= l2; j++){
        
      char c2 = w2[j - 1];
      
      if (c1 == c2){
        m[i][j] = m[i - 1][j - 1];
        
      } else {

        int del = m[i - 1][j] + 1;
        int ins = m[i][j - 1] + 1;
        int sub = m[i - 1][j - 1] + 1;
        int min = del;

        if (ins < min){
          min = ins;
        }

        if (sub < min){
          min = sub;
        }

        m[i][j] = min;
      }
    }
  }
  return m[l1][l2];
}

int main(){

  char word1[SIZE];
  fgets(word1, SIZE, stdin);
  char word2[SIZE];
  fgets(word2, SIZE, stdin);

  int len1 = strlen(word1);
  int len2 = strlen(word2);

  int d = editd(word1, word2, len1, len2);
  printf("%d\n", d);
  return 0;
}
