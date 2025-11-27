#include <stdio.h>
#include "tarefa.h"

// Função para salvar as tarefas em um arquivo
void salvarTarefas(struct Tarefa tarefas[], int quantidade) {
    FILE *arquivo = fopen("tarefas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s;%d\n", tarefas[i].nome, tarefas[i].concluida);
    }

    fclose(arquivo);
}


// Função para carregar tarefas do arquivo
int carregarTarefas(struct Tarefa tarefas[], int max) {
    FILE *arquivo = fopen("tarefas.txt", "r");

    if (arquivo == NULL) {
        // Se não existir arquivo, não é erro: só significa que não tem nada salvo.
        return 0;
    }

    int quantidade = 0;

    while (quantidade < max &&
           fscanf(arquivo, "%[^;];%d\n", tarefas[quantidade].nome, &tarefas[quantidade].concluida) == 2) {
        quantidade++;
    }

    fclose(arquivo);
    return quantidade;
}
