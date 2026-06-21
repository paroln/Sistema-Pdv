#include "halloc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AllocarHistorico(Pdv *pdv){
    if(pdv->capacidadeVendas == 0){
        pdv->capacidadeVendas = 10;
        pdv->historicoVendas = malloc (10 * sizeof(Venda));
        if(pdv->historicoVendas == NULL){
            free(pdv->addProd);
            printf("\nERRO NA MEMORIA"); exit(1);
        }
    } else if(pdv->capacidadeVendas == pdv->quantidadeVendas)

}