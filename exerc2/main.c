#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100], letra;
    int i, contador = 0;

    printf("Informe uma palavra: ");
    scanf(" %s", palavra);

    printf("Informe uma letra:");
    scanf("%c", &letra); // Espaço antes de %c para limpar o buffer

    for(i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] == letra){
            contador++;
        }
    }

    printf("Qtde: %D\n", contador);

    return 0;
}
