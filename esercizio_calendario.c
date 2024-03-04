/**
 * @file esercizio_calendario.c
 * @description esercizio con gli cicli for e while per stampare un calendario
 * @author Enrico Salvagiani 
 */


/*
OUPTUT

Da quanti giorni e' composto il calendario? 31
Da che giorno parte il calendario? 4
               1   2   3   4
   5   6   7   8   9  10  11
  12  13  14  15  16  17  18
  19  20  21  22  23  24  25
  26  27  28  29  30  31
*/



#include <stdio.h> // Libreria standard IO 


int main(void)
{
    int ng, c=1, c7=0, gg; //dichiarazione ed eventuale inizializzazione di variabili necessarie all'esecuzione del programma

    printf("Da quanti giorni e' composto il calendario? ");
    scanf("%d", &gg); //la variabile intera gg assume un valore impostato dall'utente

    printf("Da che giorno parte il calendario? (1-7)");
    scanf("%d", &ng); //la variabile intera ng (numero giorno) assume un valore impostato dall'utente, corrisponde al giorno della settimana
    c7 = ng-1; //inizializzazione della variabile contatore responsabile della corretta disposizione dei numeri in output
    for(int i=0; i<c7; i++) //ciclo for che lascia un tab di spazi che sostituiscono i numeri mancanti prima del primo
    {
        printf("    ");
    }
    while(c <= gg) //ciclo while che si ripete finchè il numero di giorni non viene raggiunto
    {
        while(c7 < 7 && c<=gg) // ciclo while annidato, utilizzato per stampare all'interno della stessa riga che arriava a 7 o a fine mese
        {
            printf("%4d", c); // stampa i giorno del mese in 4 spazi 
            c++; //incrementa il giorno del me se
            c7++; // incrementa il giorno della settimana 
        }
        printf("\n"); //manda a capo ogni 7 giorni
        c7=0; //ricomincia il giorno della settimana dal primo 
    }

    return 0;
}

