/**
 * @file esercizio_puntatori.c
 * @description
 * @author
 */

/*
Esercizio per trovare il numero più grande e più piccolo tra tre numeri

utilizzare solo variabili locali
e utilizzare una funzione: ordinamento a cui passi i puntatori e non restituiscce niente
stampare il primo e ultimo numero

*/

void ordinamento(int* v1, int* v2, int* v3);


int main(void)
{
    int numero1=5;
    int numero2=9;
    int numero3=2;


    ordinamento(&numero1, &numero2, &numero3);
    printf("%d, %d, %d", numero1, numero2, numero3);

}

void ordinamento(int* v1, int* v2, int* v3)
{
    int a = *v1;
    int b = *v2;
    int c = *v3;



    if(a>b)
    {
        if(a>c)
        {
            if(b>c)
            {
                // a b c
            }
            else
            {
                // a c b
                *v2=c;
                *v3=b;
            }
        }
        else
        {
            // c a b
            *v1=c;
            *v2=a;
            *v3=b;
        }
    }
    else
    {
        if(b>c)
        {
            if(c>a)
            {
                // b c a
                *v1=b;
                *v2=c;
                *v3=a;
            }
            else
            {
                // b a c
                *v1=b;
                *v2=a;
                *v3=c;
            }
        }
        else
        {
            // c b a
            *v1=c;
            *v2=b;
            *v3=a;
        }
    }
}
