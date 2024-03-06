/**
 * @file esercizio_doppio_array.c
 * @description Esercizio di inserimento dati in un Array, copia in ordine opposto in un altro Array i valori e stamparli entrambi.
 * @author Lombardi Michele 
 */


/*
OUTPUT DEL PROGRAMMA
----------------------------------------------------------------------

*/



#include <stdio.h> // Libreria standard IO 
#define N 3 //define di dimensione array

int main(void)
{
    int v[N], v2[N], i2=0; //allocazione di due array di dimensione fissa N e una variabile int a vlaore iniziale 0

    for (int i=0; i<N; i++) //ciclo for per riempire il vettore, si ripete N volte
    {
        printf("Inserisci: ");
        scanf("%d", &v[i]);
    }

    for (int i=N-1; i>=0; i--) //ciclo for per stampare i vettori verticalmente, paralleli ed invertiti
    {
        v2[i2]=v[i]; // ogni volta che il ciclo si ripete un valore del vettore v viene inserito nella posizione opposta del vettore v2
        printf("%d %d\n", v[i2], v2[i2]);
        i2++; //incremento la posizione in modo da poter inserire nel vettore v2 un nuovo valore proveniente dal vettore v
        
    }

    return 0;
}