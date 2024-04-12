/*
Sviluppare un programma in c che funzioni come una rubrica, utlizzando le struct e le altre strutture conosciute

Numero massimo di elementi in rubrica 100

predisporere un menu per scegliere quale opzione eseguire tra:
1)   aggiungere un nuovo elemento (possibile implementazione di verifica se il numero è già esistente),
     che salva per ogni numero i relativi dati personali:
        1) nome,
        2) cognome,
        3) data di nascita (giorno, mese, anno),
        4) azienda,
        5) numero
2)   eliminare un vecchio elemento,
3)   modificare un elemnto,
4)   cercare un elemento per nome (visualizzare tutti gli elementi coi quei dati),
5)   cercare un elemtno per cognome (visualizzare tutti gli elementi coi quei dati),

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct
{
    char p_name[10], p_surname[20], factory[15];
    unsigned short int day, month, year;
    unsigned long int phonenumber;
}persona;

void inserimento(persona array[], int posizione, int modalita)
{
    switch (modalita)
    {
    case 0:
        //menu per inserimento deri valori nella struct nella posizone n dell'array
        system("cls");
        printf("Inserire il nuovo elemnto in rubrica\n");
        break;

    case 1:
        //menu per inserimento deri valori nella struct nella posizone n dell'array
        system("cls");
        printf("Modificare %s %s nella rubrica\n", array[posizione].p_name, array[posizione].p_surname);
        break;
    
    default:
        break;
    }
    
    //numero ------
    printf("Inserisci numero di telefono: ");
    scanf("%lu", &array[posizione].phonenumber);
    //nome   ------
    printf("Inserisci Nome: ");
    scanf("%c", &array[posizione].p_name);
    //cognome ------
    printf("Inserisci Cognome: ");
    scanf("%c", &array[posizione].p_surname);
    //società ------
    printf("Inserisci Società: ");
    scanf("%c", &array[posizione].factory);
    //giorno   ------
    printf("Inserisci Giorno di Nascita: ");
    scanf("%c", &array[posizione].day);
    while(day<1 || day>31)
    {
        printf("giorno inesestinte, reinserisci un dato valido: ");
        scanf("%c", &array[posizione].day);
    }
    //mese   ------
    printf("Inserisci Mese di Nascita: ");
    scanf("%c", &array[posizione].month);
    while(month<1 || month>12)
    {
        printf("mese inesestinte, reinserisci un dato valido: ");
        scanf("%c", &array[posizione].month);
    }
    //anno ------
    printf("Inserisci Anno di Nascita: ");
    scanf("%c", &array[posizione].year);

}

void add_element(persona array[], int* ptr_n) //riceve l'array di persona e il putatore a n che rappresenta la prima posizione libera
{
    if(*ptr_n > 99)
    {
        printf("Rubrica Piena");
    }
    else
    {
        inserimento(array, *ptr_n,0);
        //incremento di n, per ricordare qual'è la prossima posiozione libera
        *ptr_n += 1;
    }
    
}

void del_element(persona array[n], int* ptr_n)
{
    printf("Quale numero vuoi eliminare? ");
    unsigned long int pn;
    scanf("%lu", &pn);
    int flag=-1;
    //pn che è il numero di telefono che devi cercare nell'array 
    //ricerca nell'array:
    for(int i = 0; i < *ptr_n; i++)
    {
        //confronta 
        if(pn == array[i].phonenumber)
        {
            flag=i; //se troiva il numero 
            
            break; //esce dal for 
        }

    }
    if(flag == -1)
    {
        printf("Numero non trovato");
    }    
    else
    {
        for(int i = flag+1; i<*ptr_n; i++)
        {

        }
    }
}

void edt_element(persona array[], int* ptr_n)
{
    printf("Quale numero vuoi modificare? ");
    unsigned long int pn;
    scanf("%lu", &pn);
    int flag=-1;
    //pn che è il numero di telefono che devi cercare nell'array 
    //ricerca nell'array:
    for(int i = 0; i < *ptr_n; i++)
    {
        //confronta 
        if(pn == array[i].phonenumber)
        {
            flag=i; //se troiva il numero 
            
            break; //esce dal for 
        }

    }
    if(flag == -1)
    {
        printf("Numero non trovato");
    }    
    else
    {
        inserimento(array, flag, 1);
    }
    //se fuori dal for il flag è ancora a -1: non ha trovato il numero 
    //se il flag è diverso da -1 ha trovato il numero e corrisponde ad flag

}

void src_element_by_name()
{

}

void src_element_by_surname()
{

}

int main(void)
{
    persona rubrica[MAX]; // array di 100 struct di tipo persona
    int n = 0; // n rappresenta la prima posizione libera
    int opt=0;
    for(;;) //programma di looop del menu
    {
        //stampare menu
        system("cls");
        printf("\nHOME");
        printf("\nOpzione 1: Aggiungi nuovo numero");
        printf("\nOpzione 2: Elimina numero");
        printf("\nOpzione 3: Modifica numero");
        printf("\nOpzione 4: Cerca Numero per nome");
        printf("\nOpzione 5: Cerca Numero per cognome");
        printf("\nOpzione 0: ESCI");


        //scegliere l'opzione
        printf("\n\n\nopzione: ");
        scanf("%d", &opt);

        while(opt<0 || opt>5)
        {
            printf("\nopzione %d sconosciuta, immetti un'opzione presente nel menu: ", opt);
            scanf("%d", &opt);
        }
        short int flag = 0;
        //opzione di uscita  con break;
        switch (opt)
        {
        case 0:
            flag = 1;
            break;

        case 1:

            add_element(rubrica, &n); // richiamo a funzione aggiungi elemnto

            break;


        }
        if (flag == 1)
            break;
    }
    system("cls");
    printf("\n\nProgramma terminato");
    return 0;
}




