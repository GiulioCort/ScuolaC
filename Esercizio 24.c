#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int nr, r, c, colore, scelta;
char carattere;


void nrighe() {
    printf("Inserisci il numero di righe che vuoi visualizzare: ");
    scanf("%d", &nr);
}

void inscarattere(){
    printf("Inserisci il carattere che vuoi visualizzare: ");
    scanf(" %c", &carattere);
}

void stampa() {
    c = 1;
    for (r = 1; r <= nr; r++){
        for (int i = 0; i < nr - r; i++){
            printf(" ");
        }
    
        for (int i = 1; i <= c; i++){
            colore = rand() % 6 + 31;
            printf("\033[%dm%c", colore, carattere);
        }
        printf("\n");
        c += 2;
    }
    printf("\n");
}

int main() {
    srand(time(0));
    inscarattere();
    nrighe();
    stampa();
    

    return 0;
}