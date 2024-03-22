/*
Inserire 8 parole da tastiera e 8 relative spiegazioni delle parole
ordinarle in ordine alfabetico le 8 parole e le relative spiegazioni


usare, o due matrici, o una a 3 dimensioni 
*/

#include <stdio.h>
#include <string.h>

#define ROW 8
#define MAX_LEN_WORD 10
#define MAX_LEN_DESC 50

int main(void)
{
    char matrix_parole[ROW][MAX_LEN_WORD];
    char matrix_descrizioni[ROW][MAX_LEN_DESC];
    int num;

    for(int i=0, i<ROW; i++)
    {
        printf("inserisci la parola: ");
        //salva la parola 

        printf("inserisci la descrizione della parola [termina la descrizione  con }");
        //salva la descrizione 

    }

    //ordina per parola (ordina anche la relativa descrizione)


    

    for(;;)
    {
        printf("cls");
        //stampa tutte le parole con un numero davanti 1-8

        printf("di che parola vuoi vedere la descrizione: [0 per usciere]")
        scanf("%d", &num);

        //aggiungi il resto del codice 

        
        if (num == 0)
            break;
    }

}