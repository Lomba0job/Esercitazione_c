/*
Si progetti un sistema infrmativo per la gestione di un singolo supermercato.
Deve salvare la lista dei materiali in maggazino e la lista dei materiali in richiesta

Ogni materiale ha un id univoco composto da 12 cifre
una nome (strigna di 14 caratteri utili)
una marca (stringa di 10 caratteri utili)
una data di scandeza composta da una struttura formata da gg mm aa

nella lista dei materili in magazzino viene salvata oltre il prodotto anche la quantità e la posizione nel magazzino (codice scaffale)
mentre nella lista dei materiali in ordine viene salvato la quantità 

strutturare le strutture necessarie.

predisporre una funzione per creare la lista dei prodotti nel magazzino e la lisa dei prodotti in ordine 
predisporre due funzioni per inserire la prima volta gli elementi nel magazzino 
predisporre una funzione che decrementi un determinato prodotto nella lista dei prodotti in magazzino inserendo il codice scaffale, se la quiantità rimanente è 0 eliminarlo dalla lista presente in magazzino e aggiungerlo nella lista in ordine con quantità 10 
predisporre una funzione che inserendo una determinata data elimini tutti gli elementi in magazzanio con data di scandeza più vecchia e li inserisca nella lista in ordine con quantità 10 per ogniuno 
predisporre una funzione consegna che elimini la lista in ordine e inserisca in magazzino tutti i prodotti che erano presenti e le relative quantità 


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct data
{
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
};

struct prodotto
{
    unsigned int id;
    char nome[15];
    char marca[11];
    struct data DataScadenza;
};

struct magazzino
{
    struct magazzino prev;
    struct prodotto Prodotto;
    unsigned int quantita;
    unsigned int codiceScaffale;
    struct magazzino next;
};


struct ordine
{
    struct ordine prev;
    struct prodotto Prodotto;
    unsigned int quantita;
    struct ordine next; 
};

typedef struct magazzino NodoListaMagazzino;


typedef struct ordine NodoListaOrdini;


