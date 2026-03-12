#include <stdio.h>
#include "string.h"

int main (){

    char str1 [21], str2 [21];
    int inicio, fim;

    printf("Informe uma string \n");
    scanf("%[^\n]", str1);

    printf("\nInforme o inicio: ");
    scanf("i%", &inicio);

    printf("\nInforme o fim: ");
    scanf("%i", &fim);


    substring(str1, str2, inicio, fim);

    printf("\nSub: %s", str2);
}
