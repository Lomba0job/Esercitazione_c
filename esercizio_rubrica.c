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

/*
PARTE DUE AGGIUNGERE IL SESSO DEL UTENTE

    funzione stampa tutti i maschi
    funzione stampa tutte le femmine

*/

#include <stdio.h>
#include <string.h>

#define MAX 100
typedef struct
{
    char p_name[10], p_surname[20], p_gender, factory[35];
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
    scanf("%s", &array[posizione].p_name);
    //cognome ------
    printf("Inserisci Cognome: ");
    scanf("%s", &array[posizione].p_surname);
    //sesso ------
    printf("Inserisci Genere (M/F): ");
    scanf(" %c", &array[posizione].p_gender);
    while (array[posizione].p_gender != 'M' && array[posizione].p_gender != 'F')
    {
        printf("%c Genere non valido, inserisci M o F: ",array[posizione].p_gender);
        scanf(" %c", &array[posizione].p_gender);
    }
    //società ------
    printf("Inserisci Società: ");
    scanf("%s", &array[posizione].factory);
    //giorno   ------
    printf("Inserisci Giorno di Nascita: ");
    scanf("%hu", &array[posizione].day);
    while(array[posizione].day<1 || array[posizione].day>31)
    {
        printf("giorno inesestinte, reinserisci un dato valido: ");
        scanf("%hu", &array[posizione].day);
    }
    //mese   ------
    printf("Inserisci Mese di Nascita: ");
    scanf("%hu", &array[posizione].month);
    while(array[posizione].month<1 || array[posizione].month>12)
    {
        printf("mese inesestinte, reinserisci un dato valido: ");
        scanf("%hu", &array[posizione].month);
    }
    //anno ------
    printf("Inserisci Anno di Nascita: ");
    scanf("%hu", &array[posizione].year);

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

void del_element(persona array[], int* ptr_n)
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
            array[i-1] = array[i];
        }
        *ptr_n -= 1;
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

void stampa_elemento(persona pers)
{
    printf("\t%s\t%s\n", pers.p_name, pers.p_surname);
    printf("Numero: %lu\n", pers.phonenumber);
    printf("Data di Nascità: %hu\\%hu\\%hu\n", pers.day, pers.month, pers.year);
    printf("Società: %s\n\n", pers.factory);
}
void src_element_by_name(persona array[], int* ptr_n)
{
    printf("Quale nome vuoi modificare? ");
    char nome[10];
    scanf("%s", nome);

    //ricerca nell'array:
    for(int i = 0; i < *ptr_n; i++)
    {
        //confronta
        if(strcmp(nome, array[i].p_name) == 0)
        {
            stampa_elemento(array[i]);
        }

    }
}

void src_element_by_surname(persona array[], int* ptr_n)
{
    printf("Quale nome vuoi modificare? ");
    char cognome[20];
    scanf("%s", cognome);

    //ricerca nell'array:
    for(int i = 0; i < *ptr_n; i++)
    {
        //confronta
        if(strcmp(cognome, array[i].p_surname) == 0)
        {
            stampa_elemento(array[i]);
        }

    }
}
void attendi(void)
{
    char carattere[20];
    printf("\n\n\n\n SCRIVI \"si\" PER CONTINUARE");
    scanf(" %s", &carattere);
}

void ord_print(persona array[], int* ptr_n)
{
    for(int i = 0; i < *ptr_n-1; i++)
    {
        for ( int j  = i + 1; j < *ptr_n; j++)
        {
            if(strcmp(array[i].p_name, array[j].p_name) > 0)
            {
                //scambio
                persona temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }
        }
    }

    //stanpaare tutti gli elementi
    for(int i = 0; i < *ptr_n; i++)
    {
        stampa_elemento(array[i]);
    }

}

void print_m(persona array[], int* ptr_n)
{
    //stanpaare tutti gli elementi
    for(int i = 0; i < *ptr_n; i++)
    {
        if(array[i].p_gender == 'M')
        stampa_elemento(array[i]);
    }

}

void print_f(persona array[], int* ptr_n)
{
    //stanpaare tutti gli elementi
    for(int i = 0; i < *ptr_n; i++)
    {
        if(array[i].p_gender == 'F')
        stampa_elemento(array[i]);
    }

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
        printf("\n\tHOME\n\n");
        printf("SALVATI %d NUMERI\n\n\n", n);
        printf("\tMenu Opzioni\n");
        printf("\nOpzione 1: Aggiungi nuovo numero");
        printf("\nOpzione 2: Elimina numero");
        printf("\nOpzione 3: Modifica numero");
        printf("\nOpzione 4: Cerca Numero per nome");
        printf("\nOpzione 5: Cerca Numero per cognome");
        printf("\nOpzione 6: Stampa tutti i numeri in ordine alfabetico per Nome");
        printf("\nOpzione 7: Stampa i maschi");
        printf("\nOpzione 8: Stampa le fighe");
        printf("\nOpzione 0: ESCI");



        //scegliere l'opzione
        printf("\n\n\nopzione: ");
        scanf("%d", &opt);

        while(opt<0 || opt>8)
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
            attendi();
            break;

        case 2:
            del_element(rubrica, &n); // richiamo a funzione aggiungi elemnto
            attendi();
            break;

        case 3:
            edt_element(rubrica, &n); // richiamo a funzione aggiungi elemnto
            attendi();
            break;

        case 4:
            src_element_by_name(rubrica, &n); // richiamo a funzione aggiungi elemnto
            attendi();
            break;

        case 5:
            src_element_by_surname(rubrica, &n); // richiamo a funzione aggiungi elemnto
            attendi();
            break;

        case 6:
            ord_print(rubrica, &n);
            attendi();
            break;

        case 7:
            print_m(rubrica, &n);
            attendi();
            break;

        case 8:
            print_f(rubrica, &n);
            attendi();
            break;


        }
        if (flag == 1)
            break;
    }
    system("cls");
    printf("\n\nProgramma terminato");
    return 0;
}




