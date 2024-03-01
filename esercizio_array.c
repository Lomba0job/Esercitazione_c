/**
 * @file esercizio_array.c
 * @description Esercizio di inserimento dati array e stampa al contrario
 * @author Lombardi Michele 
 */


/*
OUTPUT DEL PROGRAMMA

inserire il valore (1):         3
inserire il valore (2):         4
inserire il valore (3):         5
inserire il valore (4):         6
 6  5  4  3 


*/

#include <stdio.h> // Libreria standard IO 

int main(void)
{
    int v[4]; //allocato un vettore di 4 valori (poszioni 0-3)

    //Popolamento vettore
    for(int i = 0; i < 4; i++) //ciclo for che fa variare i da 0 a 3
    {
        printf("inserire il valore (%d): \t", i+1); //stampa a video il numero  dell'elemento da inserire 1-4
        scanf("%d", &v[i]); //associare il valore inserito da tastiera nella posizione appropriata nell'array
    }


    //stampa del vettore in ordine opposto
    for(int i = 3; i >=0; i--) //ciclo for che fa variare i da 3 a 0
    {
        printf(" %d ", v[i]); //stampa a video il valore dell'array da 3-0
    }
    printf("\n");
    return 0;
}