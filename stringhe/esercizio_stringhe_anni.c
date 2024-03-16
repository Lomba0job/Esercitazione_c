#include <stdio.h>
#include <time.h>

int main(void)
{
    char str1[5], str2[5];
    int anno_n, anno_c, anni;

    printf("In che anno sei nato? ");
    scanf("%s", str1);
    anno_n = atoi(str1);

    printf("Anno corrente? ");
    scanf("%s", str2);
    anno_c = atoi(str2);

    printf("\nHai %d anni", anno_c-anno_n);
}
