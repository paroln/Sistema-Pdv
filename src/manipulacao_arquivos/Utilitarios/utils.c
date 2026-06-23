#include "utils.h"
#include <stdio.h>
#include <windows.h>

void LimparBuffer(){
    while(getchar() != '\n');
}

void EvitarLixoMemoria(Pdv *pdv){
    pdv->historicoVendas = NULL;
    pdv->addProd = NULL;
    pdv->caixaAberto = 0;
    pdv->saldoInicial = 0;
    pdv->capacidadeVendas = 0;
    pdv->capacidadeProd = 0;
    pdv->quantidadeProd = 0;
    pdv->quantidadeVendas = 0;
    pdv->saldoVendas = 0;
    pdv->saldoTotal = 0;
}

void Carregando() {
    const char spinner[] = {'|', '/', '-', '\\'};
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("\r %c Carregando...", spinner[i % 4]);
        fflush(stdout);
        Sleep(200);
    }
    printf("\r                 \r");
    fflush(stdout);
    system("cls");  
}
