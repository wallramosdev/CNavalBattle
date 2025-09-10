#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição fixa do navio horizontal (linha 2, colunas 4–6)
    int linha_horizontal = 2;      // Linha 3 (índice 2)
    int coluna_horizontal = 3;     // Coluna D (índice 3)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posição fixa do navio vertical (coluna 1, linhas 5–7)
    int linha_vertical = 5;        // Linha 6 (índice 5)
    int coluna_vertical = 7;       // Coluna H (índice 7)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Imprime título
    printf("\n=== Tabuleiro Batalha Naval em C ===\n\n");

    // Imprime cabeçalho das colunas (A a J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf(" %c ", letra);
    }
    printf("\n");

    // Imprime linhas com índice numérico
    for (i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Número da linha (1 a 10)
        for (j = 0; j < TAMANHO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
