#include <stdio.h>

int main(){
    int anno;
    printf("Scrivere un anno per sapere se e' bisestile: ");
    scanf("%d", &anno);
    if (anno % 100 == 0){
        if (anno % 400 == 0)
            printf("%d e' un anno bisestile.", anno);
        else
            printf("%d non e' un anno bisestile.", anno);
    }
    else {
        if (anno % 4 == 0)
            printf("%d e' un anno bisestile.", anno);
        else
            printf("%d non e' un anno bisestile.", anno);
    }
    return 0;
}