#include <stdio.h>
#include "../include/saida.h"
#include "../include/compromisso.h"

// Mostra um título simples
void exibirTitulo(const char *titulo) {
    printf("\n%s\n", titulo);
}

// Mostra uma mensagem simples
void exibirMensagem(const char *mensagem) {
    printf("%s\n", mensagem);
}

// Mostra a lista de compromissos
void exibirLista(const Compromisso compromissos[], int total) {
    if (total == 0) {
        printf("Nenhum compromisso cadastrado.\n");
        return;
    }

    printf("\nCompromissos cadastrados:\n");
    for (int i = 0; i < total; i++) {
        printf("%d - Data: %s | Hora: %s | Descricao: %s\n",
               i + 1,
               compromissos[i].data,
               compromissos[i].hora,
               compromissos[i].descricao);
    }
}
