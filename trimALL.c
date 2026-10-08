#include <stdio.h>
#include <string.h>

#define LEN 20

int main() {
    char stringa[LEN];
    char stringa2[LEN];
    int i2 = 0;

    printf("Inserisci una stringa: ");
    fgets(stringa, LEN, stdin);

    for (int i = 0; i < strlen(stringa); i++) {
        if (stringa[i] != ' ') {
            stringa2[i2] = stringa[i];
        }
        else {
            i2--;
        }
        i2++;
        
    }

    printf("%s", stringa2);

    return 0;
}