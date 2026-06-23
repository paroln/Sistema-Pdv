#include "persistencia.h"
#include "../Armazenamento/prod_alloc/pdalloc.h"
#include <stdio.h>
#include <stdlib.h>

void SalvarProdutos(Pdv *pdv){
    FILE *arq = fopen("produtos.dat", "wb");
    if(arq == NULL){
        printf("\nErro ao salvar produtos!");
        return;
    }
    fwrite(&pdv->quantidadeProd, sizeof(int), 1, arq);
    fwrite(pdv->addProd, sizeof(Produtos), pdv->quantidadeProd, arq);
    fclose(arq);
    printf("\nProdutos salvos!");
}

void CarregarProdutos(Pdv *pdv){
    FILE *arq = fopen("produtos.dat", "rb");
    if(arq == NULL) return;

    int quantidade;
    fread(&quantidade, sizeof(int), 1, arq);

    for(int i = 0; i < quantidade; i++){
        Produtos p;
        fread(&p, sizeof(Produtos), 1, arq);
        CapacidadeProdutos(pdv, p);
    }
    fclose(arq);
}