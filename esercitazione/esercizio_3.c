/*
Difficoltà 11/10


creare un sistema per premiare gli operai più produttivi dell'azienda

per ogni operaio salvare 
id intero
nome stringa di 12 caratteri utili 
cognome stringa di 12 caratteri utili 
vettore di 31 interi 
numero_pezzi_mensile intero

creare due liste chimate produzione_reparto1 e produzione_reparto2
predisporre una funzione per aggiungere i dipendenti nella lista1 e nella lista2
predisporre una funzione che, passata, la lista, l' id, il numero del giorno e il numero di pezzi prodotti; setti sull'operaio (id) il suo resoconto giornaliero di produzione
predisporre una funzione chiamata fine_mese che per la lista passata calcoli la prodiuzione mensile di OGNI OPERAIO
predisporre una funzione per stampare i primi tre operai di ogni reparto

Quando fate modifiche all'esercizio apreire il termianle sottostante  (CTRL + j)
scrivere i seguenti comandi:

    git add .
    git commit -m " scrivere qui le modifiche che sono state scritte o una descrizione "
    git push 


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Operaio
{
    struct Operaio * prev;
    int id;
    char nome[13];
    char cognome[13];
    int vettore[31];
    int numero_pezzi_mensile;
    struct Operaio * next;
};
typedef struct Operaio NodoLista;
typedef NodoLista * TipoLista;

TipoLista addData(void)
{
    TipoLista temp = (TipoLista)malloc(sizeof(NodoLista));

    printf("Inserisci id operaio: ");
    scanf("%d", &temp->id);
    printf("Inserisci nome operaio: ");
    scanf("%s", temp->nome);
    printf("Inserisci cognome operaio: ");
    scanf("%s", temp->cognome);
    for(int i=0; i<32; i++)
    {
        vettore[i]=0;
    }
    temp->numero_pezzi_mensile = 0;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

TipoLista addOperaio(TipoLista head)
{
    TipoLista temp = head;
    if(head == NULL)
    {
        head = addData();
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = addData();
        temp->next->prev = temp; 
    }
}
//predisporre una funzione che, passata la lista, l'id, il numero del giorno e il numero di pezzi prodotti; setti sull'operaio (id) il suo resoconto giornaliero di produzione
void resoconto(TipoLista head, int identifier, int dayNum, int pezziProdotti)
{
    TipoLista temp = head;
    if (dayNum < 0 || dayNum >= 31)
    {
        printf("il parametro giorno passato non va bene.");
        break;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->id == identifier)
            {
                temp->vettore[dayNum] = pezziProdotti;
            }
            temp = temp->next;
        }
    }
    
}
//predisporre una funzione chiamata fine_mese che per la lista passata calcoli la prodiuzione mensile di OGNI OPERAIO
void fine_mese(TipoLista head)
{
    TipoLista temp = head;
    while(temp != NULL)
    {
        int numPezzi = 0;
        for(int i=0; i<31; i++)
        {
            numPezzi = numPezzi + vettore[i];
            vettore[i] = 0;
        }
        temp->numero_pezzi_mensile = numPezzi;
        temp = temp->next;
    }
}
//predisporre una funzione per stampare i primi tre operai di ogni reparto
void premioProduzione(TipoLista head)
{
    TipoLista temp = head;
    TipoLista dipendente1;
    int valMax = 0;
    while(temp != NULL)
    {
        if(temp->numero_pezzi_mensile > valMax)
        {
            valMax = temp->numero_pezzi_mensile;
            dipendente1 = temp;
        }
        temp = temp->next;
    }
}

int main(void)
{
    TipoLista produzione_reparto1 = NULL;
    TipoLista produzione_reparto2 = NULL;

    produzione_reparto1 = addOperaio(produzione_reparto1);
    produzione_reparto2 = addOperaio(produzione_reparto2);
    resoconto(produzione_reparto1, 1, 23, 45);
    resoconto(produzione_reparto2, 2, 24, 43);
    fine_mese(produzione_reparto1);
    fine_mese(produzione_reparto2);
    return 0;
}