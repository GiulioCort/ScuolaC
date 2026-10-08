#include <stdio.h>

int main() {
    int tabellina, num, i;
    for (tabellina = 1; tabellina <= 10; tabellina++){
        i = 1;
        switch (tabellina) {
        case 1:
            printf("\033[31m");
            break;
        case 2:
            printf("\033[32m");
            break;
        case 3:
            printf("\033[33m");
            break;
        case 4:
            printf("\033[34m");
            break;
        case 5:
            printf("\033[35m");
            break;
        case 6:
            printf("\033[36m");
            break;
        case 7:
            printf("\033[31m");
            break;
        case 8:
            printf("\033[32m");
            break;
        case 9:
            printf("\033[33m");
            break;
        case 10:
            printf("\033[34m");
            break;
        }
        printf("\nTabellina del %d\n", tabellina);
        for (i = 1; i <= 10; i ++){
            num = tabellina * i;
            printf("%d ", num);
        }
        printf(" ");
        
    }
    return 0;
}