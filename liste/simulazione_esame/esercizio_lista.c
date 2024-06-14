#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct struttura
{
    int numero, vettore[MAX];
    int n_voti;
    float media;
    struct struttura *prev;
    struct struttura *next;

};

typedef struct struttura NodoLista;
typedef struct struttura *TipoLista; // typedef NodoLista * TipoLista

TipoLista f_alloca(void)
{
    TipoLista temp;
    temp = (TipoLista)malloc(sizeof(NodoLista));

    printf("\nInserisci numero Bambino: ");
    scanf("%d", &temp->numero);
    float sum = 0;
    for(int i=0; i<=4; i++) //ne alloca 5 perchè è speciale :)
    {
        printf("inserisci il voto n%d: ", i+1);
        scanf("%d", &temp->vettore[i]);
        sum = sum + temp->vettore[i];
    }
    temp->media = sum/5;
    temp->prev = NULL;
    temp->next = NULL;
    temp->n_voti = 5;

    return temp;
}

TipoLista inserisci_primo(TipoLista head)
{
    TipoLista temp;
    temp = f_alloca();
    return temp;
}

TipoLista elimina(TipoLista head, int target)
{
    if(target == head->numero )
    {
        //caso si voglia eliminare il primo
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }
    else
    {
        TipoLista temp;
        temp = head->next;
        while (temp != NULL)
        {
            if(target == temp->numero )
            {
                //eliminare allocazione
                if(temp->next != NULL)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                else
                {
                    temp->prev->next = NULL;
                    free(temp);
                }
                break;
            }
            temp = temp->next;
        }
        return head;
    }
}


TipoLista inserisci_in_lista(TipoLista head, TipoLista temp)
{
    TipoLista temp2;
    temp2 = head;
    if(temp2->media < temp->media)
    {
        //va inserito in testa
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        //va fatta scorrore per inserire in coda o in mezzo
        while (temp2->next != NULL)
        {
            if(temp2->media < temp->media)
            {
                break;
            }
            temp2 = temp2->next;
        }
        if(temp2->next != NULL)
        {
            //inserisci in mezzo
            temp2->prev->next = temp;
            temp->prev = temp2->prev;
            temp->next = temp2;
            temp2->prev = temp;
        }
        else
        {
            if(temp2->media < temp->media)
            {
                //inserisci nel penultimo posot
                temp2->prev->next = temp;
                temp->prev = temp2->prev;
                temp->next = temp2;
                temp2->prev = temp;
            }
            else
            {
                //inserisci in coda
                temp2->next = temp;
                temp->prev = temp2;
            }
        }
    }

    return head;
}

TipoLista inserisci_da_tastiera(TipoLista head)
{
    //funzione per inserire  i bimbi
    if(head == NULL)
    {
        //è il primo elemento -> deduciamo che andra salvato per forza per primo
        head = inserisci_primo(head);
    }
    else
    {
        //ci sono gia altri elementi -> dobbiamo capire se va salvato prima / dopo / in mezzo
        TipoLista temp;
        temp = f_alloca();
        head = inserisci_in_lista(head, temp);
    }
    return head;
}


TipoLista aggiuni_voto(TipoLista head, int target)
{
    //aggiunge un voto al bimbo numero target
    TipoLista paux = NULL;
    TipoLista temp = head;

    //ricerca del bimbo
    while (temp != NULL)
    {
        if(target == temp->numero )
        {
            paux = head;
            break;
        }
        temp = temp->next;
    }

    //se non lo trova
    if(paux == NULL)
    {
        //non esiste
        printf("Babino non esistente");
        return head;
    }
    //se lo trova
    else
    {
        //se non ha gia 10 voti
        if (paux->n_voti < 10)
        {
            head = elimina(head, target);
            //ora puax non è più in lista
            printf("Inserisci il nuovo voto del bambino %d: ", paux->numero);
            scanf("%d", &paux->vettore[paux->n_voti]);
            paux->n_voti++;
            float somma = 0;
            for(int i; i<paux->n_voti; i++)
            {
                somma = somma + paux->vettore[i];
            }
            paux->media = somma/paux->n_voti;
            if(head != NULL)
            {
                head = inserisci_in_lista(head, paux);
            }
            else
            {
                head = paux;
            }
        }

        //se ha già 10 voti
        else
        {
            printf("Raggiunto il numero massimo di voti");
        }
    }
    return head;
}

void stampa(TipoLista head)
{
    while (head != NULL)
    {
        printf("Bambino Numero%d : Media-> %f\n\n", head->numero, head->media);
        head = head->next;
    }

}





int main(void)
{
    TipoLista head = NULL; //struct struttura * head = NULL;
    //TipoLista coda = NULL;

    head = inserisci_da_tastiera(head); //bambino 1
    head = inserisci_da_tastiera(head); //bambino 2
    head = inserisci_da_tastiera(head); //bambino 3
    head = inserisci_da_tastiera(head); //bambino 4
    head = inserisci_da_tastiera(head); //bambino 5
    head = inserisci_da_tastiera(head); //bambino 6
    head = inserisci_da_tastiera(head); //bambino 7
    stampa(head);
    
    head = aggiuni_voto(head, 1);
    stampa(head);
    head = aggiuni_voto(head, 2);
    stampa(head);
    head = aggiuni_voto(head, 3);
    stampa(head);
    head = aggiuni_voto(head, 4);
    stampa(head);
    head = aggiuni_voto(head, 5);
    stampa(head);
    head = aggiuni_voto(head, 6);
    stampa(head);
    head = aggiuni_voto(head, 7);
    stampa(head);
    head = elimina(head, 4);

    //mi aspetto di ottenere una lista di bimbi ordinati per il voto che hanno di media

    //stampa tutta la lista con numero bambino: media
    stampa(head);

    return 0;
}
