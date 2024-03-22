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
    char reminders[MAX_REMIND][MSG_LEN+1];
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
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        i=0;
    }

}