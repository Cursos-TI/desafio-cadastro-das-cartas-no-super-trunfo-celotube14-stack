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

float calcularAtributo(int opcao, struct CartaSuperTrunfo c) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.populacao / c.area; // densidade
        case 6: return (c.pib * 1000000000.0) / c.populacao; // PIB per capita
        default: return 0;
    }
}

void exibirNomeAtributo(int opcao) {
    switch (opcao) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
        case 6: printf("PIB per Capita"); break;
    }
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    int opcao1, opcao2;

    // ===== Entrada Carta 1 =====
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões R$): ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // ===== Entrada Carta 2 =====
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões R$): ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // ===== Escolha do 1º atributo =====
    printf("\nEscolha o 1º atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n6. PIB per Capita\n> ");
    scanf("%d", &opcao1);

    // ===== Escolha do 2º atributo (sem repetir o 1º) =====
    printf("\nEscolha o 2º atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            printf("%d. ", i);
            exibirNomeAtributo(i);
            printf("\n");
        }
    }
    printf("> ");
    scanf("%d", &opcao2);

    // ===== Comparação =====
    float valor1_attr1 = calcularAtributo(opcao1, carta1);
    float valor2_attr1 = calcularAtributo(opcao1, carta2);
    float valor1_attr2 = calcularAtributo(opcao2, carta1);
    float valor2_attr2 = calcularAtributo(opcao2, carta2);

    // Regra: Densidade (opção 5) -> menor vence, outros -> maior vence
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (opcao1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    pontos2 += (opcao1 == 5) ? (valor2_attr1 < valor1_attr1) : (valor2_attr1 > valor1_attr1);

    pontos1 += (opcao2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    pontos2 += (opcao2 == 5) ? (valor2_attr2 < valor1_attr2) : (valor2_attr2 > valor1_attr2);

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // ===== Resultado =====
    printf("\n===== RESULTADO =====\n");
    printf("%s: ", carta1.nomeCidade); exibirNomeAtributo(opcao1);
    printf(" = %.2f | ", valor1_attr1); exibirNomeAtributo(opcao2);
    printf(" = %.2f | Soma = %.2f\n", valor1_attr2, soma1);

    printf("%s: ", carta2.nomeCidade); exibirNomeAtributo(opcao1);
    printf(" = %.2f | ", valor2_attr1); exibirNomeAtributo(opcao2);
    printf(" = %.2f | Soma = %.2f\n", valor2_attr2, soma2);

    if (soma1 > soma2)
        printf("\nVencedor: %s\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nVencedor: %s\n", carta2.nomeCidade);
    else
        printf("\nEmpate!\n");

    return 0;
}



