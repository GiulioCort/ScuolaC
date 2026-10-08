#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int scelta = 0;
    int facce, puntipc, puntiplayer, lanci, player, pc;
    
    while (scelta != 4){
        puntipc = 0;
        puntiplayer = 0;
        // Stampa del menu
        printf("\n----------------------------------------\n");
        printf("LANCIO DEI DADI\n");
        printf("Scegli il numero di facce\n");
        printf("1) 6 facce\n");
        printf("2) 4 facce\n");
        printf("3) 8 facce\n");
        printf("4) Uscita\n");
        printf("----------------------------------------\n");
        printf("Inserisci la scelta: ");
        scanf("%d", &scelta);
        
        switch (scelta){
            case 1:
            facce = 6;
            break;
        case 2:
            facce = 4;
            break;
        case 3:
            facce = 8;
            break;
        case 4:
            printf("Uscita dal programma...\n");
            break;
        default:
            printf("Comando errato.\n");
        }
        srand(time(0));
        int i = 1;
        if (scelta >= 1 && scelta <= 3){
            // Numero di lanci
            printf("Quanti lanci? ");
            scanf("%d", &lanci);
            // Estrazioni
            while (i <= lanci){
                player = rand() % (facce - 1 + 1) + 1;
                printf("%d. Giocatore: %d\n", i, player);
                pc = rand() % (facce - 1 + 1) + 1;
                printf("%d. PC: %d\n", i,  pc);
                if (player > pc)
                    puntiplayer++;
                else if (pc > player)
                    puntipc++;
                i++;
            }
            // Output finale
            if (puntiplayer > puntipc)
                printf("Vince il giocatore con %d punti\n", puntiplayer);
            else if (puntipc > puntiplayer)
                printf("Vince il PC con %d punti\n", puntipc);
            else
                printf("Parita' con %d punti\n", puntipc);
        }
    }
    return 0;
}