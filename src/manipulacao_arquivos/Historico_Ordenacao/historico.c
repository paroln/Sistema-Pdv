#include "historico.h"
#include <stdio.h>
#include <string.h>

int buscaBinaria(Produtos arr[], int tam, float chave) {
    int esq = 0;
    int dir = tam - 1;

    while (esq <= dir) {
        int meio = (esq + dir) / 2;

        if (arr[meio].precoProd == chave)
            return meio;
        else if (arr[meio].precoProd < chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }

    return esq;
}

void ordenacaobinaria(Produtos arr[], int tam) {
    for (int i = 1; i < tam; i++) {
        Produtos chave = arr[i];

        int pos = buscaBinaria(arr, i, chave.precoProd);

        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }

        arr[pos] = chave;
    }
}

void ExibirRankingLucro(Pdv *pdv) {

    if (pdv->quantidadeProd == 0) {
        printf("\nNenhum produto cadastrado.");
        return;
    }

    Produtos copia[pdv->quantidadeProd];

    for (int i = 0; i < pdv->quantidadeProd; i++) {
        copia[i] = pdv->addProd[i];
    }

    ordenacaobinaria(copia, pdv->quantidadeProd);

    printf("\n===== RANKING POR PRECO =====");

    for (int i = 0; i < pdv->quantidadeProd; i++) {
        printf("\n%d. %s | R$ %.2f",
            i + 1,
            copia[i].nomeProd,
            copia[i].precoProd
        );
    }
}

void ExibirRankingQuantidade(Pdv *pdv) {

    if (pdv->quantidadeProd == 0) {
        printf("\nNenhum produto cadastrado.");
        return;
    }

    Produtos copia[pdv->quantidadeProd];

    for (int i = 0; i < pdv->quantidadeProd; i++) {
        copia[i] = pdv->addProd[i];
    }

    for (int i = 1; i < pdv->quantidadeProd; i++) {
        Produtos chave = copia[i];
        int j = i - 1;

        while (j >= 0 && copia[j].totalVendido < chave.totalVendido) {
            copia[j + 1] = copia[j];
            j--;
        }

        copia[j + 1] = chave;
    }

    printf("\n===== RANKING POR VENDAS =====");

    for (int i = 0; i < pdv->quantidadeProd; i++) {
        printf("\n%d. %s | %d vendidos",
            i + 1,
            copia[i].nomeProd,
            copia[i].totalVendido
        );
    }
}