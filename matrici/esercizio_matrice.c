/**
 * @file esercizio_matrice.c
 * @description 
 * @author Lombardi Michele 
 */



/*
Scrivere un porgramma in c per effetutuare le seguneti funzinoi:

inserire i valori da tastiera nella prima riga di una matrice composta da 3 righe e 10 colonne 
inserire altri valori nell seconda riga  della stessa matrice, 
poi calcolare la somma della prima riga con la seconda riga scrivendo il risultato colonna per colonna nella terza riga

stampare l'intera matrice (CONSIGLIO ciclo for annidato)
*/



//costanti
#define COL 10
#define ROW 3

int main(void)
{
    int matrice[ROW][COL];


    //INSERIMENTO DATI 
    printf("Valori Prima righa:\n");
    for (int i=0; i<COL; i++) //PRIMA RIGA 
    {
        printf("Val %d: ", i+1);
        scanf("%d", &matrice[0][i]);
    }

    printf("Valori Seconda righa:\n");
    for (int i=0; i<COL; i++) //SECONDA RIGA
    {
        printf("Val %d: ", i+1);
        scanf("%d", &matrice[1][i]);
    }


    //ELABORAZIONE DATI 
    for(int i=0; i<COL; i++)
    {
      matrice[2][i]=matrice[1][i]+matrice[0][i];  
    }
    /* COSA FA IL CICLO FOR :
    matrice[2][0]=matrice[1][0]+matrice[0][0];
    matrice[2][1]=matrice[1][1]+matrice[0][1];
    matrice[2][2]=matrice[1][2]+matrice[0][2];
    ...
    matrice[2][9]=matrice[1][9]+matrice[0][9];
    */


    //STAMPA MATRICE
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    /*matrice[0][0]
    matrice[0][1]
    ...
    matrice[0][9]

    matrice[1][0]
    matrice[1][1]
    ...
    matrice[1][9]

    matrice[2][0]
    matrice[2][1]
    ...
    matrice[2][9]*/

}