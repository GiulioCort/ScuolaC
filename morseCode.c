#include <stdio.h>
#include <string.h>

#define LEN 100

int main() {
    char stringa[LEN];

    printf("Inserisci una stringa: ");
    fgets(stringa, LEN, stdin);

    for (int c = 0; c < strlen(stringa); c++) {
        switch (stringa[c]) {
            case 'a':
                printf(".- ");
                break;
            case 'b':
                printf("-... ");
                break;
            case 'c':
                printf("-.-. ");
                break;
            case 'd':
                printf("-.. ");
                break;
            case 'e':
                printf(". ");
                break;
            case 'f':
                printf("..-. ");
                break;
            case 'g':
                printf("--. ");
                break;
            case 'h':
                printf(".... ");
                break;
            case 'i':
                printf(".. ");
                break;
            case 'j':
                printf(".--- ");
                break;
            case 'k':
                printf("-.- ");
                break;
            case 'l':
                printf(".-.. ");
                break;
            case 'm':
                printf("-- ");
                break;
            case 'n':
                printf("-. ");
                break;
            case 'o':
                printf("--- ");
                break;
            case 'p':
                printf(".--. ");
                break;
            case 'q':
                printf("--.- ");
                break;
            case 'r':
                printf(".-. ");
                break;
            case 's':
                printf("... ");
                break;
            case 't':
                printf("- ");
                break;
            case 'u':
                printf("..- ");
                break;
            case 'v':
                printf("...- ");
                break;
            case 'w':
                printf(".-- ");
                break;
            case 'x':
                printf("-..- ");
                break;
            case 'y':
                printf("-.-- ");
                break;
            case 'z':
                printf("--.. ");
                break;
    
            // Numeri
            case '0':
                printf("----- ");
                break;
            case '1':
                printf(".---- ");
                break;
            case '2':
                printf("..--- ");
                break;
            case '3':
                printf("...-- ");
                break;
            case '4':
                printf("....- ");
                break;
            case '5':
                printf("..... ");
                break;
            case '6':
                printf("-.... ");
                break;
            case '7':
                printf("--... ");
                break;
            case '8':
                printf("---.. ");
                break;
            case '9':
                printf("----. ");
                break;
    
            // Punteggiatura di base
            case '.':
                printf(".-.-.- ");
                break;
            case ',':
                printf("--..-- ");
                break;
            case '?':
                printf("..--.. ");
                break;
            case '!':
                printf("-.-.-- ");
                break;
            case ' ':
                printf(" ");
                break;  // Separatore tra parole
    
            // Carattere apostrofo singolo
            case '\'':
                printf(".----. ");
                break;

            default:
                // Ignora caratteri non supportati
        }  
    }
    printf("\n");

    return 0;
}