#include <stdio.h>
#include <string.h>
#include "tarefa.h"
#include "entrada.h"
#include "saida.h"

/* Funcao para adicionar uma tarefa nova */
void adicionarTarefa(struct Tarefa tarefas[], int *quantidade, int maximo) {
    if (*quantidade == maximo) {
        exibirMensagem("Nao e possivel adicionar mais tarefas.");
        return;
    }

    exibirMensagem("Digite a descricao da tarefa:");
    lerLinha(tarefas[*quantidade].descricao, TAM_TEXTO);

    exibirMensagem("Digite a data da tarefa:");
    lerLinha(tarefas[*quantidade].data, TAM_TEXTO);

    tarefas[*quantidade].concluida = 0; /* começa como nao concluida */

    *quantidade = *quantidade + 1;
}

/* Funcao para mostrar todas as tarefas */
void listarTarefas(struct Tarefa tarefas[], int quantidade) {
    exibirLista(tarefas, quantidade);
}

/* Funcao para marcar uma tarefa como concluida */
void marcarConcluida(struct Tarefa tarefas[], int quantidade) {
    if (quantidade == 0) {
        exibirMensagem("Nao ha tarefas para marcar.");
        return;
    }

    int numero;
    exibirMensagem("Qual tarefa deseja marcar como concluida?");
    lerInteiro(&numero);

    numero = numero - 1; /* transforma numero em indice */

    if (numero < 0 || numero >= quantidade) {
        exibirMensagem("Numero invalido.");
        return;
    }

    tarefas[numero].concluida = 1;
    exibirMensagem("Tarefa marcada.");
}

/* Funcao para excluir uma tarefa */
void excluirTarefa(struct Tarefa tarefas[], int *quantidade) {
    if (*quantidade == 0) {
        exibirMensagem("Nao ha tarefas para excluir.");
        return;
    }

    int numero;
    exibirMensagem("Qual tarefa deseja excluir?");
    lerInteiro(&numero);

    numero = numero - 1;

    if (numero < 0 || numero >= *quantidade) {
        exibirMensagem("Numero invalido.");
        return;
    }

    /* move tudo para cima para ocupar o espaco */
    int i;
    for (i = numero; i < *quantidade - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    *quantidade = *quantidade - 1;

    exibirMensagem("Tarefa excluida.");
}
