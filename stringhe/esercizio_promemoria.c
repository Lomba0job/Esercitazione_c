/**
 * @file esercizio_promemoria.c
 * @description 
 * @author Antonello Carbonara
 */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+1]; // sembra una matrice ma è un array di string la seconda posizione la usiamo per  i caratteri della stringa
    char day_str[3], msg_str[MSG_LEN+1];
    int ch, day, i, j, num_remind = 0;

    for(;;)
    {
        if(num_remind == MAX_REMIND)
        {
            printf("--NO SPACE LEFT--\n");
            break;
        }
        printf("Enter a day reminder: ");
        scanf("%2d", &day); // salvare il giorno 

        if (day == 0) //se è zero uscire dal loop infinito per stampa risultati 
            break;

        sprintf(day_str, "%2d", day); // salvare sulla stringa day_str la stringa derivata da day in 2 spazi 
        i=0;

        while ((ch = getchar()) != '\n') //legge i promemoria finchè non c'è un a capo con \n anche gli spazi 
        {
            if (i < MSG_LEN) // se i ancora sta ancora nella dimensione massima della stringa 
                msg_str [i++] = ch; // salva il carattere nella relativa posizione 
        }

        msg_str [i] = '\0'; // aggiungi l' end line della stringa 

        for (i = 0; i < num_remind; i++) // scorri l'array per quanti numeri sono attualmemte salvati 
        {
            if (strcmp(day_str, reminders[i]) < 0) //compara il day string con il reminder nella posizione attuale se è minore esci 
                break;
        }

        for (j = num_remind; j > i; j--) // scorri al contrario fino a maggiore di i che è il punto di uscita dal for precedente 
        {
            strcpy(reminders[j], reminders[j-1]); // copia la stringa in posizione attuale con quella nella posizione precedente 
        }
        strcpy(reminders[i], day_str); // quando a finito ci sarà un buco nell'array dove inseriremo day str 
        strcat(reminders[i], msg_str); // concateniamo anche il reminder 
        num_remind++; // incrementiamo il numero di promeria salvati 
    }

    printf("\nDay Reminder\n"); // stampa tutto (caso inserito 0 come giorno )
    for (i = 0; i < num_remind; i++) // scorri l'array fino alla poszione dell unltimo promemoria salvato 
        printf(" %s\n", reminders[i]); // stampa il relativo promemoria 
    return 0;


}