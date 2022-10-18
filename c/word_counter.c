#include <stdio.h>

int main() {
  int n = 0, wordStart = 0;
  for(int c = getchar(); c != EOF; c = getchar()){
    if(c ==' ' || c == '\t' || c == '\n'){
      if(wordStart){
        n++;
        wordStart=0;
      }
    }else{
      wordStart=1;
    }
  }
  if(wordStart){
    n++;
  }
  printf("Numero di parole: %d\n",n);
  return 0;
}

