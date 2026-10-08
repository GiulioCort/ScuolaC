#include <stdio.h>

int main() {
    float v, vmax, eccesso, p;
    printf("Inserire la tua velocita': ");
    scanf("%f", &v);
    printf("Inserire la velocita' massima: ");
    scanf("%f", &vmax);
    if (v < 100)
        v = v - 5;
    else {
        p = (v / 100)* 5;
        v = v - p;
    }
    if (v < vmax)
        printf("Velocita' nei limiti");
    else{
        eccesso = v - vmax;
        printf("Eri in eccesso di %f km/h\n", eccesso);
        if (eccesso <= 30)
            printf("Devi pagare una multa di 200 euro e ti verranno sottratti 2 punti della patente.");
        else {
            if (eccesso <= 50) 
                printf("Devi pagare una multa di 300 euro e ti verranno sottratti 5 punti della patente.");
            else
                printf("Devi pagare una multa di 1000 euro e ti verra' ritirata la patente.");
        }
    }
}