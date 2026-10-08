#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 10

void selectionSort(int array[]) {
    int parteOrdinata = -1;
    int temp;
    int min;

    while (N - parteOrdinata - 1 != 1) {
        min = parteOrdinata + 1;
        for (int i = parteOrdinata + 1; i < N; i++) {
            if (array[i] < array[min])
                min = i;
        }
        parteOrdinata++;
        temp = array[parteOrdinata];
        array[parteOrdinata] = array[min];
        array[min] = temp;
    }
    
}

void bubbleSort(int array[]) {
    int flag = 1;
    int parteOrdinata = N;
    int temp;

    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < parteOrdinata - 1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
                flag = 1;
            }
        }
        parteOrdinata--;
    }
}

int binarySearch(int array[], int valoreCercato) {
    int inizio = 0;
    int fine = N - 1;
    int mid;

    while (inizio <= fine) {
        mid = (inizio + fine) / 2;
        
        if (valoreCercato == array[mid])
            inizio = fine + 1;              // Per fermare il ciclo
        else if (valoreCercato < array[mid])
            fine = mid - 1;
        else
            inizio = mid + 1;

    }

    if (array[mid] != valoreCercato)
       mid = -1;

    return mid;
}

void creaArray(int array[N]) {
    for (int i = 0; i < N; i++)
        array[i] = rand() % (MAX + 1);
}

void stampaArray(int array[N]){
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
}

int main() {
    srand(time(0));
    int array[N];
    int valoreCercato;
    
    creaArray(array);
    printf("Array: ");
    stampaArray(array);
    selectionSort(array);
    printf("\nDopo ordinamento per selezione: ");
    stampaArray(array);
    
    creaArray(array);
    printf("\n\nArray: ");
    stampaArray(array);
    bubbleSort(array);\
    printf("\nDopo bubble sort: ");
    stampaArray(array);

    printf("\n\nInserisci il valore da cercare: ");
    scanf("%d", &valoreCercato);
    int posizione = binarySearch(array, valoreCercato);
    if (posizione == -1)
    printf("Il valore cercato non e' presente nell'array");
    else
    printf("%d e' alla posizione %d", valoreCercato, posizione);
    
    printf("\n\n");
    return 0;
}