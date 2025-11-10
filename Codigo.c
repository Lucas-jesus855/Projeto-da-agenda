/*
 * PROJETO: Agenda Simples (Versão Ultra Iniciante)
 * AUTOR: Lucas Sousa e Yan Pedro
 * DATA DE CRIAÇÃO: 17/10/2025
 * DESCRIÇÃO: Versão mais simples da agenda para adicionar e listar compromissos.
 */

#include <stdio.h>

// Reduzimos o limite para facilitar os testes
#define MAX_COMPROMISSOS 3 

int main() {

    // Definicao dos 3 vetores paralelos
    char datas[MAX_COMPROMISSOS][11];
    char horas[MAX_COMPROMISSOS][6];
    char descricoes[MAX_COMPROMISSOS][50];


    int total = 0; // Contador de compromissos cadastrados
    int opcao;     // Opcao do menu
    int i;         // Variavel de controle para loops

    printf("--- AGENDA SIMPLES INICIALIZADA ---\n");


    // Loop principal do programa
    do {
        // Exibicao do Menu
        printf("\n--------------------------------------\n");
        printf("1. Adicionar Compromisso\n");
        printf("2. Listar Todos os Compromissos\n");
        printf("3. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opcao: ");

        // Leitura da opcao
        scanf("%d", &opcao);

        // Controle de Fluxo (if / else if / else) 

        if (opcao == 1) {
            // --- Adicionar Compromisso ---
            if (total < MAX_COMPROMISSOS) {
                printf("\n--- ADICIONAR COMPROMISSO #%d ---\n", total + 1);

                // ATENCAO: scanf para strings nao le espacos!
                printf("Digite a data (sem espacos): ");
                scanf("%s", datas[total]);

                printf("Digite a hora (sem espacos): ");
                scanf("%s", horas[total]);

                printf("Digite a descricao (sem espacos): ");
                scanf("%s", descricoes[total]);

                total++; // Incrementa o contador
                printf("Compromisso adicionado com sucesso!\n");
            } else {
                printf("\nATENÇÃO: Agenda cheia! Limite atingido.\n");
            }

        } else if (opcao == 2) {
            //  Listar Compromissos 
            if (total == 0) {
                printf("\nNenhum compromisso cadastrado.\n");
            } else {
                printf("\n--- LISTA DE COMPROMISSOS (Total: %d) ---\n", total);
                
                for (i = 0; i < total; i++) {
                    printf(" %d: Data: %s | Hora: %s | Descricao: %s\n",
                           i + 1, datas[i], horas[i], descricoes[i]);
                }
            }

        } else if (opcao == 3) {
            //  Sair
            printf("\nPrograma encerrado. Ate mais!\n");

        } else {
            //  Opcao Invalida
            printf("\nOpcao invalida. Escolha 1, 2 ou 3.\n");
        }

    } while (opcao != 3); // Repete enquanto a opcao nao for "Sair"

    return 0;
}

