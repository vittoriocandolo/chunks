#include <stdio.h>
#include <string.h>

char *my_strchr(char *str, char c);
char *my_strchr(char *str, char c){
  for(char *p = str; *p; ++p){
    if(*p == c){
      return p;
    }
  }
  return NULL;
}
int main(){
  char prova[] = "como vamos a comer?";
  char *p = my_strchr(prova, 'o');
  while(p){
    printf("%s\n", p);
    p = my_strchr(p + 1, 'o');
  }
  return 0;
}

