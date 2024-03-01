/**
 * @file esercizio_array_dimensione_logica.c
 * @description allocazione di un array di dimensione massima N e inserimento logico variabile ad esecuzione
 * @author Lombardi Michele 
 */

/*
OUTPUT 
----------------------------------------------------------------------
quanti valori vuoi inserire nel vettore [MAX 100]:      4
inserire il valore (1):         1
inserire il valore (2):         2
inserire il valore (3):         3
inserire il valore (4):         4
 4  3  2  1 

*/


/*
OUTPUT OUT OF INDEX
----------------------------------------------------------------------
quanti valori vuoi inserire nel vettore [MAX 100]:      130
Errore: numero di elementi fouri scala


*/
#include <stdio.h> // Libreria standard IO 
#define N_MAX 100 //define di dimensione array


int main(void)
{
    int v[N_MAX]; //allocato un vettore di N valori (poszioni 0-N-1)
    int n; //allocata la varibaile int n

    printf("quanti valori vuoi inserire nel vettore [MAX 100]:\t");
    scanf("%d", &n); //inserimento della dimensione dell'array da parte dell'utente

    //controllo che l'utente non abbia superato valore massimo
    if(n > N_MAX)
    {
        printf("Errore: numero di elementi fouri scala");
        return 1; // retituisce errore 1
    }


    //Popolamento vettore
    for(int i = 0; i < n; i++) //ciclo for che fa variare i da 0 a N-1
    {
        printf("inserire il valore (%d): \t", i+1); //stampa a video il numero  dell'elemento da inserire 1-4
        scanf("%d", &v[i]); //associare il valore inserito da tastiera nella posizione appropriata nell'array
    }


    //stampa del vettore in ordine opposto
    for(int i = n-1; i >=0; i--) //ciclo for che fa variare i da N-1 a 0
    {
        printf(" %d ", v[i]); //stampa a video il valore dell'array da 3-0
    }
    printf("\n");
    return 0;
}