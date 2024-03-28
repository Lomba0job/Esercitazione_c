/**
 * @file esercizio_funzione_semplice.c
 * @description Primo eserciizo utilizzando le funzioni
 * @author Lombardi Michele
 */

/*
Funzione di count down
*/

#include <stdio.h> //libreria standard
























void countdown(int a) //dichiariamo la funzione countdown prima della funzione main prendendo in input un valore intero
{
    for (int i=a; i>=0; i--) //il ciclo for si occupa di scorrere i numeri a ritroso partendo dal valore dato in input
    {
        printf("%d\n", i); //la funzione si occupa anche della stampa dei valori, uno sotto l'altro
    }
    return; //la funzione non restituisce nulla (perché è void)
}

int main (void) //all'interno della funzione main è necessario solo richiamare la funzione passando il parametro richiesto dalla funzione e null'altro
{
    int b; //variabile intera richiesta dalla funzione 
    printf("value: ");
    scanf("%d", &b); //viene richiesto all'utente il valore dal quale partire per il conto alla rovescia
    countdown(b); //richiamando la funzione e passando il parametro inserito dall'utente non è necessario aggiungere altro al programma

    return 0;
}