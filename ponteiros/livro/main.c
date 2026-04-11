#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validarISBN(char *isbn) {
    int s1 = 0, s2 = 0;
    int contador_digitos = 0;
    char *ptr = isbn;

    while (*ptr != '\0') {
        if (*ptr != '-') {
            int valor;

            if (contador_digitos == 9 && (*ptr == 'X' || *ptr == 'x')) {
                valor = 10;
            } else if (isdigit(*ptr)) {
                valor = *ptr - '0';
            } else {
                ptr++;
                continue;
            }

            s1 += valor;
            s2 += s1;
            contador_digitos++;
        }
        ptr++;
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
        if (strcmp(entrada, "FIM") == 0 || strcmp(entrada, "fim") == 0) {
            break;
        }

        validarISBN(entrada);
    }

    return 0;
}
