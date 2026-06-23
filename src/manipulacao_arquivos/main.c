#include "Caixa/nucleo_caixa/caixa.h"
#include "Utilitarios/utils.h"
#include "Caixa/controle_estoq/produtos.h"
#include "Menu/menu.h"
#include "Persistencia/persistencia.h"
#include "Caixa/vendas/vendas.h"
int main(){
    Pdv pdv;
    EvitarLixoMemoria(&pdv);
    CarregarProdutos(&pdv);
    Menu(&pdv);
    
    return 0;
}