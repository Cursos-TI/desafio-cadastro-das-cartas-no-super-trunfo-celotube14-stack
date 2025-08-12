#include <stdio.h>

struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao; // Suporta números muito grandes
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // ===== Entrada Carta 1 =====
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // ===== Entrada Carta 2 =====
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // ===== Cálculos obrigatórios =====
    densidade1 = carta1.populacao / carta1.area;
    densidade2 = carta2.populacao / carta2.area;

    pibPerCapita1 = (carta1.pib * 1000000000.0) / carta1.populacao;
    pibPerCapita2 = (carta2.pib * 1000000000.0) / carta2.populacao;

    // ===== Comparação pelo atributo fixo: Área =====
    printf("\n===== Comparacao de Cartas (Atributo: Area) =====\n");
    printf("Carta 1 - %sArea: %.2f km²", carta1.nomeCidade, carta1.area);
    printf("Carta 2 - %sArea: %.2f km²", carta2.nomeCidade, carta2.area);

    if (carta1.area > carta2.area) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.area > carta1.area) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate! Ambas as cartas têm a mesma area.\n");
    }

    return 0;
}


