#include "persistencia.h"
#include "../Armazenamento/prod_alloc/pdalloc.h"
#include "../Utilitarios/utils.h"
#include "../Caixa/insercao_prods/inserir.h"
#include <stdio.h>
#include <stdlib.h>

void SalvarProdutos(Pdv *pdv){
    FILE *arq = fopen("produtos.dat", "wb");
    if(arq == NULL){
        printf("\n| Erro ao salvar produtos!");
        return;
    }
    Carregando();
    fwrite(&pdv->quantidadeProd, sizeof(int), 1, arq);
    fwrite(pdv->addProd, sizeof(Produtos), pdv->quantidadeProd, arq);
    fclose(arq);
    printf("\n| Produtos salvos!");
}

void CarregarProdutos(Pdv *pdv){
    FILE *arq = fopen("produtos.dat", "rb");
    if(arq == NULL) return;

    int quantidade;
    fread(&quantidade, sizeof(int), 1, arq);

    Carregando();
    for(int i = 0; i < quantidade; i++){
        Produtos p;
        fread(&p, sizeof(Produtos), 1, arq);
        InserirProd(pdv, p);
    }
    fclose(arq);
}