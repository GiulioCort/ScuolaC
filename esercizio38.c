#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 6

int combinazione[LEN];

/*
void soluzioni() {
    printf("SOLUZIONE: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", combinazione[i]);
}
*/

int controllo(int inputGiocatore[LEN]) {
    int uscita = 0;
    int posCorretta = 0;
    int posErrata = 0;
    int check;

    for (int i = 0; i < 6; i++) {
        check = 0;
        if (inputGiocatore[i] == combinazione[i]) {
            posCorretta++;
        }
        else {
            for (int j = 0; j < 6; j++) {
                if (inputGiocatore[i] == combinazione[j] && i != j)
                    check = 1;
            }
            if (check == 1)
                posErrata++;
        }
    }
    if (posCorretta == 6)
        uscita = 1;
    else {
        printf("\n%d sono nella posizione corretta", posCorretta);
        printf("\n%d sono giusti ma nella posizione sbagliata\n", posErrata);
    }

    return uscita;
}

void inserimento(int inputGiocatore[LEN]) {
    printf("Inserisci sei numeri (0 - 9) separati da uno spazio: ");

    for (int i = 0; i < 6; i++)
        scanf("%d", &inputGiocatore[i]);
}

int gioco() {
    int tentativi = 1;
    int inputGiocatore[LEN];
    int uscita;
    
    //int scelta;

    do {
        //scanf("%d", &scelta);
        //if (scelta != 0)
        inserimento(inputGiocatore);
        //else
        //soluzioni();
        uscita = controllo(inputGiocatore);

        if (uscita == 0)
            tentativi++;
    } while (uscita != 1);

    return tentativi;
}

void generaCombinazione() {
    srand(time(0));

    for (int i = 0; i < 6; i++) {
        combinazione[i] = rand() % 10;
    }
}

int main() {
    generaCombinazione();

    int tentativi = gioco();
    printf("\nHai risolto il gioco in %d tentativi\n", tentativi);
    
    return 0;
}