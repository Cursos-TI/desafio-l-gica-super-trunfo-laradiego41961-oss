#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("\n");
}

int main() {
    // Cadastro de duas cartas (dados fictícios)
    struct Carta carta1 = {
        "São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 2300.0, 150
    };

    struct Carta carta2 = {
        "Rio de Janeiro", "RJ01", "Rio de Janeiro", 6710000, 1182.30, 900.0, 120
    };

    // Cálculo da densidade e PIB per capita para ambas as cartas
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);

    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Exibir cartas
    printf("== Carta 1 ==\n");
    exibirCarta(carta1);

    printf("== Carta 2 ==\n");
    exibirCarta(carta2);

    // ==========================
    // Comparação de atributo
    // ==========================
    printf("== Comparação de cartas (Atributo: População) ==\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
