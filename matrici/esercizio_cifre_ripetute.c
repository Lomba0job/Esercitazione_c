/**
 * @file esercizio_cifre_ripetute.c
 * @description
 * @author Lombardi Michele
 * @copyright Nanolever
 */


/*
Salvare da tastiera un numero
scrivere una matrice composta da 10 colonne e 2 righe
la prima riga rappresetna le cifre disponibili 0-9
la seconda colonna rappresenta per ogni cifra quante volte si ripete all'interno del numero salvato precedentemente

*/
#include <stdio.h>

#define RAW 2
#define COL 10

int main(void)
{
    unsigned long long int n; // la variabile è in grado di supportare valori con tante tante cifre
    int matrix[RAW][COL] = {{0,1,2,3,4,5,6,7,8,9},{0,0,0,0,0,0,0,0,0,0}}; //la prima riga della matrice avrà sempre tutte le cifre in ordine crescente, pertanto viene inizializzata così

    printf("Dammi un numero: ");
    scanf("%llu", &n); //l'utente inserisce un numero che viene salvato nella variabile n
    while(n>0) //per comporre la seconda riga della matrice dividiamo il numero fino a quando il resto non è 0
    {
        int indice = n%10; // salvo il resto della divisione in una variabile di appoggio (la cifra singola più a destra)
        n /= 10; //divido anche il numero per scartare la cifra del resto salvata in indice
        matrix[1][indice]++; //incremento il numero nella seconda riga della matrice nella colonna indicata dal resto della divisione

    }

    for(int i=0; i<RAW; i++) // procedura di stampa della matrice con 2 for annidati
    {
        for(int j=0; j<COL; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // finito di stampare la prima riga vado a capo
    }
}
