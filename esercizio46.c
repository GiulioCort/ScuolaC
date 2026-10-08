#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 50
#define N_PERSONE 20
#define N_DOMANDE 30

typedef struct {
   char cognome[LEN];
   char nome[LEN];
   char indirizzo[LEN];
   int nErrori;
} Persona;

void caricaCandidati(Persona candidati[N_PERSONE]) {
   strcpy(candidati[0].nome, "Mario");
   strcpy(candidati[0].cognome, "Rossi");
   strcpy(candidati[0].indirizzo, "Via Roma, 1");

   strcpy(candidati[1].nome, "Ada");
   strcpy(candidati[1].cognome, "Verdi");
   strcpy(candidati[1].indirizzo, "Via Po, 7");

   strcpy(candidati[2].nome, "Luca");
   strcpy(candidati[2].cognome, "Bianchi");
   strcpy(candidati[2].indirizzo, "Corso Francia, 12");

   strcpy(candidati[3].nome, "Giulia");
   strcpy(candidati[3].cognome, "Neri");
   strcpy(candidati[3].indirizzo, "Via Garibaldi, 22");

   strcpy(candidati[4].nome, "Marco");
   strcpy(candidati[4].cognome, "Ferrari");
   strcpy(candidati[4].indirizzo, "Piazza Castello, 5");

   strcpy(candidati[5].nome, "Elena");
   strcpy(candidati[5].cognome, "Gallo");
   strcpy(candidati[5].indirizzo, "Via Milano, 18");

   strcpy(candidati[6].nome, "Davide");
   strcpy(candidati[6].cognome, "Conti");
   strcpy(candidati[6].indirizzo, "Via Dante, 9");

   strcpy(candidati[7].nome, "Sara");
   strcpy(candidati[7].cognome, "Romano");
   strcpy(candidati[7].indirizzo, "Via Torino, 14");

   strcpy(candidati[8].nome, "Andrea");
   strcpy(candidati[8].cognome, "Greco");
   strcpy(candidati[8].indirizzo, "Corso Italia, 30");

   strcpy(candidati[9].nome, "Chiara");
   strcpy(candidati[9].cognome, "Ricci");
   strcpy(candidati[9].indirizzo, "Via Venezia, 3");

   strcpy(candidati[10].nome, "Francesco");
   strcpy(candidati[10].cognome, "Marino");
   strcpy(candidati[10].indirizzo, "Via Napoli, 11");

   strcpy(candidati[11].nome, "Valentina");
   strcpy(candidati[11].cognome, "Lombardi");
   strcpy(candidati[11].indirizzo, "Via Firenze, 6");

   strcpy(candidati[12].nome, "Simone");
   strcpy(candidati[12].cognome, "Barbieri");
   strcpy(candidati[12].indirizzo, "Corso Umberto, 27");

   strcpy(candidati[13].nome, "Martina");
   strcpy(candidati[13].cognome, "Fontana");
   strcpy(candidati[13].indirizzo, "Via Mazzini, 19");

   strcpy(candidati[14].nome, "Alessio");
   strcpy(candidati[14].cognome, "Serra");
   strcpy(candidati[14].indirizzo, "Via Cavour, 8");

   strcpy(candidati[15].nome, "Federica");
   strcpy(candidati[15].cognome, "Moretti");
   strcpy(candidati[15].indirizzo, "Piazza Vittorio, 2");

   strcpy(candidati[16].nome, "Matteo");
   strcpy(candidati[16].cognome, "De Luca");
   strcpy(candidati[16].indirizzo, "Via XX Settembre, 15");

   strcpy(candidati[17].nome, "Laura");
   strcpy(candidati[17].cognome, "Rinaldi");
   strcpy(candidati[17].indirizzo, "Via Manzoni, 21");

   strcpy(candidati[18].nome, "Stefano");
   strcpy(candidati[18].cognome, "Costa");
   strcpy(candidati[18].indirizzo, "Corso Torino, 4");

   strcpy(candidati[19].nome, "Irene");
   strcpy(candidati[19].cognome, "Villa");
   strcpy(candidati[19].indirizzo, "Via Leopardi, 13");
}

void stampaCandidati(Persona candidati[N_PERSONE], int risposte[N_PERSONE][N_DOMANDE]) {
   printf("\n%-50s  %-50s  %-50s  Numero errori", "COGNOME", "NOME", "INDIRIZZO");
   for (int i = 0; i < N_PERSONE; i++) {
      printf("\n%-50s  %-50s  %-50s  %d", candidati[i].cognome, candidati[i].nome, candidati[i].indirizzo, candidati[i].nErrori);
      /*printf("\nRisposte: ");
      for (int j = 0; j < N_DOMANDE; j++)
         printf("%d ", risposte[i][j]);
      printf("\n");
      */
   }
}

void caricaRisposte(int risposte[N_PERSONE][N_DOMANDE]) {
   for (int r = 0; r < N_PERSONE; r++)
      for (int c = 0; c < N_DOMANDE; c++)
         risposte[r][c] = (rand() % 3) + 1;
}

void calcolaErrori(Persona candidati[N_PERSONE], int risposte[N_PERSONE][N_DOMANDE], int quiz[N_DOMANDE]) {
   for (int persona = 0; persona < N_PERSONE; persona++) {
      candidati[persona].nErrori = 0;
      for (int i = 0; i < N_DOMANDE; i++) {
         if (risposte[persona][i] != quiz[i])
            candidati[persona].nErrori++;
      }
   }
}

void verifica(Persona candidati[N_PERSONE]) {
   int trovati = 0;
   char cognomeCercato[LEN];
   printf("\nInserisci il cognome di un candidato: ");
   scanf("%s", &cognomeCercato);

   for (int i = 0; i < N_PERSONE; i++) {
      if (candidati[i].cognome == cognomeCercato && candidati[i].nErrori <= 3){
         printf("\nIl candidato %s ha superato l'esame", cognomeCercato);
         trovati++;
      }
      else if (candidati[i].cognome == cognomeCercato && candidati[i].nErrori > 3) {
         printf("\nIl candidato %s non ha passato l'esame", cognomeCercato);
         trovati++;
      }
   }
   if (trovati == 0)
      printf("\nNon e' presente nessun candidato con il cognome richiesto");
}

int main() {
   srand(time(0));

   Persona candidati[N_PERSONE];
   caricaCandidati(candidati);

   int risposte[N_PERSONE][N_DOMANDE];
   caricaRisposte(risposte);

   int quiz[N_DOMANDE] = {1, 2, 3, 1, 2, 3, 2, 1, 3, 2, 1, 3, 1, 1, 2, 3, 2, 2, 3, 1, 2, 3, 1, 1, 2, 3, 2, 1, 3, 2};
   printf("Risposte corrette: ");
   for (int i = 0; i < N_DOMANDE; i++)
      printf("%d ", quiz[i]);
   printf("\n");

   calcolaErrori(candidati, risposte, quiz);

   stampaCandidati(candidati, risposte);



   printf("\n");
   return 0;
}
