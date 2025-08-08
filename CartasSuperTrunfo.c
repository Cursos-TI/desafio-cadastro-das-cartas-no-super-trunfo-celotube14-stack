#include <stdio.h>

struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao; // Agora suporta números muito grandes
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

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
    printf("Cadastro da Carta 2:\n");
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

    // ===== Cálculos =====
    densidade1 = carta1.populacao / carta1.area;
    densidade2 = carta2.populacao / carta2.area;

    pibPerCapita1 = (carta1.pib * 1000000000.0) / carta1.populacao;
    pibPerCapita2 = (carta2.pib * 1000000000.0) / carta2.populacao;

    superPoder1 = (float)carta1.populacao + carta1.area + carta1.pib +
                  carta1.pontosTuristicos + pibPerCapita1 + (1.0 / densidade1);

    superPoder2 = (float)carta2.populacao + carta2.area + carta2.pib +
                  carta2.pontosTuristicos + pibPerCapita2 + (1.0 / densidade2);

    // ===== Comparações =====
    printf("\n\nComparacao de Cartas:\n");

    printf("Populacao: Carta %d venceu (%d)\n",
           carta1.populacao > carta2.populacao ? 1 : 2,
           carta1.populacao > carta2.populacao ? 1 : 0);

    printf("Area: Carta %d venceu (%d)\n",
           carta1.area > carta2.area ? 1 : 2,
           carta1.area > carta2.area ? 1 : 0);

    printf("PIB: Carta %d venceu (%d)\n",
           carta1.pib > carta2.pib ? 1 : 2,
           carta1.pib > carta2.pib ? 1 : 0);

    printf("Pontos Turisticos: Carta %d venceu (%d)\n",
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2,
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 0);

    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           densidade1 < densidade2 ? 1 : 2, // menor vence
           densidade1 < densidade2 ? 1 : 0);

    printf("PIB per Capita: Carta %d venceu (%d)\n",
           pibPerCapita1 > pibPerCapita2 ? 1 : 2,
           pibPerCapita1 > pibPerCapita2 ? 1 : 0);

    printf("Super Poder: Carta %d venceu (%d)\n",
           superPoder1 > superPoder2 ? 1 : 2,
           superPoder1 > superPoder2 ? 1 : 0);

    return 0;
}


