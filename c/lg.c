#include <stdio.h>
#include <math.h>

int lg (int);

int main(){
    printf(" %d", lg(1000000));
    return 0;
}
int lg(int n){
    int result = 0;
    for(int m = 0; pow(10, m) <= n; ++m) {
        result = m;
    }
    return result;
}

