/*
Creare tre array di dimensione variabile in base alla richiesta iniziale. 
riempire il primo array da tastiera, con numeri casuali 
riordinare i valori del primo array in ordine crescente salvandoli sul secondo 
riordinare i valori del primo array in ordine decrescente salvandoli sul terzo

Ottenere un OUTPUT composoto così:


Quanti valori si volgiono riordinare: 4

inserire il valore n1: 1
inserire il valore n2: 5
inserire il valore n3: 3
inserire il valore n4: 4


array principale:   1 5 3 4
array cres cente:    1 3 4 5
array decrescente:  5 4 3 1 

*/

#include <stdio.h> // Libreria standard IO 

int main(void)
{
    int N;
    
    printf("Di quanti valori vuoi che sia composto il vettore? ");
    scanf("%d", &N);

    int v[N], v2[N], v3[N];

    for (int i=0; i<N; i++)
    {
        printf("inserire il valore n%d: ", i+1);
        scanf("%d", &v[i]);
    }


    return 0;
}