#include <stdio.h>
#include <string.h>

#define LEN 20

char* concatenazione(char str1[LEN], char str2[LEN]) {
    static char str3[LEN];
    strcpy(str3, str1);
    strcat(str3, str2);
    return str3;
}

int lunghezza(char str1[LEN], char str2[LEN]){
    int lun1, lun2, lun3, rit;
    lun1 = strlen(str1);
    lun2 = strlen(str2);

    if (lun1 > lun2)
        rit = 1;
    else if (lun2 > lun3)
        rit = 2;
    else
        rit = 3;
    
    return rit;
}

int contenuto(char str1[LEN], char str2[LEN]){
    int stato = 0;
    int c = 0;
    
    for (int i = 0; i < strlen(str2) && str1[c] != '\0'; i++) {
        if (str2[i] == str1[c]) {
            stato = 1;
            c++;
        }
        else
            stato = 0;
    }

    return stato;
}

char* novocali(char str1[LEN]) {
    static char str4[LEN];
    int c = 0;

    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != 'a' && str1[i] != 'e' && str1[i] != 'i' && str1[i] != 'o' && str1[i] != 'u') {
            str4[c] = str1[i];
            c++;
        }
    }

    return str4;
}

int main() {
    char str1[LEN];
    char str2[LEN];
    char *str3;
    char *str4;

    printf("Inserisci la prima stringa: ");
    scanf("%s", &str1);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", &str2);

    str3 = concatenazione(str1, str2);
    printf("\nLe due stringhe concatenate: %s", str3);

    int x = lunghezza(str1, str2);
    if (x == 1)
        printf("\nLa stringa più lunga e': %s", str1);
    else if (x == 2)
        printf("\nLa stringa più lunga e': %s", str2);
    else
        printf("\nLe due stringhe sono uguali");

    int check = contenuto(str1, str2);
    if (check == 1)
        printf("\nLa prima stringa e' contenuta nella seconda");
    else
        printf("\nLa prima stringa non e' contenuta nella seconda");

    str4 = novocali(str1);
    printf("\nLa prima stringa senza vocali: %s", str4);
    

    printf("\n\n");
    return 0;
}