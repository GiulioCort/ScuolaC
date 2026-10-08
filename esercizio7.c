#include <stdio.h>

int main(){
    int t1, t2, t3, limite;
    float media;
    printf("Inserisci il limite di accensione: ");
    scanf("%d", &limite);
    printf("Inserisci le tre temperature:\n");
    scanf("%d", &t1);
    scanf("%d", &t2);
    scanf("%d", &t3);
    media = (t1 + t2 + t3)/ 3;
    if (media < limite)
        printf("Il sistema di riscaldamento si accende.");
    else
        printf("Il sistema di riscaldamento non si accende.");
}