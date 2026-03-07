#include <stdio.h>
#include <string.h>

int main(){
    char palavra[50], substituto;
    int i, vogais = 0;

    printf("Digite uma palavra:");
    scanf("%s", palavra);

    printf("Digite o caractere substituto: ");
    printf("%c", &substituto); // o espaço antes de %c limpa o buffer

    // conta vogais e faz a substituição
    for(i = 0; palavra[i] != '\0'; i++){
        char c = palavra[i];
        if(c=='a'|| c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            vogais++;
            palavra[i] = substituto;
        }
    }

    printf("\nA palavra original tinha %d vogais.\n", vogais);
    printf("Nova palavra: %s\n", palavra);

    return 0;
}
