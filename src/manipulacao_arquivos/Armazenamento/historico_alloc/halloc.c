#include "halloc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../Utilitarios/utils.h"

void AllocarHistorico(Pdv *pdv, int quantidade, int indice){
    if(pdv->capacidadeVendas == 0){
        pdv->capacidadeVendas = 10;
        pdv->historicoVendas = malloc (10 * sizeof(Venda));
        if(pdv->historicoVendas == NULL){
            free(pdv->addProd);
            printf("\nERRO NA MEMORIA"); exit(1);
        }
    } else if(pdv->capacidadeVendas == pdv->quantidadeVendas){
         pdv->capacidadeVendas*= 2;
         Venda *temp = realloc(pdv->historicoVendas, pdv->capacidadeVendas * sizeof (Venda));
         if(temp == NULL){
            free(pdv->historicoVendas);
            free(pdv->addProd);
            printf("\nERRO NA MEMORIA");
            exit(1);
         }
         pdv->historicoVendas = temp;

    }

        pdv->historicoVendas[pdv->quantidadeVendas].idVendas = pdv->quantidadeVendas + 1;
        pdv->historicoVendas[pdv->quantidadeVendas].quantVendas = quantidade;
        pdv->historicoVendas[pdv->quantidadeVendas].totalVendas = quantidade * pdv->addProd[indice].precoProd;
        pdv->quantidadeVendas++;
}