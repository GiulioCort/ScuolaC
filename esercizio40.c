#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

float array[MAX];
int len;

int lunghezzaArray() {
    printf("\nInserisci la lunghezza del vettore (massimo 1000): ");
    scanf("%d", &len);
    return len;
}

void caricamentoManuale() {
    len = lunghezzaArray();
    for (int i = 0; i < len; i++) {
        printf("Inserisci un numero reale: ");
        scanf("%f", &array[i]);
    }
}

void caricamentoRandom() {
    len = lunghezzaArray();
    
    float parteIntera;
    float parteDecimale;
    for (int i = 0; i < len; i++) {
        parteIntera = (rand() % 1000) + 1;
        if (parteIntera != 1000) {
            parteDecimale = (rand() % 101) / 100.0;
            parteIntera += parteDecimale;
        }
        array[i] = parteIntera;
    }
}

void stampaArray() {
    for (int i = 0; i < len; i++)
        printf("%.2f ", array[i]);
}

int numeroPrimo(int num) {
    int rit = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            rit = 0;
    }
    return rit;
}

void stampareNumeriPrimi() {
    int num;
    for (int i = 0; i < len; i++) {
        num = array[i];
        if (numeroPrimo(num) == 1) 
            printf("%.2f ", array[i]);
    }
}

int menu(){
    int scelta;
    int ritorno = 0;

    printf("\n\n---------------------------------------------------------------");
    printf("\n1. Caricare l'array manualmente\n2. Caricare l'array con numeri random\n3. Stampa l'array\n4. Stampare i numeri la cui parte intera risulti essere un numero primo\n5. Esci dal programma");
    printf("\n---------------------------------------------------------------\n");

    printf("\nInserisci la tua scelta: ");
    scanf("%d", &scelta);
    printf("\n");

    switch (scelta){
    case 1:
        caricamentoManuale();
        break;
    case 2:
        caricamentoRandom();
        break;
    case 3:
        stampaArray();
        break;
    case 4:
        stampareNumeriPrimi();
        break;
    case 5:
        printf("\nUscita dal programma");
        ritorno = 1;
        break;
    default:
        break;
    }

    return ritorno;
}

int main() {
    srand(time(0));
    int ritorno = 0;
    while (ritorno != 1)
        ritorno = menu();
    
    return 0;
}