/*
nel main viene salvato un array di int con valori decisi dall'utente e con dimensione massima 100 

scrivere le funzioni che: 
1) si passa array e numero di valori dell'array -> restituisce max [int]
2) si passa array e numero di valori dell'array -> restituisce min [int]
3) si passa array e numero di valori dell'array -> restituisce somma  [long int]
4) si passa array e numero di valori dell'array -> restituisce media [float]
5) si passa array e numero di valori dell'array -> restituisce deviazione max rispetto media  [int]
6) si passa array e numero di valori dell'array -> restituisce array ordinato in ordine crescente [int []]

7) funzione di stampa di tutto, passando tutti i singoli valori
*/
#include <stdio.h>
#define MAX 100


int main(void)
{
    int array[100];
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
    int max = 
    //richiamo min
    int min =
    //richiamo somma
    long int somma =
    //richiamo media
    float media =
    //richiamo deviazione
    int deviazione =
    //ordine crescente 
    int array_ordinato[MAX];
    array_ordinato = 

    //stampa tutto
}