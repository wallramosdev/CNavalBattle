#include <stdio.h>

#define TAMANHO 10
#define LARGURA 5
#define ALTURA 3

#define CONE 1
#define CRUZ 2
#define OCTAEDRO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linha_inicio, coluna_inicio, pode_colocar;

    // === POSICIONAMENTO DAS FORMAS ===

    // 1. CONE (3x5) começando na linha 0, coluna 2
    linha_inicio = 0;
    coluna_inicio = 2;
    pode_colocar = 1;

    if (linha_inicio + ALTURA <= TAMANHO && coluna_inicio + LARGURA <= TAMANHO) {
        // Verifica se o espaço está livre
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {
                if (j >= 2 - i && j <= 2 + i) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio + j] != 0) {
                        pode_colocar = 0;
                    }
                }
            }
        }

        // Se puder, posiciona
        if (pode_colocar) {
            for (i = 0; i < ALTURA; i++) {
                for (j = 0; j < LARGURA; j++) {
                    if (j >= 2 - i && j <= 2 + i) {
                        tabuleiro[linha_inicio + i][coluna_inicio + j] = CONE;
                    }
                }
            }
        } else {
            printf("Erro: Não foi possível posicionar o CONE.\n");
            return 1;
        }
    }

    // 2. CRUZ (3x5) começando na linha 4, coluna 2
    linha_inicio = 4;
    coluna_inicio = 2;
    pode_colocar = 1;

    if (linha_inicio + ALTURA <= TAMANHO && coluna_inicio + LARGURA <= TAMANHO) {
        // Verifica se o espaço está livre
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {
                if (i == 1 || j == 2) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio + j] != 0) {
                        pode_colocar = 0;
                    }
                }
            }
        }

        // Se puder, posiciona
        if (pode_colocar) {
            for (i = 0; i < ALTURA; i++) {
                for (j = 0; j < LARGURA; j++) {
                    if (i == 1 || j == 2) {
                        tabuleiro[linha_inicio + i][coluna_inicio + j] = CRUZ;
                    }
                }
            }
        } else {
            printf("Erro: Não foi possível posicionar a CRUZ.\n");
            return 1;
        }
    }

    // 3. OCTAEDRO (3x5) começando na linha 7, coluna 5
    linha_inicio = 7;
    coluna_inicio = 5;
    pode_colocar = 1;

    if (linha_inicio + ALTURA <= TAMANHO && coluna_inicio + LARGURA <= TAMANHO) {
        // Verifica se o espaço está livre
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {
                if (((i == 0 || i == 2) && j == 2) || (i == 1 && j >= 1 && j <= 3)) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio + j] != 0) {
                        pode_colocar = 0;
                    }
                }
            }
        }

        // Se puder, posiciona
        if (pode_colocar) {
            for (i = 0; i < ALTURA; i++) {
                for (j = 0; j < LARGURA; j++) {
                    if (((i == 0 || i == 2) && j == 2) || (i == 1 && j >= 1 && j <= 3)) {
                        tabuleiro[linha_inicio + i][coluna_inicio + j] = OCTAEDRO;
                    }
                }
            }
        } else {
            printf("Erro: Não foi possível posicionar o OCTAEDRO.\n");
            return 1;
        }
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
        printf("%2d ", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
