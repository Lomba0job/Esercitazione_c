/**
 * @file esercizio_vettore_lung_var.c
 * @description Esercizio per fare combinare lo spazio logico a quello fisico di un vettore
 * @author Lombardi Michele 
 * @copyright Nanolever 
 */




/*

OUTPUT 
----------------------------------------------------------------------

Quanti valori vogliono essere inseriti: 4
Inserire il valore 1:   1
Inserire il valore 2:   2
Inserire il valore 3:   3
Inserire il valore 4:   4
stampa al contrario:
4321


*/

// FUNZIONA SOLO CON Lo standard C99

#include <stdio.h>

int main(void) 
{
    int i, n;

    printf("Quanti valori vogliono essere inseriti:\t");
    scanf("%d", &n);

    int vettore[n]; //allocazione dinaminca (possibilità di lunghezza diversa per ogni esequzione del programma)

    for (i = 0; i < n; i++)
    {
        printf("Inserire il valore %d:\t", i+1);
        scanf("%d", &vettore[i]);
    }

    printf("stampa al contrario:\n");
    for(i = n - 1; i >= 0; i--)
    {
        printf("%d", vettore[i]);
    }

    return 0;

    
}

