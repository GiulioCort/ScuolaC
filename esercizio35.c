#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void numPari(int V[]) {
    printf("\nNumeri pari --> ");
    for (int i = 0; i < N; i++) {
        if (V[i] % 2 == 0)
            printf("%d ", V[i]);
    }
}

void media(int V[]) {
    float somma = 0;
    for (int i = 0; i < N; i++)
    somma += V[i];
    float media = somma / N;
    printf("\nMedia = %.2f", media);
}

void numNegativi(int V[]) {
    printf("\nNumeri negativi --> ");
    for (int i = 0; i < N; i++) {
        if (V[i] < 0)
            printf("%d ", V[i]);
    }
}

int main() {
    int V[N];
    srand(time(0));

    for (int i = 0; i < N; i++) {           // Assegnazione dei valori dell'array
        V[i] = (rand() % 101) - 50;
        printf("%d ", V[i]);
    }

    numPari(V);
    media(V);
    numNegativi(V);
    
    printf("\n\n");
    return 0;
}