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

typedef struct struttura_coda
{
    int a; //id crescente
    float b; //la versione della lista
    char parola[20]; //numero id scritto
    struct struttura_lista *next;
}TipoNodoCoda;

typedef TipoNodoCoda *TipoCoda;


/*
TEORIA SULLE LISTE E CODE:

    LISTA:
        attualmente è:
            HEAD->elemento1->NULL
        se aggiungo elemento2 diventa:
            HEAD->elemento2->elemento1->NULL

    CODA:
        attualmente è:
            HEAD->elemento1->NULL
        se aggiungo elemento2 diventa:
            HEAD->elemento1->elemento2->NULL

*/


//PROTOTIPO
//lista
TipoLista add_first_element_lista(TipoLista head);
TipoLista add_element_lista(TipoLista head);
void stampa_lista(TipoLista head);
void stampa_elemento_lista(TipoLista head);

//coda
TipoCoda add_first_element_coda(TipoCoda head);
void add_element_coda(TipoCoda head);
void stampa_coda(TipoCoda head);
void stampa_elemento_coda(TipoCoda head);

//generali
void trova_parola(int n, char p[20]);


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


//programma LISTA
TipoLista add_first_element_lista(TipoLista head)
{
    head = (TipoLista)malloc(sizeof(TipoNodoLista)); //alloca la memoria di spazio struct
    head->a = 1; //pone a dentro la struttura uguale a 1
    head->b = 1.1; //pone b dentro la struttura uguale a 1.1
    strcpy(head->parola, "Uno"); //copia la stringa dentro la struttura
    head->next = NULL; //pone next NULLO perchè non c'è niente dopo
    return head; //restituisce head che punta alla nuova struttura
}

TipoLista add_element_lista(TipoLista head)
{

    TipoLista paux; //crea un puntatore temporaneo
    paux = (TipoLista)malloc(sizeof(TipoNodoLista)); //gli associa la nuova allocazione di memoria
    int numero;     //crea variabile d'appoggio
    float versione; //crea variabile d'appoggio

    numero = head->a; //associa il valore della variabile d'appoggio con quello contenuta nell'ultimo elemento della lista aggiunto
    versione = head->b; //associa il valore della variabile d'appoggio con quello contenuta nell'ultimo elemento della lista aggiunto

    paux->next = head; //pone next della nuova satruttura uguale alla vecchia head
    paux->a = numero+1; //pone a della nuova struttura ugule a l'ultima vecchia  aggiungendo uno
    paux->b = versione; //la versione è la stessa

    char parola_p[20];
    trova_parola(numero+1, parola_p); //funzione per la stringa

    strcpy(paux->parola, parola_p);
    head = paux; //aggionrna head che ora punta l'ultimo aggiunto nella lista
    return head;
}

void stampa_elemento_lista(TipoLista head)
{
    printf("OGGETO\nID:\t%d\nPAROLA:\t%s\nVERSIONE:\t%f\nNEXT:%X\n\n", head->a, head->parola, head->b, head->next); //stampa il conenuto della lista
}

void stampa_lista(TipoLista head)
{
    TipoLista paux;
    paux = head->next;
    stampa_elemento_lista(head); //richiamo a stampo elemento
    if(paux != NULL)
        stampa_lista(paux); //richiamata ricorsiva fino a NULL

}
//fine programma lista

//programma coda
TipoCoda add_first_element_coda(TipoCoda head)
{
    head = (TipoCoda)malloc(sizeof(TipoNodoCoda));
    head->a = 1;
    head->b = 1.2;
    head->next = NULL;
    strcpy(head->parola, "Uno");

    return head;
}

void add_element_coda(TipoCoda head)
{
    //funzione per l'aggiunta di un nuovo elemento nella coda
    TipoCoda paux = head; //porre un puntatore d'appoggio uguale alla coda
    while (paux->next != NULL) //finchè non si punta l'utlimo elemento della coda attuale
    {
        paux = paux->next; //aggiornare il puntatore temporaneo
    }

    paux->next = (TipoCoda)malloc(sizeof(TipoNodoCoda)); //aggiungere un nuovo elemento nel puntatore next dell'ultimo elemento
    paux->next->a = paux->a + 1; //nella nuova struttura a deve valere a della precedente + 1
    paux->next->b = paux->b; //b deve valere come b di quella precedente
    paux->next->next = NULL; //next deve essere nullo


    char parola_p[20];
    trova_parola(paux->next->a, parola_p); //funzione per la stringa
    strcpy(paux->next->parola, parola_p); //copiare la parola passata dalla funzione nella struttura


}

void stampa_coda(TipoCoda head)
{
    if(head != NULL)
    {
        stampa_elemento_coda(head);
        head = head->next;
        stampa_coda(head);
    }
}

void stampa_elemento_coda(TipoCoda head)
{
    //stampare il signolo elemento puntato dal puntatore head
    printf("Elemento %d\nVersione %f\nParola %s\n\n", head->a, head->b, head->parola);

}


//fine programma coda

int main (void)
{
    TipoLista head_lista;
    head_lista = add_first_element_lista(head_lista);

    for (int i = 0; i<10; i++)
    {
        //aggiungere 10 elementi nella lista
        head_lista = add_element_lista(head_lista);
    }
    printf("\n--------------------------------------------------------------\nLISTA\n-------------------------------------------------------------------------------------\n");
    stampa_lista(head_lista);

    TipoCoda head_coda;
    head_coda = add_first_element_coda(head_coda);

    for (int i = 0; i<10; i++)
    {
        //aggiungere 10 elementi nella lista
        add_element_coda(head_coda);
    }
    printf("\n--------------------------------------------------------------\nCODA\n-------------------------------------------------------------------------------------\n");
    stampa_coda(head_coda);
}
