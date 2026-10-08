#include <stdio.h>

int main(){
    int x, y, z;
    printf("Inserisci tre numeri per sapere qual'e' il piu' grande.\n");
    printf(">>");
    scanf("%d", &x);
    printf(">>");
    scanf("%d", &y);
    printf(">>");
    scanf("%d", &z);
    if (x > y && x > z)
        printf("%d e' il numero piu' grande.", x);
    else {
        if (y > z && y > x)
            printf("%d e' il numero piu' grande.", y);
        else
            printf("%d e' il numero piu' grande.", z);
    }
    return 0;
}