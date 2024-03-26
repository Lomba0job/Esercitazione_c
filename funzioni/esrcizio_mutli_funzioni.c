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
void stampatutto(int a[], int n, int max, int min, long int somma, float media, float diff);



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
    long int somma = somma(array, n);
    //richiamo media
    float media = media(array, n);
    //richiamo deviazione
    int deviazione =

    //stampa tutto
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