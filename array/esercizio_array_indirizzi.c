/**
 * @file esercizio_array_indirizzi.c
 * @description esercizio con gli indirizzi di memoria su di un array
 * @author Lombardi Michele 
 */


/*
OUPTUT

Indirizzo del vettore: 6FAD7020
indirizzo del vettore tramite ptr: 6FAD7020 
primo elemento vettore: 10
primo vettore: 10
primo vettore: 10
secondo vettore: 20
secondo vettore: 20
secondo vettore: 20

indirizzo della posizione 2 del vettore tramite ptr: 6FAD7024
*/



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *iPtr; //definizione di un puntatore

    int v[5]={10,20,30,40,50}; //definizione e assegniazione di un array 

    //metodi per vedere l'indirizzio del vettore
    printf("Indirizzo del vettore: %X\n", v); //stamoa l'indirizzo di memoria associato alla variabile vettore, tramite il comando di escape X
    iPtr = v;
    printf("indirizzo del vettore tramite ptr: %X \n",iPtr);

    //metodi per vedere il valore all'interno della posizione 0 dell array
    printf("primo elemento vettore: %d\n", *v);    
    printf("primo vettore: %d\n", *(iPtr));
    printf("primo vettore: %d\n", v[0]);

    //metodi per vedere il valore all'interno della posizione 1 dell array
    printf("secondo vettore: %d\n", *(v+1));
    ++iPtr;
    printf("secondo vettore: %d\n", *iPtr);
    printf("secondo vettore: %d\n", v[1]);


    printf("indirizzo della posizione 2 del vettore tramite ptr: %X", iPtr); // ora il puntatore è sul secondo indirzzo di memoria dell'array e sara composta dal nome di prima +4 (byte di un int)

    return 0;
}

