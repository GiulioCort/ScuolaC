#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = GetConsoleMode(hOut, &dwMode);
    dwMode = dwMode | 0x0004;
    SetConsoleMode(hOut, dwMode);

    int n, div, i, x, nneg, npos;
    int scelta = 0;
    srand(time(0));

    while (scelta != 3){
        printf("\n\n\033[32m--------------------------------------------------");
        printf("\nMENU'");
        printf("\n1) Dato un numero N in input, stampare tutti i suoi divisori.");
        printf("\n2) Dato un numero N , produrre N numeri random compresi tra -40 e +50 , e contare quanti di questi sono negativi e quanti positivi.");
        printf("\n3) Uscita");
        printf("\n--------------------------------------------------\033[37m\n");

        printf("\nInserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                printf("\n\033[34mInserisci un numero: ");
                scanf("%d", &n);
                printf("\033[37mI divisori di \033[34m%d\033[37m sono: \033[33m", n);
                if (n < 0){
                    n = n * -1;
                }

                i = 1;
                while (i < n){
                    if (n % i == 0){
                        printf("%d, ", i);
                    }
                    i += 1;
                }
                printf("%d\033[37m", n);
                break;
            case 2:
                printf("\nInserisci un numero: ");
                scanf("%d", &n);
                i = 1;
                npos = 0;
                nneg = 0;
                while (i <= n){
                    x = rand() % 91 - 40;
                    printf("%d\n", x);
                    if (x < 0){
                        nneg += 1;
                    }
                    else {
                        npos += 1;
                    }
                    i += 1;
                }
                printf("\nI \033[35mpositivi\033[37m sono: \033[35m%d\033[37m", npos);
                printf("\nI \033[36mnegativi\033[37m sono: \033[36m%d\033[37m", nneg);
                break;
            case 3:
                printf("\n\033[31mUscita dal programma...\033[37m");
                break;
            default:
                printf("\n\033[31mComando errato\033[37m");

        }

    }

    return 0;
}