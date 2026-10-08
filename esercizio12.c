#include <stdio.h>

int area(int lato) {
    return lato * lato;
}

int perimetro(int lato) {
    return lato * 4;
}

int main() {
    int lato, p, a;

    for (int i = 0; i < 3; i++) {
        printf("Inserisci il lato: ");
        scanf("%d", &lato);

        p = perimetro(lato);
        a = area(lato);

        printf("Perimetro --> %d\n", p);
        printf("Area --> %d\n\n", a);
    }
    
    return 0;
}