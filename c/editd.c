#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a, b) ((a < b) ? a : b)

#define SIZE 64

int editd_rec(char* w1, char* w2, int l1, int l2, int** m) {
    if (l1 == 0) {
        return l2;
    }
    if (l2 == 0) {
        return l1;
    }
    if (m[l1][l2] != -1) {
        return m[l1][l2];
    }
    if (w1[l1 - 1] == w2[l2 - 1]) {
        return m[l1][l2] = editd_rec(w1, w2, l1 - 1, l2 - 1, m);
    } else {
        int ins, del, sub;
        ins = editd_rec(w1, w2, l1, l2 - 1, m);
        del = editd_rec(w1, w2, l1 - 1, l2, m);
        sub = editd_rec(w1, w2, l1 - 1, l2 - 1, m);
        return m[l1][l2] = 1 + min(ins, min(del, sub));
    }
}

int editd(char *w1, char *w2, int l1, int l2){
  int m[l1 + 1][l2 + 1];
  for(int i = 0; i <= l1; i++){
    m[i][0] = i;
  }
  for(int i = 0; i <= l2; i++){
    m[0][i] = i;
  }
  for(int i = 1; i <= l1; i++){
    int j;
    char c1 = w1[i - 1];
    for(j = 1; j <= l2; j++){
      char c2 = w2[j - 1];
      if(c1 == c2){
        m[i][j] = m[i - 1][j - 1];
      } else {
        int del = m[i - 1][j] + 1;
        int ins = m[i][j - 1] + 1;
        int sub = m[i - 1][j - 1] + 1;
        int min = del;
        if(ins < min){
          min = ins;
        }
        if(sub < min){
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
  /*
  int** m = malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        m[i] = malloc((len2 + 1) * sizeof(int));
    }
    memset(m[0], 0, (len1 + 1) * (len2 + 1) * sizeof(int));
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
        m[i][j] = -1;
        }
    }
  printf("%d\n", editd_rec(word1, word2, len1, len2, m));
  */
  printf("%d\n", editd(word1, word2, len1, len2));
  return 0;
}
