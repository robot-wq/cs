#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validarISBN(char *isbn) {
    int s1 = 0, s2 = 0;
    char *p = isbn;
    int contador_digitos = 0;

    // Processa a string usando notação de ponteiro
    while (*p != '\0') {
        if (*p != '-') { // Ignora hífens
            int valor;

            if (contador_digitos == 9 && (*p == 'X' || *p == 'x')) {
                valor = 10;
            } else if (isdigit(*p)) {
                valor = *p - '0';
            } else {
                p++;
                continue; // Ignora caracteres inválidos
            }

            s1 += valor;
            s2 += s1;
            contador_digitos++;
        }
        p++;
    }

    if (s2 % 11 == 0) {
        printf("ISBN %s é válido\n", isbn);
    } else {
        printf("ISBN inválido: %d\n", s2 % 11);
    }
}

int main() {
    char entrada[20];

    while (1) {
        printf("Informe o ISBN (ou 'FIM' para sair): ");
        scanf("%s", entrada);

        // Verifica condição de parada
        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        validarISBN(entrada);
    }

    return 0;
}
