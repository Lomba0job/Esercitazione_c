/*
Difficoltà 6/10


Programma per la gestione dei campi per un azienda agricola

ogni campo deve avere la dimensione  in ettari (int),
il tipo di frutta/verdura (char[12])
la regione di appartenenza (char[3])
il prezzo di vendita del campo (long int)
la data di raccolta del raccolto (char[12]) formato mm/aa

creare la struttura dati necessaria chiamata lista_campi                                                                                | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per aggiungere i campi                                                                                         | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione per vedere la regione e la dimensione di tutti i campi che rispettano  il tipo di frutta/verdura che si cerca  | FUNZIONA
-----------------------------------------------------------------------------------------------------------------------------------------------
predisporre una funzione che passata la dimensione e la regione elimini l' elemento dalla lista e stampi il prezzo di vendita           | FUNZIONA
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

struct lista_campi
{
    struct lista_campi * prev;
    int dimensione;
    char coltura[12];
    char regione[3];
    long int prezzo;
    char data_raccolto[6];
    struct lista_campi * next;
};
typedef struct lista_campi NodoLista;
typedef NodoLista * TipoLista;

TipoLista acquisizioneDati(void)
{
    TipoLista temp = (TipoLista)malloc(sizeof(NodoLista));

    printf("Inserisci dimensione del campo: ");
    scanf("%d", &temp->dimensione);
    printf("Inserisci tipo di coltura: ");
    scanf("%s", temp->coltura);
    printf("Inserisci regione di appartenenza: ");
    scanf("%s", temp->regione);
    printf("Inserisci prezzo del campo: ");
    scanf("%ld", &temp->prezzo);
    printf("Inserisci data raccolto: ");
    scanf("%s", temp->data_raccolto);
    printf("\n");
    printf("\n");

    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

TipoLista confermareAcquisizione(TipoLista head)
{
    TipoLista temp = head;
    if(head == NULL)
    {
        head = acquisizioneDati();
    }
    else
    {
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = acquisizioneDati();
        temp->next->prev = temp;
    }

    return head;
}

void cercaColtura(TipoLista head, char cerca_coltura[12])
{
    printf("Cerco campi che coltivano %s ...\n\n", cerca_coltura);

    while(head != NULL)
    {
        if(strcmp(head->coltura, cerca_coltura) == 0)
        {
            printf("Regione: %s, Dimensione: %d, Coltura: %s\n", head->regione, head->dimensione, head->coltura);
        }
        head = head->next;
    }
}
// predisporre una funzione che passata la dimensione e la regione elimini l' elemento dalla lista e stampi il prezzo di vendita
TipoLista rimuoviCampo(TipoLista head, int dim, char reg[3])
{
    TipoLista temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->regione, reg) == 0 && temp->dimensione == dim)
        {
            if(temp->prev == NULL)
            {
                temp->next->prev = NULL;
                head = temp->next;
                free(temp);
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
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

    head = confermareAcquisizione(head);
    head = confermareAcquisizione(head);
    head = confermareAcquisizione(head);
    char colt[12] = "mele";
    cercaColtura(head, colt);

    int dimensione;
    char regione[3];
    
    printf("\nInserisci la dimensione del campo da rimuovere: ");
    scanf("%d", &dimensione);
    printf("Inserisci la regione del campo da rimuovere: ");
    scanf("%s", regione);

    rimuoviCampo(&head, dimensione, regione);

    return 0;
}