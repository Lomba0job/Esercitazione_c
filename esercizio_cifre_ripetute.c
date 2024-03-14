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
    unsigned long long int n;
    int matrix[RAW][COL] = {{0,1,2,3,4,5,6,7,8,9},{0,0,0,0,0,0,0,0,0,0}};

    printf("Dammi un numero: ");
    scanf("%llu", &n);
    printf("%llu\n", n);
    while(n>0)
    {
        int indice = n%10;
        n /= 10;
        matrix[1][indice]++;

    }

    for(int i=0; i<RAW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
