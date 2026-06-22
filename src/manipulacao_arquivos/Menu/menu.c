#include "menu.h"
#include "../Caixa/nucleo_caixa/vendas/vendas.h"
#include "../Utilitarios/utils.h"
#include "../Caixa/controle_estoq/produtos.h"
#include "../Historico - Ordenacao/historico.h"
#include <stdio.h>
#include <stdlib.h>

void Menu(Pdv *pdv){
    int op = 0;
    do{
        printf("\nEscolha alguma opcao");
        printf("\n1 - Abrir caixa\n2 - Cadastrar produtos\n3 - Realizar venda\n4 - Historico\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);
        LimparBuffer();
        switch(op){
            case 1: AbrirCaixa(pdv); 
                break;
            case 2: CadastrarProdutos(pdv);
                break;
            case 3: RealizarVenda(pdv); 
                break;
            case 4: ExibirRankingLucro(pdv);
                    ExibirRankingQuantidade(pdv);
                break;
        }
    } while(op != 5);
    free(pdv->addProd);
    free(pdv->historicoVendas);
}