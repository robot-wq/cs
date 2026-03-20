#include <stdio.h>
#include <string.h>

void descriptografar(char *texto, int chave) {
    for(int i = 0; texto[i] != '\0'; ++i) {
        // Subtrai a chave para reverter o deslocamento
        texto[i] = texto[i] - chave;
    }
}

int main() {
    char texto[] = "Khoor#Zruog"; // String criptografada ("Hello World" + 3)
    int chave = 3;

    printf("String criptografada: %s\n", texto);

    descriptografar(texto, chave);

    printf("String descriptografada: %s\n", texto);

    return 0;
}
