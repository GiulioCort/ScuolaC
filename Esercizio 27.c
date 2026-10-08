#include <stdio.h>
#include <string.h>

int ric(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		return 1;
	else if (x == ' ')
		return 2;
	else
		return 0;
}

int main() {
	char x[20];
    int ris;
    
	printf("Inserisci una stringa: ");
	fgets(x, 20, stdin);

    for (int i = 0; i < strlen(x) - 1; i++) {
	    ris = ric(x[i]);
        printf("%d", ris);
    }
    
    printf("\n");

	return 0;
}