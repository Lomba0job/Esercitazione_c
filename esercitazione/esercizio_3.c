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
predisporre una funzione chiamata fine_mese che per la lista pssata calcoli la prodiuzione mensile dI OGNI OPERAIO 
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
    if (dayNum >= 0 && dayNum < 31)
    {
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
int main(void)
{
    TipoLista produzione_reparto1 = NULL;
    TipoLista produzione_reparto2 = NULL;

    produzione_reparto1 = addOperaio(produzione_reparto1);
    produzione_reparto2 = addOperaio(produzione_reparto2);
    return 0;
}
