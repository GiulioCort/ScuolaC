#include <stdio.h>

int main(){
    int giorni, giornimagg, giornimin, temp;
    int i = 1;
    float mediamagg = 0;
    float mediamin = 0;
    giornimagg = giornimin = 0;
    printf("Inserisci il numero di giorni: ");
    scanf("%d", &giorni);
    while (i <= giorni){
        printf("Inserisci la temperatura: ");
        scanf("%d", &temp);
        if (temp >= 0){
            mediamagg += temp;
            giornimagg++;
        }
        else{
            mediamin += temp;
            giornimin++;
        }
        i++;
    }
    if (giornimagg == 0)            //Controlli per evitare che il programma esegua una divisione per 0
        mediamagg = 0;
    else
        mediamagg /= giornimagg;
    
    if (giornimin == 0)
        mediamin = 0;
    else
        mediamin /= giornimin;

    printf("La media delle temperature sotto lo zero e' %.2f\n", mediamin);
    printf("La media delle temperature sopra lo zero e' %.2f\n", mediamagg);
    
    return 0;
}