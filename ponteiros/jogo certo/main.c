#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> // Para a função Sleep()

// Protótipos das funções
void adicionar_numero(char *sequencia);
int testar_jogador(int num_jogador, char *sequencia, int *erro_pos);

int main() {
    char sequencia[100] = "";
    int rodada = 1;
    int ganhou = 0;
    int erro_posicao = -1;

    srand(time(NULL));

    printf("--- JOGO DA MEMORIA ---\n\n");

    while (1) {
        adicionar_numero(sequencia);

        // Vez do Jogador 1
        printf("Jogador 1, prepare-se...\n");
        Sleep(1000);
        printf("Memorize: %s\n", sequencia);
        Sleep(2000); // Exibe por 2 segundos
        system("cls || clear");

        if (!testar_jogador(1, sequencia, &erro_posicao)) {
            printf("\nJogador 1 errou!\n");
            ganhou = 2;
            break;
        }

        // Vez do Jogador 2
        printf("Jogador 2, prepare-se...\n");
        Sleep(1000);
        printf("Memorize: %s\n", sequencia);
        Sleep(2000);
        system("cls || clear");

        if (!testar_jogador(2, sequencia, &erro_posicao)) {
            printf("\nJogador 2 errou!\n");
            ganhou = 1;
            break;
        }

        rodada++;
        system("cls || clear");
    }

    // Resultado final
    printf("\n--- FIM DE JOGO ---\n");
    printf("Vencedor: Jogador %d\n", ganhou);
    printf("Total de casas memorizadas perfeitamente: %d\n", (int)strlen(sequencia) - 1);
    printf("O erro ocorreu na casa: %d (da esquerda para a direita)\n", erro_posicao + 1);

    return 0;
}

// Função para adicionar um número randômico ao final da string (notação ponteiro)
void adicionar_numero(char *sequencia) {
    int novo_num = rand() % 10;
    int tam = 0;

    // Encontra o fim da string usando ponteiro
    while (*(sequencia + tam) != '\0') {
        tam++;
    }

    *(sequencia + tam) = novo_num + '0'; // Converte int para char
    *(sequencia + tam + 1) = '\0';       // Finaliza a string
}

// Função para testar a memória do jogador (notação ponteiro)
int testar_jogador(int num_jogador, char *sequencia, int *erro_pos) {
    char tentativa[100];
    printf("Jogador %d, digite a sequencia: ", num_jogador);
    scanf("%s", tentativa);

    int i = 0;
    while (*(sequencia + i) != '\0') {
        if (*(tentativa + i) != *(sequencia + i)) {
            *erro_pos = i; // Armazena a posição do primeiro erro
            return 0;      // Errou
        }
        i++;
    }
    return 1; // Acertou
}
