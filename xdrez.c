#include <stdio.h>

// -------------------------------
// Funções Recursivas
// -------------------------------

// Torre: movimento vertical simples (exemplo: para cima)
void moverTorre(int casas) {
    if (casas == 0) return; // caso base
    printf("Cima\n");
    moverTorre(casas - 1); // chamada recursiva
}

// Bispo: movimento diagonal (recursivo + loops aninhados)
void moverBispo(int casas) {
    if (casas == 0) return; // caso base

    // loop externo: movimento vertical
    for (int v = 0; v < 1; v++) {
        // loop interno: movimento horizontal
        for (int h = 0; h < 1; h++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // chamada recursiva
}

// Rainha: pode se mover como Torre (vertical) + Bispo (diagonal)
void moverRainha(int casas) {
    if (casas == 0) return; // caso base

    // Exemplo: primeiro movimento vertical
    printf("Cima\n");
    // depois movimento diagonal
    printf("Cima\n");
    printf("Direita\n");

    moverRainha(casas - 1); // chamada recursiva
}

// -------------------------------
// Cavalo com Loops Aninhados
// -------------------------------
void moverCavalo(int movimentos) {
    int cima = 2;    // duas casas para cima
    int direita = 1; // uma casa para direita

    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < cima; j++) {
            printf("Cima\n");
            if (j == cima - 1) continue; // só segue até o final
        }
        for (int k = 0; k < direita; k++) {
            printf("Direita\n");
            if (k == direita - 1) break; // encerra depois de mover para a direita
        }
    }
}

// -------------------------------
// Função Principal
// -------------------------------
int main() {
    int casas = 3;       // número de casas (para recursão)
    int movimentos = 2;  // número de movimentos do cavalo

    printf("Movimento da Torre:\n");
    moverTorre(casas);

    printf("\nMovimento do Bispo:\n");
    moverBispo(casas);

    printf("\nMovimento da Rainha:\n");
    moverRainha(casas);

    printf("\nMovimento do Cavalo:\n");
    moverCavalo(movimentos);

    return 0;
}



