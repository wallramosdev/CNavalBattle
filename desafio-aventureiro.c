#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === POSICIONAMENTO DOS NAVIOS COM VALIDAÇÃO ===

    // --- Navio horizontal (linha 3, colunas D–F)
    int linha_horizontal = 2;      // Linha 3 (índice 2)
    int coluna_horizontal = 3;     // Coluna D (índice 3)
    int pode_colocar = 1;

    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
            }
        }
    } else {
        pode_colocar = 0;
    }

    if (!pode_colocar) {
        printf("Erro: Não foi possível posicionar o navio horizontal (linha 3, colunas D–F).\n");
        return 1;
    }

    // --- Navio vertical (coluna H, linhas 6–8)
    int linha_vertical = 5;        // Linha 6 (índice 5)
    int coluna_vertical = 7;       // Coluna H (índice 7)
    pode_colocar = 1;

    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        }
    } else {
        pode_colocar = 0;
    }

    if (!pode_colocar) {
        printf("Erro: Não foi possível posicionar o navio vertical (coluna H, linhas 6–8).\n");
        return 1;
    }

    // --- Navio diagonal (B6 - D8)
    int linha_diag1 = 5;
    int coluna_diag1 = 1;
    pode_colocar = 1;

    if (linha_diag1 + TAMANHO_NAVIO <= TAMANHO && coluna_diag1 + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag1 + i][coluna_diag1 + i] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_diag1 + i][coluna_diag1 + i] = NAVIO;
            }
        }
    } else {
        pode_colocar = 0;
    }

    if (!pode_colocar) {
        printf("Erro: Não foi possível posicionar o navio diagonal (B6 - D8).\n");
        return 1;
    }

    // --- Navio diagonal (F4 - D6)
    int linha_diag2 = 3;
    int coluna_diag2 = 5;
    pode_colocar = 1;

    if (linha_diag2 + TAMANHO_NAVIO <= TAMANHO && coluna_diag2 - (TAMANHO_NAVIO - 1) >= 0) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag2 + i][coluna_diag2 - i] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_diag2 + i][coluna_diag2 - i] = NAVIO;
            }
        }
    } else {
        pode_colocar = 0;
    }

    if (!pode_colocar) {
        printf("Erro: Não foi possível posicionar o navio diagonal (F4 - D6).\n");
        return 1;
    }

    // === IMPRESSÃO DO TABULEIRO ===
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
