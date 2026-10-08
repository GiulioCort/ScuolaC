#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    int nr, r, c, colore;
    char carattere;
    c = 1;
    srand(time(0));

    printf("Inserisci il carattere che vuoi visualizzare: ");
    scanf(" %c", &carattere);
    printf("Inserisci il numero di righe che vuoi visualizzare: ");
    scanf("%d", &nr);
    //system("cls");
    

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
    return 0;
}