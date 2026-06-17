#include "Caixa/nucleo_caixa/caixa.h"
#include "Utilitarios/utils.h"
#include "Caixa/controle_estoq/produtos.h"
#include "Menu/menu.h"

int main(){
    Pdv pdv;
    EvitarLixoMemoria(&pdv);
    Menu(&pdv);
    
    return 0;
}