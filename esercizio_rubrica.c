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
typedf struct   
{
    char p_name[10], p_surname[20], factory[15];
    short int day, month, year;
    long int phonenumber;
}persona;

add_element()
{

}

del_element()
{

}

edt_element()
{

}

src_element_by_name()
{
    
}

src_element_by_surname()
{
    
}

int main(void)
{
    persona rubrica[MAX]; // array di 100 struct di tipo persona 


    for(;;) //programma di looop del menu
    {
        int opt;
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
        scanf("%d", opt);

        while(opt>=0 && opt<=5)
        {
            printf("\nopzione sconosciuta, immetti un'opzione presente nel menu: ");
            scanf("%d", opt);
        }
        short int flag = 0;
        //opzione di uscita  con break;
        switch (opt)
        {
        case 0:
            flag = 1;
            break;
        
        
        }
        if (flag == 1)
            break;
    }
    system("cls");
    printf("\n\nProgramma terminato");
    return 0;
}