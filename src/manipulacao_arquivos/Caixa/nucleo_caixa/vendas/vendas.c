#include "vendas.h"
#include "../../../Armazenamento/historico_alloc/halloc.h"
#include "../../../Utilitarios/utils.h"
#include <stdio.h>
#include <string.h>

void RealizarVenda(Pdv *pdv){
    int opcao, retorno, idEscolha, encontrado = 0;
    char escolha[50];
    if(pdv->caixaAberto == 0 || pdv->quantidadeProd == 0 ){
        printf("\nO seu caixa ainda nao foi aberto, ou nao ha produtos cadastrados");
        return;
    }
    
    do{
            printf("\nEscolha");
            printf("\nMercado - 1");
            printf("\nPadaria - 2");
            retorno = scanf("%d", &opcao);
            if(retorno !=1){
                printf("\nUtilize apenas numeros");
                LimparBuffer();
                continue;
            }
            if (opcao == 1 ){
                printf("\n=========Mercado=========");
                for(int i = 0; i< pdv->quantidadeProd; i++){
                    if(pdv->addProd[i].tipoProd == 1){
                        if(pdv->addProd[i].disponivelProd == 1){
                            printf("\n|Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n|Estoque | %d", pdv->addProd[i].estoqueProd);
                            printf("\n=====================");
                        }
                        else if(pdv->addProd[i].disponivelProd == 0){
                            printf("\n|Produto| %s", pdv->addProd[i].nomeProd);
                            printf("\n| Fora de estoque | ");

                        }
                    }
                }
            }
            if (opcao == 2 ){
                printf("\n=========Padaria=========");
                for(int i = 0; i< pdv->quantidadeProd; i++){
                    if(pdv->addProd[i].tipoProd == 2){
                        if(pdv->addProd[i].disponivelProd == 1){
                            printf("\n|Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n|Estoque | %d", pdv->addProd[i].estoqueProd);
                            printf("\n=====================");
                        }
                        else if(pdv->addProd[i].disponivelProd == 0){
                            printf("\n|Produto| %s", pdv->addProd[i].nomeProd);
                            printf("\n| Fora de estoque | ");

                        }
                    }
                }
            }

                printf("\nDigite o nome do produto");
                fgets(escolha, 50, stdin);
                escolha[strcspn(escolha, "\n")] = '\0';
                printf("\nSelecione o ID do produto desejado");
                for(int i = 0; i < pdv->quantidadeProd; i++){
                    if(strstr(pdv->addProd[i].nomeProd, escolha)!=NULL){
                        if(pdv->addProd[i].disponivelProd == 1){
                            printf("\n[%d] | %s ", pdv->addProd[i].idProd, pdv->addProd[i].nomeProd);
                        }
                    }
                }

                printf("\nID: ");
                scanf("%d", &idEscolha);
                for(int i = 0; i < pdv->quantidadeProd; i++){
                    if(idEscolha == pdv->addProd[i].idProd){
                        printf("\nProduto selecionado: %s", pdv->addProd[i].nomeProd);
                        encontrado = 1;
                        break;
                    }
                }

                if(encontrado == 0){
                    printf("\nNenhum produto encontrado");
                }




            




    }while ( retorno !=1|| (opcao !=1 && opcao !=2));
}
