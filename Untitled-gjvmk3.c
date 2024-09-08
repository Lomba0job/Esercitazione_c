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
        paux->media = s/N_MATERIE;
        paux = paux->next;
    }
}


void ordinapermedia(ptr_studente head)
{
    if (head == NULL) return;

    ptr_studente i, j;
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->media < j->media) // Confronta le medie
            {
                // Scambia solo i contenuti (dati dello studente) tra i nodi
                // Scambio di nome
                char temp_nome[STR_LEN+1];
                strcpy(temp_nome, i->nome);
                strcpy(i->nome, j->nome);
                strcpy(j->nome, temp_nome);

                // Scambio di cognome
                char temp_cognome[STR_LEN+1];
                strcpy(temp_cognome, i->cognome);
                strcpy(i->cognome, j->cognome);
                strcpy(j->cognome, temp_cognome);

                // Scambio dei voti
                int temp_voti[N_MATERIE];
                for (int k = 0; k < N_MATERIE; k++)
                {
                    temp_voti[k] = i->voto[k];
                    i->voto[k] = j->voto[k];
                    j->voto[k] = temp_voti[k];
                }

                // Scambio della media
                float temp_media = i->media;
                i->media = j->media;
                j->media = temp_media;
            }
        }
    }
}


void stampalistaordinata(ptr_studente head)
{
    ptr_studente paux = head;
    while(paux != NULL)
    {
        printf("%s %s, media: %f", paux->nome, paux->cognome, paux->media);
        paux = paux->next;
    }
}

void test(void)
{
    // Redirige lo stream di input al file "input.txt"
    freopen("input.txt", "r", stdin);

    ptr_studente head = NULL;

    // Inserimento studenti utilizzando scanf come se leggesse da tastiera
    while (!feof(stdin))
    {
        head = inserisci_studente(head); // Usa allocadato che ha già scanf
    }

    // Calcolo la media
    calcolamedia(head);

    // Ordino la lista degli studenti per media
    ordinapermedia(head);

    // Stampo la lista ordinata
    printf("Lista ordinata per media:\n");
    stampalistaordinata(head);

    // Ripristina stdin a quello standard (tastiera) se necessario
    freopen("/dev/tty", "r", stdin);
}

void verifica_ordine_output(ptr_studente head)
{
    FILE *file_atteso = fopen("risulta.txt", "r");
    if (file_atteso == NULL)
    {
        printf("Errore nell'apertura del file risulta.txt!\n");
        return;
    }

    char nome_atteso[STR_LEN+1];
    char cognome_atteso[STR_LEN+1];
    float media_attesa;
    ptr_studente paux = head;
    int posizione = 1;

    // Leggi da "risulta.txt" e confronta con la lista
    while (fscanf(file_atteso, "%s %s %f", nome_atteso, cognome_atteso, &media_attesa) == 3)
    {
        if (paux == NULL)
        {
            printf("Errore: la lista ha meno studenti del file risulta.txt!\n");
            break;
        }

        // Confronto nome, cognome e media
        if (strcmp(paux->nome, nome_atteso) == 0 && strcmp(paux->cognome, cognome_atteso) == 0 && abs(paux->media - media_attesa) < 0.001)
        {
            printf("Posizione %d corretta: %s %s, media: %f\n", posizione, paux->nome, paux->cognome, paux->media);
        }
        else
        {
            printf("Errore in posizione %d: atteso %s %s, media: %f, trovato %s %s, media: %f\n", 
                    posizione, nome_atteso, cognome_atteso, media_attesa, paux->nome, paux->cognome, paux->media);
        }

        paux = paux->next;
        posizione++;
    }

    // Se la lista ha più studenti del file risulta.txt
    if (paux != NULL)
    {
        printf("Errore: la lista ha più studenti del file risulta.txt!\n");
    }

    fclose(file_atteso);
}

void test(void)
{
    // Redirige lo stream di input al file "input.txt"
    freopen("input.txt", "r", stdin);

    ptr_studente head = NULL;

    // Inserimento studenti utilizzando scanf come se leggesse da tastiera
    while (!feof(stdin))
    {
        head = inserisci_studente(head); // Usa allocadato che ha già scanf
    }

    // Calcolo la media
    calcolamedia(head);

    // Ordino la lista degli studenti per media
    ordinapermedia(head);

    // Stampo la lista ordinata
    printf("Lista ordinata per media:\n");
    stampalistaordinata(head);

    // Verifica che l'ordine dei nomi e delle medie corrisponda a quello del file risulta.txt
    verifica_ordine_output(head);

    // Ripristina stdin a quello standard (tastiera)
    freopen("/dev/tty", "r", stdin);
}

int main(void)
{
    test();
}
