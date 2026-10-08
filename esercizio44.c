#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define C 6
#define R 10

void caricaMatrice(int matrice[R][C]) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            matrice[r][c] = rand() % 11;
}

void stampaMatrice(int matrice[R][C]) {
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
            printf("\t%d", matrice[r][c]);
        printf("\n");
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void controlloPrimo(int matrice[R][C]) {
    int c, r;
    for (c = 0; c < C && matrice[r][c - 1] != 0; c++) {
        for (r = 0; r < R && matrice[r][c] != 0; r++) {}
    }
    c--;

    printf("Il primo zero si trova in posizione %d %d\n", r, c);
}

void controlloUltimo(int matrice[R][C]) {
    int c, r;
    for (c = C - 1; c >= 0 && matrice[r][c + 1] != 0; c--) {
        for (r = R - 1; r >= 0 && matrice[r][c] != 0; r--) {}
    }
    c++;

    printf("L'ultimo zero si trova in posizione %d %d\n", r, c);
}

int main() {
    int matrice[R][C];
    srand(time(0));

    caricaMatrice(matrice);
    stampaMatrice(matrice);
    controlloPrimo(matrice);
    controlloUltimo(matrice);

    return 0;
}