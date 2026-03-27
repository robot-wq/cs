#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    int i, primeiroespaco = -1, ultimoespaco = -1;

    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nome);

    int tamanho = strlen(nome);

    for (i = 0; i < tamanho; i++) {
        if (nome[i] == ' ') {
            primeiroespaco = i;
            break;
        }
    }

    for (i = tamanho - 1; i >= 0; i--) {
        if (nome[i] == ' ') {
            ultimoespaco = i;
            break;
        }
    }

    printf("Primeiro nome: ");
    for (i = 0; i < primeiroespaco; i++) {
        printf("%c", nome[i]);
    }

    printf("\nUltimo nome: ");
    for (i = ultimoespaco + 1; i < tamanho; i++) {
        printf("%c", nome[i]);
    }

    return 0;
}
