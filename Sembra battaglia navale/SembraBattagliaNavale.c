#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rig1, rig2, rig3, rig4, rigut, colut;
int tentativi = 16;
char coltem;

void stampa(int pos[], int col1, int col2, int col3, int col4, int uscita, int soluz);


void inserimento(int pos[], int col1, int col2, int col3, int col4) {
    int i, uscita = 0;
    int soluz = 0;

    printf("\n");
    tentativi--;
    if (tentativi == 0)
        uscita = 1;
    else {
        printf("\n\033[37mInserisci la casella:");
        scanf(" %c %d", &coltem, &rigut);                       // L'utente inserisce la colonna e la riga che vuole selezionare
    }

    if (rigut == 0) {
        uscita = 1;
        soluz = 1;
    }

        switch (coltem) {
        case 'A':
            colut = 1;
            break;
        case 'B':
            colut = 2;
            break;
        case 'C':
            colut = 3;
            break;
        case 'D':
            colut = 4;
            break;
        case 'E':
            colut = 5;
            break;
        case 'F':
            colut = 6;
            break;
        default:
            printf("Comando errato\n");
            tentativi++;
        }
    if (uscita != 1){
        i = 6 * (rigut-1) + (colut-1);                      // i è la posizione della casella inserita dall'utente all'interno de vettore pos
        if ((rigut == rig1 && colut == col1) || (rigut == rig2 && colut == col2) || (rigut == rig3 && colut == col3) || (rigut == rig4 && colut == col4)){
            pos[i] = 2;                                     // I valori all'interno di pos possono essere:
            tentativi += 4;                                 // 0 --> L'utente non ha mai scelto la casella corrisponente
    }                                                       // 1 --> L'utente ha inserito una casella sbagliata
        else {                                              // 2 --> L'utente ha inserito una casella corretta
            pos[i] = 1;
        }
    }

    stampa(pos, col1, col2, col3, col4, uscita, soluz);
}

void stampa(int pos[], int col1, int col2, int col3, int col4, int uscita, int soluz) {
    system("clear");
    printf("SEMBRA BATTAGLIA NAVALE");
    if (uscita == 1) {
        printf(" - SOLUZIONI");
    }
    

    printf("\n\n");
    int c = 0;
    int col;
    int cicli2 = 1;
    int i = 0;
    printf("\033[33m   A B C D E F\n");
    for (int r = 1; r <= 6; r++) {
        col = 1;
        printf("\033[33m %d\033[34m", r);
        while (c < 36) {
            if (uscita != 1){
                if (pos[c] == 1)
                    printf("\033[31m");
                else if (pos[c] == 2) {
                    printf("\033[32m");
                }
            }
            else {
                if ((r == rig1 && col == col1) || (r == rig2 && col == col2) || (r == rig3 && col == col3) || (r == rig4 && col == col4)){      //Soluzioni
                    printf("\033[32m");
                }
            }
            printf(" O\033[34m");
            c++;
            if (c == 6 || c == 12 || c == 18 || c == 24 || c == 30)
                break;
            col++;
            i += 2;
        }
        printf("\n");
    }

    if (uscita != 1) {
        printf("\n\n\033[0mTentativi rimanenti --> %d", tentativi-1);
    }
    else if (uscita == 1 && soluz != 1)
        printf("\n\n\033[0mTentativi esauriti");
    
    
    if (uscita != 1)
        inserimento(pos, col1, col2, col3, col4);

}

void assegnazione() {
    int col1, col2, col3, col4;
    
    srand(time(0));
   
    
    int pos[36];
    for (int e = 0; e < 36; e++) {                  //Ogni numero dentro a POS[] viene impostato a 0
        pos[e] = 0;
    }
    
    while (col1 == col2 || col2 == col3 || col3 == col4 || col4 == col1 || col1 == col3 || col2 == col4) {
        col1 = rand() % 6 + 1;
        col2 = rand() % 6 + 1;
        col3 = rand() % 6 + 1;
        col4 = rand() % 6 + 1;
    }
    
    rig1 = rig2 = rig3 = rig4 = 0;
    while (rig1 == rig2 || rig2 == rig3 || rig3 == rig4 || rig4 == rig1) {
        rig1 = rand() % 6 + 1;
        rig2 = rand() % 6 + 1;
        rig3 = rand() % 6 + 1;
        rig4 = rand() % 6 + 1;
    }
    
    //printf("%d %d\n%d %d\n%d %d\n%d %d\n\n", rig1, col1, rig2, col2, rig3, col3, rig4, col4);
    //char dummy[] = "ciao";
    //scanf("%s", &dummy);

    stampa(pos, col1, col2, col3, col4, 0, 0);
}

void uscita() {
    printf("\n\n\033[0mGRAZIE PER AVER GIOCATO\033[0m\n\n");
}

int main() {
    assegnazione();
    uscita();
    
    return 0;
}