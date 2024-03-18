/**
 * @file esercizio_parole_palindrome.c
 * @description controlla se una parola è palindroma o non palindroma
 * @author Enrico Salvagiani 
 */

/*
OUTPUT 
----------------------------------------------------------------------
Inserisci la parola: itopinonavevanonipoti
palindroma

*/

#include <stdio.h>
#include <string.h> //libreria per utilizzare funzioni per le stringhe
#define DIM 30 //dimensione massima per la parola in input

int main (void)
{
    char parola[DIM]; //la parola data dall'utente assume DIM come dimensione massima

    printf("Inserisci la parola: ");
    gets(parola); //come lo scanf ma non serve assegnare l'indirizzo di memoria

    int len = strlen(parola); //la variabile len ci permette di capire quanto è lunga la stringa data in input
    int flag = 0; //utilizzata per l'output finale
    for(int i=0; i<=len/2; i++) //il ciclo for si ripete fino a metà della lughezza della parola data
    {
        if(parola[i]!=parola[len-i-1]) //controllo diversità tra i caratteri iniziali e finali e mi avvicino sempre di più al centro con una manovra a tenaglia
        {
            flag = 1; //salva se la condizione sia verificata
            break; //non appena la condizione si verifica, esce dal for
        }
    }

    if(flag == 0) //se è stato eseguito tutto il for la parola è palindroma
        printf("palindroma");
    else //altrimenti no
        printf("non palindroma");

    return 0;
}
