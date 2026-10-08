#include <stdio.h>

int main(){
    int x, y;
    printf("Inserisci due numeri per sapere qual'e' il maggiore\n");
    printf(">>");
    scanf("%d", &x);
    printf(">>");
    scanf("%d", &y);
    if (x>y)
        printf("%d e' il più grande.", x);
    else
        printf("%d e' il più grande.", y);
    return 0;
}