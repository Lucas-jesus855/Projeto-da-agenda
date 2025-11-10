// Projeto: Agenda simples
// Autores: Yan Pedro e Lucas Sousa
// Data: 17/10/2025
// Versão 1.0
#include <stdio.h>
#include <string.h>

#define MAX_COMPROMISSOS 3

// Funções (protótipos)

void adicionarCompromisso(char datas[][11], char horas[][6], char descricoes[][50], int *total);
void listarCompromissos(char datas[][11], char horas[][6], char descricoes[][50], int total);

int main() {
    char datas[MAX_COMPROMISSOS][11];
    char horas[MAX_COMPROMISSOS][6];
    char descricoes[MAX_COMPROMISSOS][50];

    int total = 0;
    int opcao;
    int leitura;

    printf("+++ AGENDA SIMPLES +++\n");

    do {
        printf("\n1 - Adicionar compromisso");
        printf("\n2 - Listar compromissos");
        printf("\n3 - Sair");
        printf("\nEscolha uma opcao: ");

        // Verifica se a entrada é válida 

        leitura = scanf("%d", &opcao);

        if (leitura != 1) { 
            // Se o usuário digitou algo inválido (letra, símbolo, etc.)
            printf("\nERRO: Entrada invalida! Digite apenas numeros.\n");

            // Limpa o buffer (descarta o que foi digitado)
            while (getchar() != '\n');

            // Continua o loop sem travar
            opcao = 0;
        }

        if (opcao == 1) {
            adicionarCompromisso(datas, horas, descricoes, &total);
        } else if (opcao == 2) {
            listarCompromissos(datas, horas, descricoes, total);
        } else if (opcao == 3) {
            printf("\nSaindo do programa...\n");
        } else if (opcao != 0) {
            printf("\nOpcao invalida! Escolha 1, 2 ou 3.\n");
        }

    } while (opcao != 3);

    return 0;
}

// Função para adicionar compromisso

void adicionarCompromisso(char datas[][11], char horas[][6], char descricoes[][50], int *total) {
    if (*total < MAX_COMPROMISSOS) {
        printf("\n+++ ADICIONAR COMPROMISSO %d +++\n", *total + 1);

        printf("Digite a data dd/mm/aaaa: ");
        scanf("%s", datas[*total]);

        printf("Digite a hora hh:mm: ");
        scanf("%s", horas[*total]);

        printf("Digite a descricao (sem espacos): ");
        scanf("%s", descricoes[*total]);

        (*total)++;
        printf("Compromisso adicionado com sucesso!\n");
    } else {
        printf("\nAgenda cheia! Nao e possivel adicionar mais compromissos.\n");
    }
}

// Função para listar compromissos

void listarCompromissos(char datas[][11], char horas[][6], char descricoes[][50], int total) {
    if (total == 0) {
        printf("\nNenhum compromisso cadastrado.\n");
    } else {
        printf("\n+++ LISTA DE COMPROMISSOS +++\n");
        for (int i = 0; i < total; i++) {
            printf("%d - Data: %s | Hora: %s | Descricao: %s\n", i + 1, datas[i], horas[i], descricoes[i]);
        }
    }
}
