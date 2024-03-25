/*
Inserire 8 parole da tastiera e 8 relative spiegazioni delle parole
ordinarle in ordine alfabetico le 8 parole e le relative spiegazioni


usare, o due matrici, o una a 3 dimensioni
*/

#include <stdio.h>
#include <string.h> //la libreria per le funzioni relative alle stringhe

#define ROW 8 //numero di righe della matrice
#define MAX_LEN_WORD 10 //lunghezza massima della parola
#define MAX_LEN_DESC 5000 //lunghezza massima della descrizione

int main(void)
{
    char matrix_parole[ROW][MAX_LEN_WORD]; //dichiaro una matrice matrix_parole di righe ROW e di parole lunghe MAX_LEN_WORD
    char matrix_descrizioni[ROW][MAX_LEN_DESC+1]; //dichiaro una matrice matrix_descrizioni di righe ROW e contenente la descrizione delle parole di MAX_LEN_DESC+1
    int num; //variabile utilizzata per rintracciare la posizione delle parole nella matrice
    int c; //fintanto che il carattere non corrisponde a '}' continua ad andare avanti a chiedere caratteri per comporre la descrizione della parola in questione

    for(int i=0; i < ROW; i++) //ciclo for relativo all'inserimento delle parole e alla loro descrizione
    {
        printf("inserisci la parola: \n");
        //salva la parola
        scanf("%s", matrix_parole[i]); //salva l'array di caratteri che compone la parola nella posizione i corrente

        printf("inserisci la descrizione della parola (termina la descrizione  con }): \n");
        //salva la descrizione
        int j = 0; //variabile di controllo della lunghezza della descrizione
        while ((c=getchar()) != '}') //fintanto che il carattere non corrisponde a '}' continua ad andare avanti a chiedere caratteri per comporre la descrizione della parola in questione
        {
            if(j < MAX_LEN_DESC) //fintanto che la descrizione non è lunga quanto MAX_LEN_DESC vengono inseriti caratteri nella matrice
                matrix_descrizioni[i][j++] = c;

        }
        matrix_descrizioni[i][j] = '\0'; //caratere invio
    }

    //ordina per parola (ordina anche la relativa descrizione)

    for (int i=0; i<ROW-1; i++)
    {
        for (int j=i+1; j<ROW; j++)
        {
            /*
                1) il primo ciclo for scorre le parole dalla prima alla penultima 
                2) il secondo ciclo for parte dalla parole successiva a quella del primo ciclo e scorre progressivamente tutte le altre fino all'utlima
            */
            if(strcmp(matrix_parole[i],matrix_parole[j]) > 0) 
            // mettendo in comparazione le parole indicate dal primo ciclo e dal secondo, se quella del secondo ciclo viene prima in ordine alafaabetico dell'altra si procede allo scambio 
            {
                // le scambiamo
                char app[MAX_LEN_WORD]; //variabile d'appoggio necessaria per l'ordinamento
                strcpy(app, matrix_parole[i]); // associamo alla variabile di appogio la parola indicata dal primo ciclo
                // app == parola indicata da i 
                strcpy(matrix_parole[i], matrix_parole[j]); //associamo alla parola indicata dal primo ciclo il valore di quella indicata dal secondo 
                // parola indicata da i == parola indicatra da j e saranno diverse da app
                strcpy(matrix_parole[j], app); //associamo la parola del secondo ciclo a quella salvata nell'appoggio 
                // parola indicata da j == app diverse da parola indicata da i 

                /*
                parola i nuova = parola j vecchia 
                parola j nuova = parola i vecchia
                */
                
                // ripetere lo stesso procedimento anche per le relative descrizione nell'altra matrice
                char app1[MAX_LEN_DESC];
                strcpy(app1, matrix_descrizioni[i]);
                strcpy(matrix_descrizioni[i], matrix_descrizioni[j]);
                strcpy(matrix_descrizioni[j], app1);
            }
        }
    }



    for(;;) //ciclo infinito
    {
        system("cls"); //comando che fa in modo che la schermata venga pulita per mostrare il contenuto selezionato più recente
        //stampa tutte le parole con un numero davanti 1-ROW MENU
        printf("\n\n\t--------MENU--------");
        for (int i=0; i<ROW; i++)
        {
            printf("\n\t %2d - %10s  ", i+1, matrix_parole[i]);
        }
        printf("\n\t----------------\n");

        printf("di che parola vuoi vedere la descrizione: [0 per usciere]\t ");
        scanf("%d", &num);

        //aggiungi il resto del codice


        if (num == 0)
            break; // USCIRE DAL CICLO FOR INFINITO
        else // se è stato inserito un numero strampare la rispettiva descrizone 
            {
                system("cls");
                printf("\nHai selezionato la prola %s", matrix_parole[num-1]);
                printf("\n\nIl suo significato: \n");
                printf("%s", matrix_descrizioni[num-1]);

                printf("\n\n\n\nPREMERE SPAZIO POI INVIO PER CONTINUARE");
                while(( c = getchar()) != ' '){} // aspetta che venga inviato il carattere spazio per ricominciare il ciclo 
            }


     /*
     ! BUG 

     questo programma presenta un bug :
     se viene inviato un numero non presente nel menu, e questo numero supera la matrice 
     il programma restituisce errore. 
     per risolvere basta inserire dentro l'else un controllo del numero 
     esempio se sono state salvate 7 parole bisogna contrallare che il numero sia
     minore o uguale a 7 prima di stampare la descrizione, in caso contrario bisogna richiederlo all'interno di un ciclo while che si ripete 
     finche il valore non è accettabile 
     
     */
    }
}
