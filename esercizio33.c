#include <stdio.h>
#include <string.h>

#define LEN 100

int contaVocali(char str[]) {
    int conta = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            conta++;
    }
    return conta;
}

int contaParole(char str[]) {
    int conta = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ')
            if (str[i + 1] != '\0')
                conta++;
    }
    return conta;
}

int contaDoppie(char str[]) {
    int conta = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == str[i + 1])
            conta++;
    }
    return conta;
}

int main() {
    char str[LEN];

    printf("Inserisci una stringa: ");
    fgets(str, LEN, stdin);

    printf("\n%d", contaVocali(str));
    printf("\n%d", contaParole(str));
    printf("\n%d", contaDoppie(str));

    return 0;
}