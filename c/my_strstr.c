#include <stdio.h>
#include <string.h>

char *my_strstr(char *str, char *pattern);
int main(){
  char prova[] = "como vamos a comer?";
  char *p = my_strstr(prova, "mo");
  while(p){
    printf("%s\n", p);
    p = my_strstr(p + 1, "mo");
  }
  return 0;
}
char *my_strstr(char *str, char *pattern){
  int patLen = strlen(pattern);
  char *p = strchr(str, pattern[0]);
  while(p){
    if(strncmp(p, pattern, patLen) == 0){
      return p;
    }
    p = strchr(p + 1, pattern[0]);
  }
  return NULL;
}

