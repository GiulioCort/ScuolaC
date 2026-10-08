// Giulio Cortese - 3Bi - 18/05/2026 - Fila A

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define R 3
#define C 5

#define LEN 20
#define MAX 100
int len = 0;

typedef struct {
    char nome[LEN];
    char tipo[LEN];
    char colore[LEN];
    int eta;
} Animale;

void caricaMatrice(float matrice[R][C]) {
    int parteIntera;
    float parteDecimale;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            parteIntera = rand() % 101;
            parteDecimale = (rand() % 101) / 100.0;
            matrice[r][c] = parteIntera + parteDecimale;
         }
    }
}

void stampaMatrice(float matrice[R][C]) {
    printf("\n");
    for (int r = 0; r < R; r++) {
        printf("\t");
        for (int c = 0; c < C; c++) {
            printf("%5.2f\t", matrice[r][c]);
         }
        printf("\n");
    }
}

void calcoloSommaMatrice(float matrice[R][C]) {
    float somma;
    for (int c = 0; c < C; c++) {
        somma = 0.0;
        for (int r = 0; r < R; r++) {
            somma += matrice[r][c];
        }
        printf("\n\tSomma colonna %d = %.2f", c, somma);
    }
    printf("\n");
}

void caricaVettoreStruct(Animale listaAnimali[MAX]) {
    printf("\nQuanti animali vuoi inserire (MAX: %d) >> ", MAX);
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        printf("Inserisci [nome] [tipo] [colore] [eta] >> ");
        scanf("%s %s %s %d", &listaAnimali[i].nome, &listaAnimali[i].tipo, &listaAnimali[i].colore, &listaAnimali[i].eta);
    }
}

void stampaVettoreStruct(Animale listaAnimali[MAX]) {
    for (int i = 0; i < len; i++) {
        printf("\n------------------------------");
        printf("\nNome: %s", listaAnimali[i].nome);
        printf("\nTipo: %s", listaAnimali[i].tipo);
        printf("\nColore: %s", listaAnimali[i].colore);
        printf("\nEta': %d", listaAnimali[i].eta);
    }
    printf("\n------------------------------");
}

void ordinaVettoreStruct(Animale listaAnimali[MAX]) {
    int flag = 1;                               // All'inizio a 1 per entrare nel ciclo
    Animale temp;

    while (flag) {                              // Fino a quando avvengono degli scambi
        flag = 0;
        for (int i = 1; i < len; i++) {
            if (strcmp(listaAnimali[i - 1].tipo, listaAnimali[i].tipo) > 0 || (strcmp(listaAnimali[i - 1].tipo, listaAnimali[i].tipo) == 0 && strcmp(listaAnimali[i - 1].nome, listaAnimali[i].nome) > 0)) {
                temp = listaAnimali[i - 1];
                listaAnimali[i - 1] = listaAnimali[i];
                listaAnimali[i] = temp;
                flag = 1;                       // Flag a 1 perché è avvenuto uno scambio
            }
        }
    }
}

int menu(float matrice[R][C], Animale listaAnimali[MAX], int *checkMatrice, int *checkStruct) {
    int uscita = 1;
    int scelta;

    printf("\n=======================================================");
    printf("\n1) Caricare con numeri random una matrice di float");
    printf("\n2) Stampare la matrice");
    printf("\n3) Calcola la somma dei valori suddivisi per colonne");
    printf("\n\n4) Carica un vettore di struct");
    printf("\n5) Ordina il vettore di struct");
    printf("\n6) Stampa il vettore di struct");
    printf("\n7) Esci dal programma");
    printf("\n=======================================================\n");

    printf("\nInserisci la tua scelta >> ");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            caricaMatrice(matrice);
            printf("\033[32mMatrice caricata\033[0m\n");
            *checkMatrice = 1;
            break;
        case 2:
            if (*checkMatrice)
                stampaMatrice(matrice);
            else
                printf("\n\033[33mMATRICE NON INIZIALIZZATA\033[0m");
            break;
        case 3:
            if (*checkMatrice)
                calcoloSommaMatrice(matrice);
            else
                printf("\n\033[33mMATRICE NON INIZIALIZZATA\033[0m");
            break;
        case 4:
            caricaVettoreStruct(listaAnimali);
            *checkStruct = 1;
            break;
        case 5:
            if (*checkStruct) {
                ordinaVettoreStruct(listaAnimali);
                printf("\n\033[32mVettore ordinato\033[0m\n");
            }
            else
                printf("\n\033[33mVETTORE NON INIZIALIZZATO\033[0m");
            break;
        case 6:
            if (*checkStruct)
                stampaVettoreStruct(listaAnimali);
            else
                printf("\n\033[33mVETTORE NON INIZIALIZZATO\033[0m");
            printf("\n");
            break;
        case 7:
            printf("Uscita dal programma...");
            uscita = 0;
            break;
        default:
            printf("\033[31mCOMANDO ERRATO\033[0m\n");
    }
    return uscita;
}

int main() {
    srand(time(0));
    float matrice[R][C];
    Animale listaAnimali[MAX];

    int uscita;
    int checkMatrice = 0;       // checkMatrice = 1 se la matrice è gia stata caricata
    int checkStruct = 0;        // checkStruct = 1 solo se il vettore di struct è stato caricato
    do {
        uscita = menu(matrice, listaAnimali, &checkMatrice, &checkStruct);
    } while (uscita);

    return 0;
}