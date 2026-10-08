#include <stdio.h>
#include <string.h>

#define LEN 20

int main() {
    char stringa[LEN];
    int car;

    printf("Inserisci una stringa: ");
    fgets(stringa, LEN, stdin);

    for (int i = 0; i < LEN; i++) {
        car = stringa[i];
        if (car >= 97 && car <= 122)
            stringa[i] = stringa[i] - 32;
    }

    printf("%s", stringa);

    return 0;
}
