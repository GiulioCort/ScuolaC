#include <stdio.h>
#include <stdint.h>

int main() {
    // 1. TODO ichiarazione variabili (8 bit)
    uint8_t a = 150;
    uint8_t b = 50;
    int8_t c = 100;
    int8_t d = 50;
    int8_t e = -80;
    int8_t f = -60;

    uint8_t risultato1;                         // unsigned
    int8_t risultato2, risultato3, risultato4;  // signed
    uint8_t risultato5;                         // unsigned


    printf("\n=== ANALISI INTERVALLO RAPPRESENTABILE ===\n\n");
    printf("Variabile a contiene: %u\n", a);
    printf("Variabile b contiene: %u\n", b);
    printf("Variabile c contiene: %d\n", c);
    printf("Variabile d contiene: %d\n", d);
    printf("Variabile e contiene: %d\n", e);
    printf("Variabile f contiene: %d\n", f);

    //3. TODO  assegna valori alle variabili a c ed e fuori intervallo e ristampa contenuto
    a = 256;
    c = 128;
    e = -300;
    printf("\nVariabile a contiene, giusto??: %u\n", a);
    printf("Variabile c contiene, giusto??: %d\n", c);
    printf("Variabile e contiene, giusto??: %d\n", e);

    //4. TODO  riporta a, c ed e a valori rappresentabili e iniziano le operazioni aritmetiche
    a = 150;
    c = 100;
    e = -80;

    printf("\n=== ANALISI OVERFLOW E CA2 ===\n\n");

    // --- OPERAZIONE 1a: unsigned + unsigned ---
    risultato1 = a + b;
    printf("Operazione 1a: %u + %u (unsigned)\n", a, b);
    printf("Risultato ottenuto: %u\n", risultato1);
    printf("Risultato teorico: %d\n", (uint16_t)a + (uint16_t)b);
    printf("\n---------------------------------------\n");

     // --- OPERAZIONE 1b: unsigned + unsigned (Overflow) ---
    b = 200; // assegna a b un valore per andare in overflow
    risultato1 = a + b;
    printf("Operazione 1b: %u + %u (unsigned)\n", a, b);
    printf("Risultato ottenuto: %u\n", risultato1);
    printf("Risultato teorico: %u\n", (uint16_t)a + (uint16_t)b);
    printf("\n---------------------------------------\n");


    // --- OPERAZIONE 2a: signed + signed positivi ---
    c = 50;
    risultato2 = c + d;
    printf("Operazione 2a: %d + %d (signed)\n", c, d);
    printf("Risultato ottenuto: %d\n", risultato2);
    printf("Risultato teorico: %u\n", (uint16_t)c + (uint16_t)d);
    printf("\n---------------------------------------\n");

    // --- OPERAZIONE 2b: signed + signed positivi (Overflow) ---
    c = 100;
    risultato2 = c + d;
    printf("Operazione 2b: %d + %d (signed)\n", c, d);
    printf("Risultato ottenuto: %d\n", risultato2);
    printf("Risultato teorico: %u\n", (uint16_t)c + (uint16_t)d);
    printf("\n---------------------------------------\n");

    // --- OPERAZIONE 3a: signed + signed negativi ---
    e = -60;
    risultato3 = e + f;
    printf("Operazione 3a: %d + %d (signed)\n", e, f);
    printf("Risultato ottenuto: %d\n", risultato3);
    printf("Risultato teorico: %d\n", (int16_t)e + (int16_t)f);
    printf("\n---------------------------------------\n");

    // --- OPERAZIONE 3b: signed + signed negativi (Overflow) ---
    e = -80;
    risultato3 = e + f;
    printf("Operazione 3b: %d + %d (signed)\n", e, f);
    printf("Risultato ottenuto: %d\n", risultato3);
    printf("Risultato teorico: %d\n", (int16_t)e + (int16_t)f);
    printf("\n---------------------------------------\n");

    // --- OPERAZIONE 4: signed +  (-signed) (Sottrazione con scarto base,no overflow) ---
    risultato4 = c + e;
    printf("Operazione 4: %d + %d (signed)\n", c, e);
    printf("Risultato ottenuto: %d\n", risultato4);
    printf("Risultato teorico: %d\n", (int16_t)c + (int16_t)e);
    printf("\n---------------------------------------\n");

    // --- OPERAZIONE 5: unsigned - unsigned (overflow) ---
    b = 200;
    risultato5 = a - b;
    printf("Operazione 5: %u - %u (unsigned)\n", a, b);
    printf("Risultato ottenuto: %u\n", risultato5);
    printf("Risultato teorico: %d\n", (int16_t)a - (int16_t)b);
    printf("\n---------------------------------------\n");


    return 0;
}
