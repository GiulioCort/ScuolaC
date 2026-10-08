#include <stdio.h>

int mcd(int a, int b) {
    int min, i;

    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;

    if (a > b)
        min = b;
    else
        min = a;

    i = min;

    while (a % i != 0 || b % i != 0)
        i--;

    return i;
}

int main() {
    int a, b, MCD, N, i;

    printf("Inserisci N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        MCD = mcd(a, b);

        printf("Il Massimo Comune Divisore è: \033[32m%d\n\n\033[37m", MCD);
    }
    
    return 0;
}