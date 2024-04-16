/**
 * @file esercizo_lista_semplice.c
 * @description
 * @author Lombardi Michele
 */

/*
definire una lista con all'interno una int un float e una stringa

scrivere le funzioni per agigungere un elemnto nella lista
eliminare l'ultimo elemento della lista

cercare nella lista un elemento che abbia una stringa uguale a str
cercare nella lista gli elemento con N come int
*/


//prima cosa definisci la cazzo di struttura nodolista

//definisci la struttura tipo lista

//definisci la madonna

//main

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct struttura_lista
{
    int a; //id crescente
    float b; //la versione della lista
    char parola[20]; //numero id scritto
    struct struttura_lista *next;
}TipoNodoLista;

typedef TipoNodoLista *TipoLista;


void trova_parola(int n, char p[20])
{
    switch (n)
    {
    case 1:
        strcpy(p,"uno");
        break;

    case 2:
        strcpy(p,"due");
        break;

    case 3:
        strcpy(p,"tre");
        break;

    case 4:
        strcpy(p,"quattro");
        break;

    case 5:
        strcpy(p,"cinque");
        break;

    case 6:
        strcpy(p,"sei");
        break;

    case 7:
        strcpy(p,"sette");
        break;

    case 8:
        strcpy(p,"otto");
        break;

    case 9:
        strcpy(p,"nove");
        break;

    case 10:
        strcpy(p,"dieci");
        break;

    case 11:
        strcpy(p,"undici");
        break;

    case 12:
        strcpy(p,"dodici");
        break;


    default:
        break;
    }
}

void add_first_element(TipoLista head)
{
    head = (TipoLista)malloc(sizeof(TipoNodoLista));
    head->a = 1;
    head->b = 1.1;
    strcpy(head->parola, "Uno");
    head->next = NULL;
}

void add_element(TipoLista head)
{
    TipoLista paux;
    paux = (TipoLista)malloc(sizeof(TipoNodoLista));
    int numero;
    float versione;

    numero = head->a;
    versione = head->b;

    paux->next = head;
    paux->a = numero+1;
    paux->b = versione;

    char parola_p[20];
    trova_parola(numero+1, parola_p);

    strcpy(paux->parola, parola_p);
    ;
    head = paux;
}
void stampa_elemento(TipoLista head)
{
    printf("OGGETO\nID:\t%d\nPAROLA:\t%s\nVERSIONE:\t%f\n\n", head->a, head->parola, head->b);
}

void stampa_lista(TipoLista head)
{
    TipoLista paux;
    paux = head->next;
    stampa_elemento(head);
    if(paux != NULL)
        stampa_lista(paux);

}

int main (void)
{
    TipoLista head;
    add_first_element(head);

    for (int i = 0; i<10; i++)
    {
        //aggiungere 10 elementi nella lista
        add_element(head);
    }

    stampa_lista(head);

}
