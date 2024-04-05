/**
 * @file esercizio_multi_funzioni_v2.c
 * @description
 * @author Lombardi Michele
 */

/*
aggiungere una funzione che inserisca un altro valore nell'array, questa funzione deve essere richiamata 5 volte nel main, dopo aver popolato l'array iniziale.
void add_valore(int *v, n); | void add_valore(int v[], n);
!! ricordarsi come funziona un vettore

in oltre voglio una nuova funzione di stampa alla quale passo l'array, n, e la modalità di stampa:
    la modalità di stampa è definita mediante un numero:
        0: stampa solo l'array
        1: stampa solo l'array, max, min
        2: stampa solo l'array, max, min , media
        3: stampa solo l'array, media e differnza da media,
        4: stampa l'array, max, min, media, differenza da media.

questa funzione viene chiamata 4 volte alla fine del main in questa maniera qui :
1 chiamata -> modalità 2, con l'array originale creato ad inzio main
2 chiamata -> modalità 2, con l'array con i 5 valori aggiunti dalla funzione
3 chiamata -> modalità 3, con l'array con i 5 valori aggiunti dalla funzione
4 chiamata -> modalità 5, con l'array e solo 3 valori aggiunti dalla funzione

*/



#include <stdio.h>
#define MAX 100 //massimo di valori contenuti nel vettore

//prototipo anticipazione delle funzioni utilizzate dal programma
//la loro presenza qui consente di dichiarare funzioni anche dopo il main
void printarray(int a[], int n);
int massimo(int a[], int n);
int minimo(int a[], int n);
long int somma(int a[], int n);
float media(int a[], int n);
float differenza_da_media(int a[], int n);
void stampatutto(int a[], int n, int max, int min, long int somma_v, float media_v, float diff);
void add_valore(int *v, int n); //il puntatore a v equivale &array[0] che equivale ad array
void stampa_nuova(int v[], int n, int mod);

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

    //5 volte
    for(int i=0; i<5; i++)
    {
        add_valore(array, n);
        n++;
    }

    stampa_nuova(array, n-5 ,2);     //1 chiamata -> modalità 2, con l'array originale creato ad inzio main
    stampa_nuova(array, n ,2);     //2 chiamata -> modalità 2, con l'array con i 5 valori aggiunti dalla funzione
    stampa_nuova(array, n ,3);     //3 chiamata -> modalità 3, con l'array con i 5 valori aggiunti dalla funzione
    stampa_nuova(array, n-2 ,4);     //4 chiamata -> modalità 4, con l'array e solo 3 valori aggiunti dalla funzione

    return 0;
}
void stampa_nuova(int v[], int n, int mod)
{
    /*
        0: stampa solo l'array
        1: stampa solo l'array, max, min
        2: stampa solo l'array, max, min , media
        3: stampa solo l'array, media e differnza da media,
        4: stampa l'array, max, min, media, differenza da media.
    */

    switch (mod)
    {
    case 0:
        printarray(v, n);
        break;

    case 1:
        printarray(v, n);
        printf("\nmax: %d\nmin: %d",massimo(v, n),minimo(v, n));
        break;

    case 2:
        printarray(v, n);
        printf("\nmax: %d\nmin: %d\nmedia: %f",massimo(v, n),minimo(v, n),media(v, n));
        break;

    case 3:
        printarray(v, n);
        printf("\nmedia: %f\ndifferenza_da_media: %f",media(v, n),differenza_da_media(v, n));
        break;

    case 4:
        printarray(v, n);
        printf("\nmax: %d\nmin: %d\nnmedia: %f \ndifferenza_da_media: %f",massimo(v, n),minimo(v, n),media(v, n),differenza_da_media(v, n));
        break;

    default:
        break;
    }
}
void printarray(int a[], int n)
{

    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}
void add_valore(int *v,int n)
{
    /*
    n è il numero di elementi !!!!!! non  la posizione dell'ultimo elemento
    quindi l'ultima posizione si trova n-1
    v punta a cosa ? array[0]

    */
    v += n;
    printf("valore da aggiungere: ");
    scanf("%d", v);
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
