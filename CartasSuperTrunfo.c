#include <stdio.h>

// Definição de uma estrutura para armazenar os dados da carta
struct CartaSuperTrunfo {
    char estado;
    char codigo[4]; // Ex: A01 (3 caracteres + '\0')
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    // Entrada de dados para a Carta 1
    printf("Cadastro da Carta 1:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpar o buffer
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);


    // Entrada de dados para a Carta 2
    printf("\nCadastro da Carta 2:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpar o buffer
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Impressão dos dados
    printf("\n\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);

    return 0;
}
