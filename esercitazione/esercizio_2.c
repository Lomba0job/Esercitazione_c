/*
difficoltà 4/10

Creare un sistema per la gestione degli operai di una fabbrica

ogni operaio ha
un codice fiscale char[12]
un reparto di riferimento int
una data di assunzione
uno stipendio


creare la lista operai                                                                                                              | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per inserire un nuovo operaio                                                                              | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per stampare l'operaio con lo stipendio più alto di un determinato reparto                                 | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per promuovere un operairo passando il codice fiscale e il nuovo stipendio                                 | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per licenziare un operaio                                                                                  | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------



Quando fate modifiche all'esercizio apreire il termianle sottostante  (CTRL + j)
scrivere i seguenti comandi:

    git add .
    git commit -m " scrivere qui le modifiche che sono state scritte o una descrizione "
    git push


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structOperaio
{
    struct structOperaio * prev;
    char cf[12];
    int repRef;
    char data[9];
    int stipendio;
    struct structOperaio * next;
};

typedef struct structOperaio NodoLista;
typedef NodoLista * TipoLista;

TipoLista Inserimento(void)
{
    TipoLista temp = (TipoLista)malloc(sizeof(NodoLista));

    printf("Inserisci codice fiscale: ");
    scanf("%s", temp->cf);
    printf("Inserisci reparto di riferimento: ");
    scanf("%d", &temp->repRef);
    printf("Inserisci data assunzione: ");
    scanf("%s", temp->data);
    printf("Inserisci stipendio: ");
    scanf("%d", &temp->stipendio);
    printf("\n");
    printf("\n");

    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

TipoLista nuovoOperaio(TipoLista head)
{
    TipoLista temp = head;
    if(head == NULL)
    {
        head = Inserimento();
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = Inserimento();
        temp->next->prev = temp;
    }

    return head;
}

void operaioRicco(TipoLista head, int reparto)
{
    TipoLista temp = head;
    int stipendio_max = 0;
    TipoLista pt_op = NULL;
    while (temp != NULL)
    {
        printf("\t\tTESTCODE:reparto dip: %d, reparto richiesto %d\n", temp->repRef, reparto);
        if (temp->repRef == reparto)
        {
           if(temp->stipendio > stipendio_max)
           {
                stipendio_max = temp->stipendio;
                pt_op = temp;
           }
        }
        temp = temp->next;
    }

    if(pt_op != NULL)
    {
        printf("\nL'operaio %s ha lo stipendio piu alto del reparto: %d con %d", pt_op->cf,pt_op->repRef, pt_op->stipendio);
    }
    else
    {
        printf("\nNessun operaio per quel reparto");
    }
}

void modificaStipendio(TipoLista head, char cerca_cf[12], int nuovo_stipendio)
{
    while(head != NULL)
    {
        if(strcmp(head->cf, cerca_cf) == 0)
        {
            head->stipendio = nuovo_stipendio;
            printf("Stipendio all'operaio %s aggiornato a %d", head->cf, head->stipendio);
        }
        head = head->next;
    }
}


TipoLista licenziaOperaio(TipoLista head, char cerca_cf[12])
{
    TipoLista temp = head;
    
    while(temp != NULL)
    {
        if(strcmp(temp->cf, cerca_cf) == 0)
        {
            if(temp->prev == NULL)
            {
                head=temp->next;
                head->prev = NULL;
                free(temp);
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
            }
        }
        temp = temp->next;
    }
    return head;
}

int main(void)
{
    TipoLista head = NULL;

    head = nuovoOperaio(head);
    head = nuovoOperaio(head);
    head = nuovoOperaio(head);

    int reparto = 1;
    operaioRicco(head, reparto);
    modificaStipendio(head, "1212", 500);
    operaioRicco(head, reparto);
    head = licenziaOperaio(head, "2323");
    return 0;
}