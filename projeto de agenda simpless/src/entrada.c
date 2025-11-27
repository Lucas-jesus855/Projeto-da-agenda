#include <stdio.h>
#include <string.h>
#include "../include/entrada.h"

// Limpa o resto da linha quando o usuário digita algo errado
void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != ) {}
}

// Lê um número digitado pelo usuário
int lerInteiro(int *valor) {
    if (scanf("%d", valor) != 1) {
        limparEntrada(); // limpa lixo digitado
        return 0;
    }
    limparEntrada(); // remove o \n
    return 1; 
}

// Lê um texto simples (ex: data, hora, descrição)
int lerString(char *destino, int tamanho) {
    fgets(destino, tamanho, stdin);

    // remove o \n do final
    destino[strcspn(destino, "\n")] = '\0';

    return 1;
}
