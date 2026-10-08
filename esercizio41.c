#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 3

void caricaMatrice(float matrice[R][C]) {
    float parteIntera;
    float parteDecimale;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            parteIntera = rand() % 11;
            parteDecimale = (rand() % 100) / 100.0;
            parteIntera += parteDecimale;
            matrice[r][c] = parteIntera;
        }
}

void stampaMatrice(float matrice[R][C]) {
    for (int r = 0; r < R; r++) {
        printf("\033[33mRiga %d\t\033[0m", r + 1);
        for (int c = 0; c < C; c++)
            printf("%5.2f\t", matrice[r][c]);
        printf("\n");
    }
}

void stampaSommaRighe(float matrice[R][C]) {
    float somma;
    for (int r = 0; r < R; r++) {
        somma = 0;
        for (int c = 0; c < C; c++)
            somma += matrice[r][c];
        printf("\nSomma della riga %d = %.2f", r + 1, somma);
    }
}

int main() {
    srand(time(0));
    float matrice[R][C];

    caricaMatrice(matrice);
    stampaMatrice(matrice);
    stampaSommaRighe(matrice);

    return 0;
}
