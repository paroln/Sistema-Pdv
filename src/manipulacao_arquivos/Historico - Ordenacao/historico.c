#include "historico.h"
#include <stdio.h>
#include <string.h>

int buscaBinaria(Produtos arr[], int tam, float chave) {
    int esq = 0;
    int dir = tam - 1;

    while (esq <= dir){
        int meio = (esq + dir) / 2;

        if (arr[meio].precoProd == chave)
            return meio;
        else if (arr[meio].precoProd > chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return esq;
}

int buscaBinariaEstoque(Produtos arr[], int tam, int chave) {
    int esq = 0;
    int dir = tam - 1;

    while (esq <= dir){
        int meio = (esq + dir) / 2;

        if (arr[meio].estoqueProd == chave)
            return meio;
        else if (arr[meio].estoqueProd > chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return esq;
}

void OrdenacaoBinaria(Produtos arr[], int tam) {
    for (int i = 1; i < tam; i++) {
        Produtos chave = arr[i];
        int pos = buscaBinaria(arr, i, chave.precoProd);

        for (int j = i; j > pos; j--)
            arr[j] = arr[j-1];
        arr[pos] = chave;
    }
}

void ExibirRankingLucro(Pdv *pdv) {
    if (pdv->quantidadeVendas == 0) {
    printf("\nNenhuma venda registrada ainda.");
    return;
}
    

    Produtos copia[pdv->quantidadeProd];
        for (int i = 0; i < pdv->quantidadeProd; i++)
            copia[i] = pdv->addProd[i];

    OrdenacaoBinaria(copia, pdv->quantidadeProd);

    printf("\n===== RANKING POR PRECO =====");
        for (int i = 0; i < pdv->quantidadeProd; i++) {
            printf("\n%d. %s | R$ %.2f", i + 1, copia[i].nomeProd, copia[i].precoProd);
    }
}

void OrdenacaoBinariaEstoque(Produtos arr[], int tam) {
    for (int i = 1; i < tam; i++) {
        Produtos chave = arr[i];
        int pos = buscaBinariaEstoque(arr, i, chave.estoqueProd);

        for (int j = i; j > pos; j--)
            arr[j] = arr[j-1];
        arr[pos] = chave;
    }
}

void ExibirRankingQuantidade(Pdv *pdv){
    if (pdv->quantidadeVendas == 0){  
        printf("\nNenhuma venda registrada ainda.");
        return;
    }
    Produtos copia[pdv->quantidadeProd];
        for (int i = 0; i < pdv->quantidadeProd; i++)
            copia[i] = pdv->addProd[i];

        OrdenacaoBinariaEstoque(copia, pdv->quantidadeProd);

    printf("\n===== RANKING POR QUANTIDADE =====");
        for (int i = 0; i < pdv->quantidadeProd; i++) {
            printf("\n%d. %s | %d unidades", i + 1, copia[i].nomeProd, copia[i].estoqueProd);
    }
}


