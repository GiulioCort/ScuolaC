#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n, x;
    srand(time(0));
    x = rand();
    n = x % 101;
    while (n != 0){
        printf("%d\n", n);
        x = rand();
        n = x % 101;
    }
    printf("%d", n);
    return 0;
}