#include <stdio.h>
#include <string.h>

#define LEN 20

int main() {
    char stringa[LEN];
    char stringa2[LEN];
    int num;
    
    printf("Inserisci una stringa: ");
    fgets(stringa, LEN, stdin);

    int c = strlen(stringa) - 1;
    for (int i = 0; i < strlen(stringa); i++) {
        stringa2[i] = stringa[c];
        c--;
    }

    printf("%s\n", stringa2);

    return 0;
}
