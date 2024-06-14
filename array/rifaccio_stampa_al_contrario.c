#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main(void)
{
    int v[DIM], v2[DIM];
    // mettiamo i valori nel primo
    for(int i=0; i<DIM; i++)
    {
        printf("inserisci il valore %d: ", i+1);
        scanf("%d", &v[i]);
    }
    //copiamo i valori al contrario nel secondo
        int j=DIM-1;
    for(int i=0; i<DIM; i++)
    {
        v2[j]=v[i];
        j--;
    }

    printf("vettore normale: \n");
    for(int i=0; i<DIM; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    printf("\n");

    printf("vettore contrario: \n");
    for(int i=0; i<DIM; i++)
    {
        printf("%d ", v2[i]);
    }
    return 0;
}
