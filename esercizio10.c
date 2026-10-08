#include <stdio.h>

int main() {
    float a, b, ris;
    char nome[10];
    char operatore;
    printf("Inserisci il tuo nome: ");
    scanf("%s", nome);
    printf("Inserisci il primo valore: ");
    scanf("%f", &a);
    printf("Inserisci il secondo valore: ");
    scanf("%f", &b);
    printf("Inserisci l'operatore: ");
    scanf(" %c", &operatore);
    printf("%s, ", nome);
    switch (operatore)
    {
    case '+':
        ris = a + b;
        printf("%.3f + %.3f = %.3f\n", a, b, ris);
        break;
    case '-':
    
        ris = a - b;
        printf("%.3f - %.3f = %.3f\n", a, b, ris);
        break;
    case '*':
        ris = a * b;
        printf("%.3f * %.3f = %.3f\n", a, b, ris);
        break;
    case '/':
        if (b == 0)
            printf("ERRORE\n");
        else {
            ris = a / b;
            printf("%.3f / %.3f = %.3f\n", a, b, ris);
        }
        break;
    default:
        printf("Operazione inesistente\n");
        break;
    }
}