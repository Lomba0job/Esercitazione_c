/**
 * @file esercizio_funzione_semplice.c
 * @description Primo eserciizo utilizzando le funzioni
 * @author Lombardi Michele
 */

/*
Funzione di count down
*/

#include <stdio.h>

void countdown(int a)
{
    for (int i=a; i>=0; i--)
    {
        printf("%d\n", i);
    }
    return;
}

int main (void)
{
    int b;
    printf("value: ");
    scanf("%d", &b);
    countdown(b);
}
