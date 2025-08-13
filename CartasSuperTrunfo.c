#include <stdio.h>
#include <string.h>

struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao; 
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    int opcao;

    // ===== Entrada Carta 1 =====
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0'; // remove \n
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
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0'; // remove \n
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

    // ===== Menu de Comparação =====
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("6. PIB per Capita\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO =====\n");

    switch (opcao) {
        case 1: // População
            printf("Comparando Populacao:\n");
            printf("%s: %lu\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %lu\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Comparando Area:\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Comparando Pontos Turisticos:\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomeCidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade Demográfica (menor vence)
            printf("Comparando Densidade Demografica:\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, densidade1);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, densidade2);
            if (densidade1 < densidade2)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (densidade2 < densidade1)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 6: // PIB per Capita
            printf("Comparando PIB per Capita:\n");
            printf("%s: %.2f R$/hab\n", carta1.nomeCidade, pibPerCapita1);
            printf("%s: %.2f R$/hab\n", carta2.nomeCidade, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2)
                printf("Vencedor: %s\n", carta1.nomeCidade);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("Vencedor: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

    return 0;
}


