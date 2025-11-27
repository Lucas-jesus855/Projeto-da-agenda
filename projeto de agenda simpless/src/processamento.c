#include <stdio.h>
#include "processamento.h"
#include "tarefa.h"
#include "persistencia.h"
#include "entrada.h"
#include "saida.h"

void processarOpcao(int opcao, struct Tarefa tarefas[], int *quantidade, int max) {

    if (opcao == 1) {
        // Adicionar tarefa
        adicionarTarefa(tarefas, quantidade, max);
        salvarTarefas(tarefas, *quantidade);
        exibirMensagem("Tarefa adicionada com sucesso!");

    } else if (opcao == 2) {
        // Listar tarefas
        listarTarefas(tarefas, *quantidade);

    } else if (opcao == 3) {
        // Marcar como concluída
        marcarConcluida(tarefas, *quantidade);
        salvarTarefas(tarefas, *quantidade);

    } else if (opcao == 4) {
        // Excluir tarefa
        excluirTarefa(tarefas, quantidade);
        salvarTarefas(tarefas, *quantidade);

    } else if (opcao == 0) {
        exibirMensagem("Saindo do programa...");

    } else {
        exibirMensagem("Opcao invalida.");
    }
}
