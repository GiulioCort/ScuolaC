#include <stdio.h>

float percentuale(int quantita, float totale) {
    float x = (quantita * 100.0) / totale;
    return x;
}

int main() {
    int nSi, nNO;

    printf("Inserisci il numero di persone che votano si': ");
    scanf("%d", &nSi);
    printf("Inserisci il numero di persone che votano no: ");
    scanf("%d", &nNO);

    float nTot = nSi + nNO;

    float pSi = percentuale(nSi, nTot);
    float pNo = percentuale(nNO, nTot);

    printf("Si' --> %.1f%\n", pSi);
    printf("No --> %.1f%\n", pNo);

    printf("\n\n");
    return 0;
}