#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../../Persistencia/persistencia.h"
#include "../../Utilitarios/utils.h"
#include"../../Validacoes/validacoes.h"
    void EditarProd(Pdv *pdv){
        int id, indice = -1, opcao;
            if(pdv->quantidadeProd == 0){
                    printf("\n===== Nenhum produto cadastrado! =====");
                    return;
        }

            printf("\n===== PRODUTOS =====");
            for (int i = 0; i< pdv->quantidadeProd; i++){
                printf("\n[%d] %s | %.2f | Estoque: %d",
                pdv->addProd[i].idProd,
                pdv->addProd[i].nomeProd,
                pdv->addProd[i].precoProd,
                pdv->addProd[i].estoqueProd
                );
            }

            printf("\n| Digite o ID: ");
            if (scanf("%d", &id) != 1){
                printf("\n| ID invalido!");
                LimparBuffer();
                return;
            }


            for(int i = 0; i<pdv->quantidadeProd;i++){
                if(pdv->addProd[i].idProd == id){
                    indice = i;
                    break;
                }
            }
            
            if(indice == -1){
                printf("\n===== Produto nao encontrado =====");
                return;
            }

            printf("\n| Produto selecionado %s", pdv->addProd[indice].nomeProd);
            printf("\n| Oque deseja editar?");
            printf("\n1 | Nome");
            printf("\n2 | Preco");
            printf("\n3 | Estoque");
            printf("\n4 | Tipo");
            printf("\nOPCAO");
            scanf("%d", &opcao);
            switch(opcao){
                case 1 : ValidarNome(pdv->addProd[indice].nomeProd, pdv, indice); break;
                case 2 : ValidarPreco(&pdv->addProd[indice].precoProd); break;
                case 3 : ValidarEstoque(&pdv->addProd[indice].estoqueProd );
                        if(pdv->addProd[indice].estoqueProd > 0){
                            pdv->addProd[indice].disponivelProd = 1;
                      } else {
                            pdv->addProd[indice].disponivelProd = 0;
                            } break;
                case 4 : ValidarTipo(&pdv->addProd[indice].tipoProd); break;
            
            } 


            SalvarProdutos(pdv);
            printf("\n| Produto atualizado! [%d] %s | %.2f Estoque: %d",
                pdv->addProd[indice].idProd,
                pdv->addProd[indice].nomeProd,
                pdv->addProd[indice].precoProd,
                pdv->addProd[indice].estoqueProd);



    }