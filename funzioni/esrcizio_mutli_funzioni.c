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
#define MAX 100 //massimo di valori contenuti nel vettore

//prototipo anticipazione delle funzioni utilizzate dal programma
//la loro presenza qui consente di dichiarare funzioni anche dopo il main
int massimo(int a[], int n);
int minimo(int a[], int n);
long int somma(int a[], int n);
float media(int a[], int n);
float differenza_da_media(int a[], int n);
void stampatutto(int a[], int n, int max, int min, long int somma_v, float media_v, float diff);



int main(void)
{
    int array[MAX]; //vettore che riempiamo di n cifre per un massimo di MAX
    int n; //numero di valori salvati nell'array

    printf("Quanti valori si vogliono usare? ");
    scanf("%d", &n);

    while(n > MAX) //stampa l'errore in caso vengano inseriti più di MAX valori, il controllo viene fatto ad ogni inserimento
    {
        printf("Valore massimo superato \nIl massimo di valori sono 100, quanti valori si vogliono usare? ");
        scanf("%d", &n);
    }

    for(int i=0; i<n; i++) //ciclo for per riempire l'array
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
    float deviazione = differenza_da_media(array, n);

    //stampa tutto
    stampatutto(array, n, max, min, somma_v, media_v, deviazione);

    return 0;
}

int massimo(int a[], int n)
{
    /*
    descrizione: 
    questa funzione trova il massimo valore contenuto nei primi n valori dell'array

    input: 
    Array: int[] - array dei valori da cui ricavare il massimo 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    int - valore massimo dell'array passato
    */
    int max = a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

int minimo(int a[], int n)
{
    /*
    descrizione: 
    questa funzione trova il minimo valore contenuto nei primi n valori dell'array

    input: 
    Array: int[] - array dei valori da cui ricavare il minimo 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    int - valore minimo dell'array passato
    */
    int min = a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i] < min)
            min = a[i];
    }
    return min;
}

long int somma(int a[], int n)
{
    /*
    descrizione: 
    questa funzione calcola la somma dei primi n valori dell'array

    input: 
    Array: int[] - array dei valori da cui ricavare la somma 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    long int - somma dei valori
    */
    long int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];
    }
    return sum;
}

float media(int a[], int n)
{
    /*
    descrizione: 
    questa funzione calcola la media dei primi n valori dell'array

    input: 
    Array: int[] - array dei valori da cui ricavare la media 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    float - media dei valori
    */
    long int sum = somma(a, n); //richiama la funzione somma
    float med = (double)sum / n; //cast necessario per calcolare la media in virgola mobile 
    return med;
}

float differenza_da_media(int a[], int n)
{
    /*
    descrizione: 
    questa funzione calcola la differenza massima tra i primi n valori dell'array e la media 
    per rappresentare in fomrmato "media +- valore" l'array fino a n 

    input: 
    Array: int[] - array dei valori da cui ricavare la media 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    float - media dei valori
    */
    int max = massimo(a, n);
    int min = minimo(a,n);
    float media_v = media(a, n);

    float dif_m = media_v - (float)min; //cast necessario per calcolare la media in virgola mobile 
    float dif_M = (float)max - media_v; //cast necessario per calcolare la media in virgola mobile 

    if (dif_M > dif_m)
        return dif_M;
    else
        return dif_m;
}

void stampatutto(int a[], int n, int max, int min, long int somma_v, float media_v, float diff)
{
    /*
    descrizione: 
    questa funzione calcola la differenza massima tra i primi n valori dell'array e la media 
    per rappresentare in fomrmato "media +- valore" l'array fino a n 

    input: 
    Array: int[] - array dei valori da cui ricavare la media 
    n: int - n di valori contenuti nell'array da utilizzare

    output:
    float - media dei valori
    */
    printf("array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nmax: %d", max);
    printf("\nmin: %d", min);
    printf("\nsomma: %ld", somma_v);
    printf("\nmedia: %f", media_v);
    printf("\ndistanza massima da media: %f", diff);
}
