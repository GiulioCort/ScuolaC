#include <stdio.h>

int main() {
    int factor, num, i;
    factor = 0;
    while (factor < 10){
        i = 1;
        factor = factor + 1;
        switch (factor) {
        case 1:
            printf("\033[31m"); //Red
            break;
        case 2:
            printf("\033[32m"); //Green
            break;
        case 3:
            printf("\033[33m"); //Yellow
            break;
        case 4:
            printf("\033[34m"); //Blue
            break;
        case 5:
            printf("\033[35m"); //Purple
            break;
        case 6:
            printf("\033[36m"); //Light blue
            break;
        case 7:
            printf("\033[31m"); //Red
            break;
        case 8:
            printf("\033[32m"); //Green
            break;
        case 9:
            printf("\033[33m"); //Yellow
            break;
        case 10:
            printf("\033[34m"); //Light blue
            break;
        }
        printf("\n%d's multiplication table\n", factor);
        while (i <= 10){
            num = factor * i;
            printf("%d ", num);
            i = i + 1;
        }
        printf(" ");
        
    }
    return 0;
}