/*
Projeto: Organization 
Autor: Lucas Sousa e Yan Pedro
Data de criação: 17/10/2025
Descrição: Estrutura inicial do projeto Agenta simples. 
Versão 1.0*/




#include <stdio.h>

int main() {
    char datas[5][11];
    char horas[5][6];
    char descricoes[5][50];
    int numero1, total = 0;
    int opcao;

    do {
        printf("\nAgenda Simples\n");
        printf("1 Adicionar compromisso\n");
        printf("2 Listar compromissos\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total < 5) {
                printf("Digite a data (dd/mm/aaaa): ");
                scanf(" %10[^\n]", datas[total]);
                printf("Digite a hora (hh:mm): ");
                scanf(" %5[^\n]", horas[total]);
                printf("Digite a descricao: ");
                scanf(" %49[^\n]", descricoes[total]);
                total++;
                printf("Compromisso adicionado!\n");
            } else {
                printf("Agenda cheia!\n");
            }
        } else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum compromisso cadastrado.\n");
            } else {
                printf("\nLista de compromissos:\n");
                for (numero1 = 0; numero1 < total; numero1++) {
                    printf("%d - %s %s - %s\n", numero1+1, datas[numero1], horas[numero1], descricoes[numero1]);
                }
            }
        } else if (opcao != 3) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    printf("Programa encerrado.\n");
    return 0;

}
