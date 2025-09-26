#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5   // tamanho fixo das matrizes de habilidade

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // água
        }
    }
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // área de efeito
            }
        }
        printf("\n");
    }
}

// ---------------- Matrizes de Habilidade ----------------

// Cone: expande de cima para baixo
void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE/2 - i) && j <= (TAM_HABILIDADE/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Cruz: linha vertical e horizontal passando pelo centro
void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Octaedro: forma de losango (distância Manhattan do centro)
void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// ---------------- Função para aplicar habilidades no tabuleiro ----------------

void aplicarHabilidade(
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
    int origemLinha, int origemColuna
) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colTab   = origemColuna + (j - centro);

                // Validação para não sair do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
                    colTab >= 0 && colTab < TAM_TABULEIRO) {
                    
                    // Marca área de efeito (não sobrescreve navio)
                    if (tabuleiro[linhaTab][colTab] != 3) {
                        tabuleiro[linhaTab][colTab] = 5;
                    }
                }
            }
        }
    }
}

// ---------------- Programa Principal ----------------

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona manualmente alguns navios
    tabuleiro[2][2] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[8][8] = 3;

    // Cria matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro em pontos diferentes
    aplicarHabilidade(tabuleiro, cone, 1, 5);      // cone perto do topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // octaedro canto inferior esquerdo

    // Exibe tabuleiro final
    printf("=== TABULEIRO COM HABILIDADES ===\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}