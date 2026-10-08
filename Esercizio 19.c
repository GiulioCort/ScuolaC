#include <stdio.h>

int main() {
    int num, n;
    int s_pari = 0;
    int s_dispari = 0;
    int i = 1;

    printf("Inserisci la quantita' di numeri che vuoi inserire: ");
    scanf("%d", &n);

    while (i <= n) {
        printf("Inserisci un numero: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            s_pari += num;
        else
            s_dispari += num;
        i += 1;
    }
    printf("\nSomma numeri pari: %d", s_pari);
    printf("\nSomma numeri dispari: %d", s_dispari);

    if (s_pari > s_dispari)
        printf("\n%d e' la somma maggiore", s_pari);
    else
        printf("\n%d e' la somma maggiore", s_dispari);

    return 0;
}