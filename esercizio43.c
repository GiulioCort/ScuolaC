#include <stdio.h>
#include <string.h>

#define N 20
#define MAX 3

int check = 0;

typedef struct {
    char cognome[N];
    char nome[N];
    int eta;
    char telefono[11];
} Persona;

void caricaRubrica(Persona rubrica[MAX]) {
    for (int i = 0; i < MAX; i++){
        printf("Inserisci nome cognome eta' e numero di telefono: ");
        scanf("%s %s %d %s", &rubrica[i].nome, &rubrica[i].cognome, &rubrica[i].eta, &rubrica[i].telefono);
    }
}

void stampaRubrica(Persona rubrica[MAX]) {
    for (int i = 0; i < MAX; i++){
        printf("\n %-20s  %-20s  %-3d  %-10s", rubrica[i].cognome, rubrica[i].nome, rubrica[i].eta, rubrica[i].telefono);
    }
}

void ordinaRubrica(Persona rubrica[MAX]) {
    int flag = 1;
    int parteOrdinata = MAX;
    Persona temp;

    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < parteOrdinata - 1; i++) {
            if (strcmp(rubrica[i].cognome, rubrica[i + 1].cognome) > 0 || (strcmp(rubrica[i].cognome, rubrica[i + 1].cognome) == 0 && strcmp(rubrica[i].nome, rubrica[i + 1].nome) > 0)) {
                temp = rubrica[i + 1];
                rubrica[i + 1] = rubrica[i];
                rubrica[i] = temp;
                flag = 1;
            }
        }
        parteOrdinata--;
    }

    printf("\n La rubrica e' stata ordinata");
}

void ricercasequenziale(Persona rubrica[MAX]) {
    char cognomeCercato[30];
    printf("\nInserisci il cognome da cercare: ");
    scanf("%s", &cognomeCercato);

    int cont = 0;
    for (int i = 0; i < MAX; i++) {
        if (strcmp(cognomeCercato, rubrica[i].cognome) == 0) {
            printf("\n %-20s  %-20s  %-3d  %-10s", rubrica[i].cognome, rubrica[i].nome, rubrica[i].eta, rubrica[i].telefono);
            cont++;
        }
    }
    if (cont == 0)
        printf("\nessuna persona con questo cognome");
}

void ricercaDicotomica(Persona rubrica[MAX]) {
    char cognomeCercato[N]; char nomeCercato[N];
    printf("\nInserisci nome e cognome da cercare: ");
    scanf("%s %s", &nomeCercato, &cognomeCercato);

    int inizio = 0;
    int fine = MAX - 1;
    int mid;

    while (inizio <= fine) {
        mid = (inizio + fine) / 2;

        if (strcmp(cognomeCercato, rubrica[mid].cognome) == 0 && strcmp(nomeCercato, rubrica[mid].nome) == 0)
            break;
        else if (strcmp(cognomeCercato, rubrica[mid].cognome) < 0 || (strcmp(cognomeCercato, rubrica[mid].cognome) == 0 && strcmp(nomeCercato, rubrica[mid].nome) < 0))
            fine = mid - 1;
        else
            inizio = mid + 1;

    }

    if (strcmp(cognomeCercato, rubrica[mid].cognome) == 0 && strcmp(nomeCercato, rubrica[mid].nome) == 0)
        printf("\n %-20s  %-20s  %-10s", rubrica[mid].cognome, rubrica[mid].nome, rubrica[mid].telefono);
    else
        printf("\nPersona non trovata");
}

void stampaMinorenni(Persona rubrica[MAX]) {
    printf("\nPersone minorenni");
    int cont = 0;
    for (int i = 0; i < MAX; i++){
        if (rubrica[i].eta < 18){
            printf("\n %-20s  %-20s  %-3d  %-10s", rubrica[i].cognome, rubrica[i].nome, rubrica[i].eta, rubrica[i].telefono);
            cont++;
        }
    }
    if (cont == 0)
        printf("\nNessun minorenne");
}

int menu(Persona rubrica[MAX]) {
    printf("\n\n---------------------------------------------------------------");
    printf("\n1. Carica la rubrica\n2. Stampa la rubrica\n3. Ordina la rubrica\n4. Ricerca per cognome\n5. Ricerca per nome e cognome\n6. Stampa le persone minorenni\n7. Esci dal programma");
    printf("\n---------------------------------------------------------------\n");

    int scelta;
    printf("\nInserisci la tua scelta: ");
    scanf("%d", &scelta);
    printf("\n");

    int ritorno = 0;

    switch (scelta){
    case 1:
        caricaRubrica(rubrica);
        check = 1;
        break;
    case 2:
        if (check == 1)
            stampaRubrica(rubrica);
        else
            printf("\nRubrica ancora non creata");
        break;
    case 3:
        ordinaRubrica(rubrica);
        break;
    case 4:
        ricercasequenziale(rubrica);
        break;
    case 5:
        ricercaDicotomica(rubrica);
        break;
    case 6:
        stampaMinorenni(rubrica);
        break;
    case 7:
        printf("\nUscita dal programma");
        ritorno = 1;
        break;
    default:
        break;
    }

    return ritorno;
}

int main() {
    Persona rubrica[MAX];

    int ret;
    do {
        ret = menu(rubrica);
    } while (ret != 1);

    return 0;
}
