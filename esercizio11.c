#include <stdio.h>

int massimo(int a, int b) {
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

int inserimento() {
    int a, b;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("Inserisci un numero: ");
    scanf("%d", &b);

    int max = massimo(a, b);

    return max;
}

int main() {
    int a, b, N, max;

    printf("Inserisci N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        max = inserimento();
        printf("%d\n", max);
    }
    
    return 0;
}