/*
Creare tre array di dimensione variabile in base alla richiesta iniziale.
riempire il primo array da tastiera, con numeri casuali
riordinare i valori del primo array in ordine crescente salvandoli sul secondo
riordinare i valori del primo array in ordine decrescente salvandoli sul terzo

Ottenere un OUTPUT composoto così:


Quanti valori si volgiono riordinare? 4

inserire il valore n1: 1
inserire il valore n2: 5
inserire il valore n3: 3
inserire il valore n4: 4


array principale:   1 5 3 4
array crescente:    1 3 4 5
array decrescente:  5 4 3 1

*/

#include <stdio.h> // Libreria standard IO

int main(void)
{
    int N;

    printf("Quanti valori si volgiono riordinare? ");
    scanf("%d", &N);

    int v[N], v2[N], v3[N];

    for (int i=0; i<N; i++)
    {
        printf("inserire il valore n%d: ", i+1);
        scanf("%d", &v[i]);
        v2[i] = v[i];
        v3[i] = v[i];
    }


    for(int i=0; i<N-1; i++)
    {
        int appoggio;
        for(int a=i+1;a<N;a++)
        {
            appoggio = v2[a];

            if (appoggio < v2[i])
            {
                int temp = v2[i];
                v2[i] = appoggio;
                v2[a] = temp;
            }

        }
    }

    for(int i=0; i<N-1; i++)
    {
        int appoggio;
        for(int a=i+1;a<N;a++)
        {
            if (v3[a] > v3[i])
            {
                int temp = v3[i];
                v3[i] = v3[a];
                v3[a] = temp;
            }

        }
    }

    printf("\n\narray principale:\t");
    for (int i=0; i<N; i++)
    {
        printf("%4d ", v[i]);
    }
    printf("\narray crescente:\t");
    for (int i=0; i<N; i++)
    {
        printf("%4d ", v2[i]);
    }
    printf("\narray decrescente:\t");
    for (int i=0; i<N; i++)
    {
        printf("%4d ", v3[i]);
    }


    return 0;
}
