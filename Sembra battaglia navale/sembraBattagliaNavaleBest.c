#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RIGHE 5
#define COLONNE 5
#define CASELLE 6

int griglia[RIGHE * COLONNE];

int uscita = 0;

void stampa() {
    int i = 0;
    char alfabeto[] = "ABCDEFGHILMNOPQRSTUVX";

    printf("  ");
    for (int lettera = 0; lettera < COLONNE; lettera++){
        printf("\033[33m%c\033[37m ", alfabeto[lettera]);
    }

    printf("\n");
    for (int r = 1; r <= RIGHE; r++){
        printf("\033[33m%d\033[37m ", r);
        for (int col = 1; col <= COLONNE; col++){
            if (uscita == 1 && (griglia[i] == 1 || griglia[i] == 3)) {
                printf("\033[32m");
            }
            else if (uscita == 0 && griglia[i] == 2) {
                printf("\033[31m");
            }
            else if (griglia[i] == 3) {
                printf("\033[32m");
            }
            printf("%d \033[37m", griglia[i]);
            i++;
        }
        printf("\n");
    }
}

void inserimento() {
    int rigut, colut;
    char colins;

    printf("\n\nInserisci la casella --> ");
    scanf(" %c %d", colins, rigut);

    char alfabeto[] = "ABCDEFGHILMNOPQRSTUVX";
    
}


void assegnazione(){
    int genera = 0;

    srand(time(0));

    for (int i = 0; i < RIGHE * COLONNE; i++)
        griglia[i] = 0;

    while (genera != CASELLE) {
        int i = rand() % (RIGHE * COLONNE);
        if (griglia[i] == 0){
            griglia[i] = 1;
            genera++;
        }
    }
    
}

int main() {
    assegnazione();

    while (uscita == 0){
        stampa();
        inserimento();
    }
    stampa();

    printf("\n\n\n\n");

    return 0;
}