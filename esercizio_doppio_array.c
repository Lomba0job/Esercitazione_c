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
    int v[N], v2[N], i2=0;
    
    for (int i=0; i<N; i++)
    {
        printf("Inserisci: ");
        scanf("%d", &v[i]);
    }

    for (int i=N-1; i>=0; i--)
    {
        v2[i2]=v[i];
        printf("%d %d\n", v[i2], v2[i2]);
        i2++;
        
    }

    return 0;
}