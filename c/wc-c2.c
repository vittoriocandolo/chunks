#include <stdio.h>

int main(){
    long nc = 0;
    for(; getchar() != EOF; ++nc);
    printf("%ld\n",nc);
    return 0;
}

