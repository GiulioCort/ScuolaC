#include <stdio.h>
#include <string.h>

#define LEN 50

char upperCase(char carattere) {
    if (carattere >= 97 && carattere <= 122)
        carattere = carattere - 32;
    return carattere;
}

void aggiungiNome(char elenco[LEN][LEN]) {
    int primoVuoto = 0;
    while (primoVuoto < LEN && elenco[primoVuoto][0]) {
        primoVuoto++;
    }

    printf("\nInserisci nome e cognome: ");
    fgets(elenco[primoVuoto], LEN, stdin);

    elenco[primoVuoto][strlen(elenco[primoVuoto]) - 1] = 0;
}

void stampaElenco(char elenco[LEN][LEN]) {
    printf("\nElenco:");
    for (int i = 0; i < LEN && elenco[i][0] != 0; i++)
        printf("\n%d. %s", i + 1 , elenco[i]);
}

void correzioneNomi(char elenco[LEN][LEN]) {
    for (int j = 0; j < LEN && elenco[j][0] != 0; j++) {
        elenco[j][0] = upperCase(elenco[j][0]);

        int i;
        for (i = 0; i < LEN && elenco[j][i] != ' '; i++) {}
        elenco[j][i + 1] = upperCase(elenco[j][i + 1]);
    }
}

int menu(char elenco[LEN][LEN]){
    int scelta;
    int ritorno = 0;

    printf("\n\n---------------------------------------------------------------");
    printf("\n1. Aggiungere un allievo all'elenco\n2. Stampare l'elenco degli allievi\n3. Correggere i nomi degli allievi mettendo in maiuscolo l'iniziale del nome e del cognome\n4. Uscire dal programma");
    printf("\n---------------------------------------------------------------\n");

    printf("\nInserisci la tua scelta: ");
    scanf("%d", &scelta);

    switch (scelta){
    case 1:
        getchar();
        aggiungiNome(elenco);
        break;
    case 2:
        stampaElenco(elenco);
        break;
    case 3:
        correzioneNomi(elenco);
        break;
    case 4:
        printf("\nUscita dal programma\n");
        ritorno = 1;
        break;
    default:
        break;
    }

    return ritorno;
}

int main() {
    char elenco[LEN][LEN] = {"Giulio Cortese", "Edoardo Grazio", "Federico Ferrero", "Davide Fini", "Andrea Savarino"};

    int ritorno = 0;
    while (ritorno != 1)
        ritorno = menu(elenco);
    
    
    return 0;
}