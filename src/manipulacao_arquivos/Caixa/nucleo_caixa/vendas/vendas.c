#include "vendas.h"
#include "../../../Armazenamento/historico_alloc/halloc.h"
#include "../../../Utilitarios/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void RealizarVenda(Pdv *pdv){
    int opcao, retorno, idEscolha, idEncontrado = 0, nomeEncontrado = 0;
    char nomeEscolha[50];
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

                printf("\nDigite o nome do produto: ");
                LimparBuffer();
                fgets(nomeEscolha 
                    , 50, stdin);
                nomeEscolha[strcspn(nomeEscolha, "\n")] = '\0';
                char escolhaMinuscula[50];
                for (int j = 0;nomeEscolha[j] != '\0'; j ++){
                    escolhaMinuscula[j] = tolower((unsigned char)nomeEscolha[j]);
                } 
                    escolhaMinuscula[strlen(nomeEscolha)] = '\0';

                printf("\nSelecione o ID do produto desejado");
                for(int i = 0; i < pdv->quantidadeProd; i++){
                    char nomeMin[50];
                    for(int j = 0; pdv->addProd[i].nomeProd[j] != '\0'; j++){
                        nomeMin[j] = tolower((unsigned char)pdv->addProd[i].nomeProd[j]);
                    }
                    nomeMin[strlen(pdv->addProd[i].nomeProd)] = '\0';

                    if(strstr(nomeMin, escolhaMinuscula) != NULL && pdv->addProd[i].disponivelProd == 1 && pdv->addProd[i].tipoProd == opcao){
                        printf("\n[%d] | %s", pdv->addProd[i].idProd, pdv->addProd[i].nomeProd);
                        nomeEncontrado = 1;

                    }
                    if(nomeEncontrado == 0){
                        printf("\nNenhum produto encontrado!");
                            return;
                    }


                }
                    printf("\nID: ");
                    if(scanf("%d", &idEscolha) !=1){
                        printf("\nDigite apenas numeros");
                        LimparBuffer();
                        continue;
                    }   
                        idEncontrado = 0;
                        for(int i = 0; i < pdv->quantidadeProd; i++){
                            if(idEscolha == pdv->addProd[i].idProd && pdv->addProd[i].tipoProd == opcao && pdv->addProd[i].disponivelProd == 1){
                            printf("\nProduto selecionado: %s", pdv->addProd[i].nomeProd);
                            idEncontrado = 1;
                            break;
                    }
                }

                if(idEncontrado == 0 ){
                    printf("\nNenhum produto encontrado");
                    return;
                }




            




    }while ( retorno !=1|| (opcao !=1 && opcao !=2));
}
