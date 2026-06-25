#include "vendas.h"
#include "../../Persistencia/persistencia.h"
#include "../../Armazenamento/historico_alloc/halloc.h"
#include "../../Utilitarios/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void RealizarVenda(Pdv *pdv){
    int opcao, retorno, quantidade, indice, idEscolha, idEncontrado = 0, nomeEncontrado = 0; float totalSessao = 00.0f;
    char nomeEscolha[50],continuarCompra;
    if(pdv->caixaAberto == 0 || pdv->quantidadeProd == 0 ){
        printf("\nO seu caixa ainda nao foi aberto, ou nao ha produtos cadastrados");
        return;
    }
    
    do{
            printf("\n===== Escolha =====");
            printf("\n1 | Mercado");
            printf("\n2 | Padaria");
            retorno = scanf("%d", &opcao);
            if(retorno !=1){
                printf("\n===== Utilize apenas numeros! =====");
                LimparBuffer();
                return;
            }

            if(opcao != 2 && opcao != 1){
                printf("\nOpcao invalida!");
                return;
            }
            if (opcao == 1 ){
                printf("\n===== Mercado =====");
                for(int i = 0; i< pdv->quantidadeProd; i++){
                    if(pdv->addProd[i].tipoProd == 1){
                        if(pdv->addProd[i].disponivelProd == 1){
                            printf("\n| Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n| Estoque | %d", pdv->addProd[i].estoqueProd);
                            printf("\n=====================");
                        }
                        else if(pdv->addProd[i].disponivelProd == 0){
                            printf("\n| Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n| Fora de estoque | ");

                        }
                    }
                }
            }
            if (opcao == 2 ){
                printf("\n===== Padaria =====");
                for(int i = 0; i< pdv->quantidadeProd; i++){
                    if(pdv->addProd[i].tipoProd == 2){
                        if(pdv->addProd[i].disponivelProd == 1){
                            printf("\n| Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n| Estoque | %d", pdv->addProd[i].estoqueProd);
                            printf("\n| Preco R$%.2f |", pdv->addProd[i].precoProd);
                            printf("\n=====================");
                        }
                        else if(pdv->addProd[i].disponivelProd == 0){
                            printf("\n| Produto | %s", pdv->addProd[i].nomeProd);
                            printf("\n| Fora de estoque | ");

                        }
                    }
                }
            }
            
                printf("\n| Digite o nome do produto: ");
                LimparBuffer();
                fgets(nomeEscolha, 50, stdin);
                nomeEscolha[strcspn(nomeEscolha, "\n")] = '\0';

                char escolhaMinuscula[50];
                for(int j = 0; nomeEscolha[j] != '\0'; j++){
                            escolhaMinuscula[j] = tolower((unsigned char)nomeEscolha[j]);
                }
                escolhaMinuscula[strlen(nomeEscolha)] = '\0';

                nomeEncontrado = 0;

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

                }

                if(nomeEncontrado == 0){
                        printf("\n===== Nenhum produto encontrado! =====");
                        return;
                }
                printf("\nID: ");   
                if(scanf("%d", &idEscolha) != 1){
                        printf("\n===== Digite apenas numeros =====");
                        LimparBuffer();
                        continue;
                }
                indice = -1;
                idEncontrado = 0;
                for(int i = 0; i < pdv->quantidadeProd; i++){
                    if(idEscolha == pdv->addProd[i].idProd && pdv->addProd[i].tipoProd == opcao && pdv->addProd[i].disponivelProd == 1){
                            printf("\n| Produto selecionado: %s", pdv->addProd[i].nomeProd);
                            idEncontrado = 1;
                            indice = i;
                            break;
                    }
                }

                if(idEncontrado == 0){
                        printf("\n===== Nenhum produto encontrado! =====");
                        return;
                    }

                printf("\n| Quantidade: ");
                if(scanf("%d", &quantidade) != 1 || quantidade <= 0){
                        printf("\n===== Quantidade invalida! =====");
                        LimparBuffer();
                        return;
                }

                if(quantidade > pdv->addProd[indice].estoqueProd){  
                        printf("\nEstoque insuficiente! Disponivel: %d", pdv->addProd[indice].estoqueProd);
                        return;
                }

                pdv->addProd[indice].estoqueProd -= quantidade;
                pdv->addProd[indice].totalVendido += quantidade;

                if(pdv->addProd[indice].estoqueProd == 0){
                        pdv->addProd[indice].disponivelProd = 0;
                        printf("\n| Produto esgotado! |");
                }
                AllocarHistorico(pdv, quantidade, indice);
                pdv->saldoVendas += pdv->historicoVendas[pdv->quantidadeVendas - 1].totalVendas;
                pdv->saldoTotal  += pdv->historicoVendas[pdv->quantidadeVendas - 1].totalVendas;
                totalSessao += pdv->historicoVendas[pdv->quantidadeVendas - 1].totalVendas;
                SalvarProdutos(pdv);

                printf("\nDeseja adicionar mais algum produto na sacola?");
                scanf(" %c",&continuarCompra);
                if(continuarCompra == 'n' || continuarCompra == 'N'){
                    printf("\n| Venda realizada! Total da sessao: |R$ %.2f", totalSessao);
                    printf("======================================");
                }


    }while ( continuarCompra == 's' || continuarCompra == 'S' );
}
