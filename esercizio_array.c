/**
 * @file esercizio_array.c
 * @description Esercizio di inserimento dati array e stampa al contrario
 * @author Lombardi Michele 
 */


/*
OUTPUT DEL PROGRAMMA
----------------------------------------------------------------------
inserire il valore (1):         3
inserire il valore (2):         4
inserire il valore (3):         5
inserire il valore (4):         6
 6  5  4  3 


*/

#include <stdio.h> // Libreria standard IO 
#define N 10 //define di dimensione array


int main(void)
{
    int v[N]; //allocato un vettore di N valori (poszioni 0-N-1)

    //Popolamento vettore
    for(int i = 0; i < N; i++) //ciclo for che fa variare i da 0 a N-1
    {
        printf("inserire il valore (%d): \t", i+1); //stampa a video il numero  dell'elemento da inserire 1-4
        scanf("%d", &v[i]); //associare il valore inserito da tastiera nella posizione appropriata nell'array
    }


    //stampa del vettore in ordine opposto
    for(int i = N-1; i >=0; i--) //ciclo for che fa variare i da N-1 a 0
    {
        printf(" %d ", v[i]); //stampa a video il valore dell'array da 3-0
    }
    printf("\n");
    return 0;
}