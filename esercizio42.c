#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lato;

void caricaMatrice(float matrice[lato][lato]) {
    float parteIntera;
    float parteDecimale;
    for (int r = 0; r < lato; r++)
        for (int c = 0; c < lato; c++) {
            parteIntera = rand() % 11;
            parteDecimale = (rand() % 100) / 100.0;
            parteIntera += parteDecimale;
            matrice[r][c] = parteIntera;
        }
}

void stampaMatrice(float matrice[lato][lato]) {
    for (int r = 0; r < lato; r++){
        for (int c = 0; c < lato; c++)
            printf("%5.2f\t", matrice[r][c]);
        printf("\n");
    }
}

float sommaDiagonalePrincipale(float matrice[lato][lato]) {
    float somma = 0.0;

    for (int i = 0; i < lato; i++)
        somma += matrice[i][i];

    return somma;
}

float sommaDiagonaleSecondaria(float matrice[lato][lato]) {
    float somma = 0.0;

    int r = 0;
    int c = lato - 1;
    while (c >= 0) {
        somma += matrice[r][c];
        r++;
        c--;
    }

    return somma;
}

int main() {
    srand(time(0));
    printf("Inserisci il lato della matrice: ");
    scanf("%d", &lato);

    float matrice[lato][lato];

    caricaMatrice(matrice);
    stampaMatrice(matrice);

    float sommaPrincipale = sommaDiagonalePrincipale(matrice);
    printf("Somma diagonale principale: %5.2f\n", sommaPrincipale);
    float sommaSecondaria = sommaDiagonaleSecondaria(matrice);
    printf("Somma diagonale secondaria: %5.2f\n", sommaSecondaria);
    
    return 0;
}