#include "menu.h"
#include "../Caixa/editar_produto/editar.h"
#include "../Caixa/vendas/vendas.h"
#include "../Utilitarios/utils.h"
#include "../Caixa/controle_estoq/produtos.h"
#include "../Historico_Ordenacao/historico.h"
#include <stdio.h>
#include <stdlib.h>

void Menu(Pdv *pdv){
    int op = 0;
    do{
        printf("\n===== SISTEMA MERCADO|PADARIA =====");
        printf("\n===== Escolha alguma opcao =====");
        printf("\n1 | Abrir caixa\n2 | Cadastrar produtos \n3 | Realizar venda\n4 | Historico\n5 | Editar\n6 | Sair");
        printf("\n===================================");
        printf("\nOpcao: ");
        scanf("%d", &op);
        LimparBuffer();
        switch(op){
            case 1: Carregando();AbrirCaixa(pdv); 
                break;
            case 2: Carregando();CadastrarProdutos(pdv);
                break;
            case 3: Carregando();RealizarVenda(pdv); 
                break;
            case 4: Carregando();ExibirMaiorPreco(pdv);
                    ExibirRankingQuantidade(pdv);
                    ExibirHistoricoFinanceiro(pdv);
                    
                break;
            case 5 : Carregando(); EditarProd(pdv);
                break;
        }
    } while(op != 6);
    free(pdv->addProd);
    free(pdv->historicoVendas);
}