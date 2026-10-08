#include <stdio.h>
#include <string.h>

#define LEN 100

void caricamentoAllievi(char elenco[LEN][LEN], int eta[LEN]) {
    char nome[LEN];
    char cognome[LEN];

    int primoVuoto = 0;                                             // Capire qual'è il primo spazio vuoto del vettore
    while (primoVuoto < LEN && elenco[primoVuoto][0] != 0) {
        primoVuoto++;
    }

    printf("Inserisci nome: ");
    scanf("%s", &nome);
    printf("Inserisci cognome: ");
    scanf("%s", &cognome);
    printf("Inserisci l'eta': ");
    scanf("%d", &eta[primoVuoto]);

    nome[strlen(nome)] = ' ';
    strcat(elenco[primoVuoto], nome);
    strcat(elenco[primoVuoto], cognome);

}

void stampaMinorenni(char elenco[LEN][LEN], int eta[LEN]) {
    printf("\nETA'\tNOME COGNOME");
    for (int i = 0; i < LEN && elenco[i][0] != 0; i++) {
        if ((eta[i] < 18 && eta[i] >= 0)) {
            printf("\n%d", eta[i]);
            printf("\t%s", elenco[i]);
        }
    }
}

int menu(char elenco[LEN][LEN], int eta[LEN]){
    int scelta;
    int ritorno = 0;

    printf("\n\n---------------------------------------------------------------");
    printf("\n1. Caricare gli allievi\n2. Stampa i nomi degli allievi minorenni\n3. Esci dal programma");
    printf("\n---------------------------------------------------------------\n");

    printf("\nInserisci la tua scelta: ");
    scanf("%d", &scelta);

    switch (scelta){
    case 1:
        caricamentoAllievi(elenco, eta);
        break;
    case 2:
        stampaMinorenni(elenco, eta);
        break;
    case 3:
        printf("\nUscita dal programma");
        ritorno = 1;
        break;
    default:
        break;
    }

    return ritorno;
}

int main() {
    char elenco[LEN][LEN];
    int eta[LEN];

    for (int i = 0; i < LEN; i++)
        strcpy(elenco[i], "\0");

    int ritorno = 0;
    while (ritorno != 1)
        ritorno = menu(elenco, eta);
    
    return 0;
}