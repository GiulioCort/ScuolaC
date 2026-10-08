#include <stdio.h>

int main() {
    int n1, n2, n3, nmin, nmed, nmax;
    char ordine;
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &n3);
    printf("Vuoi visualizzare i numeri in ordine crescente [c] o decresciente [d]: ");
    scanf(" %c", &ordine);
    if (n1 < n2)
        if (n1 < n3)
            if (n3 < n2){
                nmin = n2;
                nmed = n3;
                nmax = n1;
            }
            else {
                nmin = n3;
                nmed = n2;
                nmax = n1;
            }
        else {
            nmin = n2;
            nmed = n1;
            nmax = n3;
        }
    else if (n1 < n3){
        nmin = n3;
        nmed = n1;
        nmax = n2;
    }
    else if (n3 < n2){
        nmin = n1;
        nmed = n2;
        nmax = n3;
    }
    else {
        nmin = n1;
        nmed = n3;
        nmax = n2;
    }
    
    if (ordine == 'd')
        printf("%d %d %d", nmin, nmed, nmax);
    else
        printf("%d %d %d", nmax, nmed, nmin);

    return 0;
}