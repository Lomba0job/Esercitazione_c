#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//strutture dati
struct struct_data
{
    unsigned short int giorno;
    unsigned short int mese;
    unsigned short int anno;
    char formato_GG_MM_AA[9];
};

typedef struct struct_data Data;


struct struttura
{
    struct struttura * prev;
    char nomeCognome[71]; //70 caratteri utili + 1 di fine riga
    char nTesseraSan[13];
    unsigned short int idEsame;
    Data dataNascita;
    Data dataEsame;
    struct struttura * next;
};

typedef struct struttura NodoLista;
typedef NodoLista * TipoLista;

TipoLista creaLista(TipoLista head); //funzione crea Lista
void cercaEsame(TipoLista head, char tessera[13]); //funzione ricerca esame
TipoLista cancellaEsame(TipoLista head, char tessera[13]); //funzione elemina prenotazioni di un panzente;



int main(void)
{
    TipoLista testa;
    testa = NULL;
    testa = creaLista(testa);
    testa = creaLista(testa);

    printf("\nPrimo elemento %s ->data esame: %s\n Secondo elemnto %s ->data esame: %s\n", testa->nomeCognome, testa->dataEsame.formato_GG_MM_AA, testa->next->nomeCognome, testa->next->dataEsame.formato_GG_MM_AA);
}

void inserisci_data(Data * data)
{
    printf("Inserisci Giorno: ");
    scanf("%hu", &data->giorno);
    while( data->giorno<1 ||  data->giorno>31)
    {
        printf("giorno inesestinte, reinserisci un dato valido: ");
        scanf("%hu", &data->giorno);
    }
    //mese   ------
    printf("Inserisci Mese: ");
    scanf("%hu", &data->mese);
    while(data->mese<1 || data->mese>12)
    {
        printf("mese inesestinte, reinserisci un dato valido: ");
        scanf("%hu", &data->mese );
    }
    //anno ------
    printf("Inserisci Anno [formato a due cifre]: ");
    int anno;
    scanf("%d", &anno);
    while(anno<0 || anno>99)
    {
        printf("anno non valido, reinserisci un dato valido nel formato a due cifre: ");
        scanf("%d", &anno);
    }
    data->anno = (unsigned short)anno; //sarebbe il metodo corretto

    sprintf(data->formato_GG_MM_AA, "%02hu/%02hu/%02hu", data->giorno, data->mese, data->anno);
}

TipoLista inserisci_dati(void)
{
    TipoLista paux;
    //allcoare la memoria necessaria
    paux = (TipoLista)malloc(sizeof(NodoLista));

    //inserimento dati da tastiera
    printf("Inserisci nome e cognome attaccati:\t");
    scanf("%s", paux->nomeCognome);

    printf("Inserisci la tessera sanitaria:\t");
    scanf("%s", paux->nTesseraSan);

    printf("COMPONI Data di nascita\n");
    inserisci_data(&paux->dataNascita);

    printf("Inserisci l'id dell'esame:\t");
    scanf("%hu", &paux->idEsame);

    printf("COMPONI Data esame\n");
    inserisci_data(&paux->dataEsame);

    return paux;
}

TipoLista inserisci_primo_elemento_lista(TipoLista head){
    //richiamo inserimento dati da tastiera
    head = inserisci_dati();
    //sistemazione puntatori
    head->prev = NULL;
    head->next = NULL;
    //restituzione lista aggiornata

    return head;
}

void inserisci_elemento_lista(TipoLista head){
    //richiamo inserimento dati da tastiera
    TipoLista paux;
    paux = inserisci_dati();
    TipoLista ultimo = head;
    //sistemazione puntatori
    while (ultimo->next != NULL)
    {
        ultimo = ultimo->next;
    }
    ultimo->next = paux;
    paux->prev = ultimo;
    paux->next = NULL;
}

TipoLista creaLista(TipoLista head)
{
    //inserire i dati di una prenotazione nella lista
    /*
        1° caso: se la lista è vuota deve inserire il primo elemento
            |-> bisogna struttrare una funzione inserisci_primo_elemento_lista
        2° caso: se la lista contiene già uno o più elementi sono da mettere in cascata/testa
            |-> bisogna strutturare una funzione inserisci_elemento_lista
    */

   //verifichimao in che caso ci troviamo
    if(head == NULL)
    {
        //primo caso
        //richiamiamo la rispettiva funzione
        head = inserisci_primo_elemento_lista(head);
    }
    else
    {
        //secondo caso
        //richiamiamo la rispettiva funzione
        inserisci_elemento_lista(head);
    }

    //resittuiamo la lista aggiornata
    return head;




}
void stampa_appuntamento(TipoLista paux, int i)
{
    printf("\nAppuntamento numero %d in data: %s", i, paux->dataEsame.formato_GG_MM_AA);
}

void cercaEsame(TipoLista head, char tessera[13])
{
    int i = 1;
    printf("\n\nAppuntamenti del paziente con Tessera sanitaria %s:\n", tessera);
    if(head == NULL)
    {
        printf("Nessun appuntamento trovato");
    }
    else
    {
        do
        {
            if(strcmp(head->nTesseraSan, tessera) == 0)
            {
                stampa_appuntamento(head, i);
                i++;
            }
            head = head->next;
        }while (head != NULL);
        if (i == 1)
        {
            printf("Nessun appuntamento trovato");
        }
    }
    
}

TipoLista elimina_appuntamento(TipoLista head, TipoLista paux)
{
    if (head == paux){
        //1° elemento da elimare 
        head = head->next;
        head->prev = NULL; 
        free(paux);
        
    }
    else
    {
        if(paux->next == NULL)
        {
            //è l'ultimo elemento 
            paux->prev->next = NULL;
            free(paux);
        }
        else{
            paux->prev->next = paux->next;
        }
    }
    return head; 
}

TipoLista cancellaEsame(TipoLista head, char tessera[13])
{
    if(head == NULL)
    {
        printf("lista vuota");
    }
    else
    {
        TipoLista paux = head;
        do
        {
            if(strcmp(paux->nTesseraSan, tessera) == 0)
            {
                head = elimina_appuntamento(head, paux);
            }
            paux = paux->next;
        }while (paux != NULL); 
    }
    return head;
}