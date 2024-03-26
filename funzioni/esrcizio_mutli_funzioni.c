/*
nel main viene salvato un array di int con valori decisi dall'utente e con dimensione massima 100 

scrivere le funzioni che: 
1) si passa array e numero di valori dell'array -> restituisce max [int]
2) si passa array e numero di valori dell'array -> restituisce min [int]
3) si passa array e numero di valori dell'array -> restituisce somma  [long int]
4) si passa array e numero di valori dell'array -> restituisce media [float]
5) si passa array e numero di valori dell'array -> restituisce deviazione max rispetto media  [float]

7) funzione di stampa di tutto, passando tutti i singoli valori
*/
#include <stdio.h>
#define MAX 100

//prototipo 
int massimo(int a[], int n);
int minimo(int a[], int n);
long int somma(int a[], int n);
float media(int a[], int n);
float differenza_da_media(int a[], int n);
void stampatutto(int a[], int n, int max, int min, long int somma_v, float media_v, float diff);



int main(void)
{
    int array[MAX];
    int n;

    printf("Quanti valori si vogliono usare? ");
    scanf("%d", &n);
    while(n < MAX)
    {
        printf("Valore massimo superato \nIl massimo di valori sono 100, quanti valori si vogliono usare? ");
        scanf("%d", &n);
    }
    
    for(int i=0; i<n; i++)
    {
        printf("Inserire il valore %d: ", i+1);
        scanf("%d", &array[i]);
    }

    //richiamo max
    int max = massimo(array, n);
    //richiamo min
    int min = minimo(array, n);
    //richiamo somma
    long int somma_v = somma(array, n);
    //richiamo media
    float media_v = media(array, n);
    //richiamo deviazione
    int deviazione = differenza_da_media(array, n);

    //stampa tutto
    stampatutto(array, n, max, min, somma_v, media_v, deviazione);
}

int massimo(int a[], int n)
{
    int max = a[0];
    for(int i=1, i<n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

int minimo(int a[], int n)
{
    int min = a[0];
    for(int i=1, i<n; i++)
    {
        if(a[i] < min)
            min = a[i];
    }
    return min;
}

long int somma(int a[], int n)
{
    long int sum = 0;
    for(int i=0, i<n; i++)
    {
        sum += a[i];
    }
    return sum;
}

float media(int a[], int n)
{
    long int sum = somma(a, n);
    float med = sum/n;
    return med;
}

float differenza_da_media(int a[], int n)
{
    int max = massimo(a, n);
    int min = minimo(a,n);
    float media = media(a, n);

    float dif_m = media - min;
    float dif_M = max - media; 

    if (dif_M > dif_m)
        return dif_M;
    else
        return dif_m;
}

void stampatutto(int a[], int n, int max, int min, long int somma_v, float media_v, float diff)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("max: %d", max);
    printf("min: %d", min);
    printf("somma: %ld", somma_v);
    printf("media: %f", media_v);
    printf("diff: %f", diff);
}
