#include <stdio.h>
#include <string.h>

#define LEN 128

int main() {
    char stringa1[LEN] = "";
    char stringaTrim[LEN] = "";
    char stringaReverse[LEN] = "";
    int i2 = 0;
    int check = 0;

    printf("Inserisci una stringa: ");
    fgets(stringa1, LEN, stdin);

    for (int i = 0; i <= strlen(stringa1); i++) {
        if (stringa1[i] != ' ' && stringa1[i] != '\n') {
            stringaTrim[i2] = stringa1[i];
        }
        else {
            i2--;
        }
        i2++;
    }

    int c = strlen(stringaTrim) - 1;
    for (int i = 0; i < strlen(stringaTrim); i++) {
        stringaReverse[i] = stringaTrim[c];
        c--;
    }

    check = strcmp(stringaTrim, stringaReverse);

    if (check == 0)
        printf("La stringa e' palindroma\n");
    else
        printf("La stringa non e' palindroma\n");

    printf("\n");
    
    return 0;
}