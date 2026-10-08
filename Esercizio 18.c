#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int scelta = 0;
    int n, x, somma, i;
    float media;

    while(scelta != 4){
        printf("\n\n----------------------------------------\n");
        printf("MENU'\n");
        printf("1) Estrarre un numero random compreso tra -50 e +50\n");
        printf("2) Dato un numero N scelto dall'utente, stampare la somma di tutti i numeri compresi tra 1 ed N\n");
        printf("3) Dato un numero N scelto dall'utente, richiedere all'utente N valori e stamparne la media\n");
        printf("4) Uscita\n");
        printf("----------------------------------------\n");
        printf("Inserisci la scelta: ");
        scanf("%d", &scelta);

        srand(time(0));
        i = 1;
        somma = 0;
        media = 0;
        switch(scelta){
            case 1:
                n = rand() % 101 - 50;
                printf("\n%d", n);
                break;
            case 2:
                printf("\nInserisci N: ", n);
                scanf("%d", &n);
                while (i <= n){
                    somma += i;
                    i++;
                }
                printf("\nLa somma e': %d", somma);
                break;
            case 3:
                printf("\nInserisci N: ", n);
                scanf("%d", &n);
                while (i <= n){
                    printf("Inserisci un numero: ");
                    scanf("%d", &x);
                    media += x;
                    i++;
                }
                media = media / n;
                printf("\nLa media e': %.2f", media);
                break;
            case 4:
                printf("\nUscita dal programma...");
                break;
            default:
                printf("\nComando errato.");
        }
    }
    return 0;
}