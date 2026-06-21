#include "vendas.h"
#include "../../../Armazenamento/historico_alloc/halloc.h"
#include "../../../Utilitarios/utils.h"
#include "stdio.h"

void RealizarVenda(Pdv *pdv){
    int opcao, retorno;
    if(pdv->caixaAberto == 0 || pdv->quantidadeProd == 0 ){
        printf("\nO seu caixa ainda nao foi aberto, ou nao ha produtos cadastrados");
        return;
    }
    
    do{
            printf("\nEscolha");
            printf("\nMercado - 1 ");
            printf("\nPadaria - 2 ");
            retorno = scanf("%d", &opcao);
            if(retorno !=1){
                printf("\nUtilize apenas numeros");
                LimparBuffer();
                continue;
            }




    }while ( retorno !=1|| (opcao !=1 && opcao !=2));
}
