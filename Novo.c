#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    // =========================
    // Cadastro das duas cartas
    // =========================

    Carta carta1 = {"São Paulo", "A01", "São Paulo", 12300000, 1521.11, 699000000000.0, 50, 0, 0};
    Carta carta2 = {"Rio de Janeiro", "B02", "Rio de Janeiro", 6000000, 1182.3, 450000000000.0, 40, 0, 0};

    // =========================
    // Cálculo de densidade e PIB per capita
    // =========================
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // =========================
    // Escolha do atributo para comparação
    // (fixo no código - exemplo: População)
    // =========================
    char atributoEscolhido[30] = "População";

    // =========================
    // Comparação e resultado
    // =========================
    printf("Comparação de cartas (Atributo: %s)\n\n", atributoEscolhido);

    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}