#include <stdio.h>

int divisibile(int endo, int ore) {
    int rit;
    if (ore % endo == 0)
        rit = 1;
    else
        rit = 0;

    return rit;
}

int perfetto(int x) {
    int rit, c;
    int somma = 0;

    for (int i = x - 1; i > 0; i--) {
        c = divisibile(i, x);
        if (c == 1)
            somma += i;
    }

    if (somma == x)
        rit = 1;
    else    
        rit = 0;

    return rit;
}

int main() {
    int num, rit;

    printf("Inserisci un numero: ");
    scanf("%d", &num);

    rit = perfetto(num);

    if (rit == 1)
        printf("Il numero e' perfetto\n");
    else
        printf("Il numero non e' perfetto\n");

    return 0;
}