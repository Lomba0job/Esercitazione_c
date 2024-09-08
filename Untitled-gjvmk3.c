//definizone delle librerie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//definizioni delle costanti
#define ita 0
#define mat 1
#define ing 2

#define N 20
#define N_MATERIE 3 //aggiunta io perchè sono stornzo

#define STR_LEN 30


//definuzione della struttura studente
/*
typedef struct{
    char nome[STR_LEN+1];       //allocazione di una stringa di lunghezza STR_LEN +1
    char cognome[STR_LEN+1];    //allocazione di una stringa di lunghezza STR_LEN +1
    int voto[N_MATERIE];                //allocazione di un'array di 3 elementi
} studente;

*/
//Modo equivalente:

struct studentestruct
{
    char nome[STR_LEN+1];
    char cognome[STR_LEN+1];
    int voto[N_MATERIE];
    float m;
    struct studentestruct * next;
};

typedef struct studentestruct studente;
typedef studente * ptr_studente;

ptr_studente allocadato(void)
{
    ptr_studente paux;
    paux = (ptr_studente)malloc(sizeof(studente));

    //printf("Nome? ");
    scanf("%s", paux->nome);
    //printf("Cognome? ");
    scanf("%s", paux->cognome);
    for(int i=0; i<N_MATERIE; i++)
    {
        //printf("Voto %d? ", i+1);
        scanf("%d", &paux->voto[i]);
    }
    paux->next = NULL;
    return paux;
}

ptr_studente inserisci_studente(ptr_studente head)
{
    ptr_studente paux = head;

    if(head != NULL)
    {
        while(paux->next != NULL)
        {
            paux = paux->next;
        }
        paux->next = allocadato();
    }else
    {
        //insiresci la prima
        head = allocadato();
    }
    return head;
}

void calcolamedia(ptr_studente head)
{
    //printf("calcolo media...\n");

    ptr_studente paux = head;
    while(paux != NULL)
    {
        float s=0;
        for(int i=0; i<N_MATERIE; i++)
        {
            s += paux->voto[i];
        }
        printf("la media di %s %s corrisponde a %.2f: \n", paux->nome, paux->cognome, s/N_MATERIE);
        paux = paux->next;
    }
}

void test_calcolo_medie() {
    // Simuliamo l'input da tastiera usando freopen
    freopen("input_test.txt", "r", stdin);  // Redirige l'input standard da un file

    // Redirige l'output standard su un file
    freopen("output_test.txt", "w", stdout);

    // Richiama la logica del programma principale
    ptr_studente head = NULL;
    for(int i = 0; i < N; i++) {
        head = inserisci_studente(head);
    }
    calcolamedia(head);

    // Ripristina stdin e stdout
    freopen("/dev/tty", "r", stdin); // Torna a utilizzare l'input standard da tastiera
    freopen("/dev/tty", "w", stdout); // Torna a utilizzare l'output standard su schermo

    // Verifica l'output generato
    FILE *f = fopen("output_test.txt", "r");
    char output[256];

    // Lettura dell'output e verifica
    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Mario Rossi corrisponde a 8.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Luca Verdi corrisponde a 7.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Anna Bianchi corrisponde a 8.67") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Giulia Ferrari corrisponde a 7.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Paolo Conti corrisponde a 9.33") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Marco DeLuca corrisponde a 6.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Sara Ricci corrisponde a 8.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Laura Bianchi corrisponde a 7.33") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Stefano Romano corrisponde a 7.00") != NULL);

    fgets(output, sizeof(output), f);
    assert(strstr(output, "la media di Federica Moretti corrisponde a 10.00") != NULL);

    printf("Test passed: Le medie sono corrette!\n");

    fclose(f);
}


int main(void)
{

    /*
    //MODELLO LOCALE  ACCESSO DIRETTO
    studente classe[N]; //dichairazione di un array di strutture lungo N (constante)

    float m;        //allocazione variabile float
    int i; int j;   //allocazione variabili intere


    //lettura dati
    //tramite l' utilizzo di due cicli for annidati

    for(i=0;i<N; i++)   //per ogni elemento dell array
    {
        scanf(“%STR_LENs”, classe[i].nome);         //salva nome (%STR_LENs equivale a %30s -> il che salva sempre una stringa di 30 caratteri inserendo spazi o troncando se necessario)
        scanf(“%STR_LENs”, classe[i].cognome);      //salva cognome (%STR_LENs equivale a %30s -> il che salva sempre una stringa di 30 caratteri inserendo spazi o troncando se necessario)
        for(j=ita; j<=ing; j++)             //for j che parte dalla prima materia fino all' ultima
            scanf( "%d", &classe[i].voto[j]);       //inserisci il voto nell'array interno della struttura nella posizione di quella materia
    }


    //stampa delle medie
    //calcolo anch'esso effettuato tramite due cicli for annidati

    for( i=0; i<N; i++ )            //per ogni struttura nell'array
    {
        for( m=0,j=ita; j<=ing; j++ )   //per ogni materia (ita la prima, ing l'ultima)
            m += classe[i].voto[j];         //incrementa m aggiungendo il voto dello studente

        printf( "media di %s %s: %f\n", classe[i].nome, classe[i].cognome, m/N_MATERIE ); //stampa la media dello studente
    }

    */

    //MODELLO LOCALE ACCESSO A PUNTATORE CON LISTA
    test_calcolo_medie();

}
