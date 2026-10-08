#include <stdio.h>
#include <string.h>

#define LEN 20

int main() {
    char stringa[LEN];
    int num;
    
    printf("Inserisci una stringa: ");
    scanf("%s", &stringa);
    
    printf("Inserisci un numero: ");
    scanf("%d", &num);

    int len2 = LEN * num;

    char stringa2[len2];
    
    for (int i = 1; i <= num; i++) {
        strcat(stringa2, stringa);
    }

    

    printf("%s\n", stringa2);

    return 0;
}
