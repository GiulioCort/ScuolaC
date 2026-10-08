#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int scelta = 0;
    int punti, numero, colore;                            //Colori -> 0 = nero  1 = rosso   2 = verde(0)
    int scommessa1, scommessa2;

    punti = 0;

    while(scelta != 6){
        printf("\n\n----------------------------------------\n");
        printf("ROULETTE\n");
        printf("1) L'utente punta sul rosso o sul nero\n");
        printf("2) L'utente punta sul numero secco\n");
        printf("3) L'utente punta su pari o dispari\n");
        printf("4) L'utente punta su due numeri\n");
        printf("5) Stampa dei punti ottenuti\n");
        printf("6) Uscita\n");
        printf("----------------------------------------\n");
        printf("Inserisci la scelta: ");
        scanf("%d", &scelta);

        srand(time(0));
        numero = rand() % 37;
        if (numero == 32 || numero == 19 || numero == 21 || numero == 25 || numero == 34 || numero == 27 || numero == 36 || numero == 30 || numero == 23 || numero == 5 || numero == 16 || numero == 1 || numero == 14 || numero == 9 || numero == 18 || numero == 7 || numero == 12 || numero == 3)
            colore = 1;
        else if (numero == 0)
            colore = 2;
        else
            colore = 0;

        switch(scelta){
            case 1:
                printf("\n0) Nero\n1) Rosso\nInserisci: ");
                scanf("%d", &scommessa1);
                printf("\nNumero uscito: %d", numero);
                if (colore == 0)
                    printf("\nColore: Nero");
                else if (colore == 1)
                    printf("\nColore: Rosso");

                if (scommessa1 == colore){
                    punti += 1;
                    printf("\nVinci");
                }
                else if (scommessa1 != 0 && scommessa1 != 1)
                    printf("\nColore non valido\n");
                else
                    printf("\nVince il banco");
                break;
            case 2:
                printf("\nInserisci il numero:  ");
                scanf("%d", &scommessa1);
                printf("\nNumero uscito: %d", numero);
                if (scommessa1 == numero){
                    punti += 35;
                    printf("\nVinci");
                }
                else if(scommessa1 < 0 || scommessa1 > 36)
                    printf("\nNumero non valido\n");
                else
                    printf("\nVince il banco");
                break;
            case 3:
                printf("\n0) Pari\n1) Dispari\nInserisci: ");
                scanf("%d", &scommessa1);
                printf("\nNumero uscito: %d", numero);
                if (scommessa1 == numero % 2){
                    punti += 1;
                    printf("\nVinci");
                }
                else if (scommessa1 != 0 && scommessa1 != 1)
                    printf("\nValore non valido non valido\n");
                else
                    printf("\nVince il banco");
                break;
            case 4:
                printf("\nInserisci il primo numero: ");
                scanf("%d", &scommessa1);
                printf("\nInserisci il secondo numero: ");
                scanf("%d", &scommessa2);
                printf("\nNumero uscito: %d", numero);
                if (scommessa1 != scommessa2){
                    if (scommessa1 < 0 || scommessa1 > 36 || scommessa2 < 0 || scommessa2 > 36)
                        printf("\nNumeri non validi");
                    else if (scommessa1 == numero || scommessa2 == numero){
                        punti += 17;
                        printf("\nVinci");
                    }
                    else
                    printf("\nVince il banco");
                }
                break;
            case 5:
                printf("\nHai ottenuto %d punti", punti);
                break;
            case 6:
                printf("\nUscita dal programma...");
                break;
            default:
                printf("\nComando errato.");
        }
    }
    return 0;
}