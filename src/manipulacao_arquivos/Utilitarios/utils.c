#include "utils.h"
#include <stdio.h>

void LimparBuffer(){
    while(getchar ()!='\n');
}

void EvitarLixoMemoria(Pdv *pdv){
    pdv->historicoProd = NULL;
    pdv->addProd = NULL;
    pdv->caixaAberto = 0;
    pdv->saldoInicial = 0;
    pdv->capacidadeVendas = 0;
    pdv->capacidadeProd= 0;
    pdv->quantidadeProd = 0;
    pdv->quantidadeVendas = 0;
    pdv->saldoVendas = 0;
    pdv->saldoTotal = 0;
    pdv->saldoInicial = 0;
}