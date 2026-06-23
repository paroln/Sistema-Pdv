#include "pdalloc.h"
#include <stdio.h>
#include <stdlib.h>

void CapacidadeProdutos(Pdv *pdv, Produtos produto_novo){
    if (pdv->capacidadeProd == 0) {
        pdv->capacidadeProd = 10;
        pdv->addProd = malloc(10 * sizeof(Produtos));
        if (pdv->addProd == NULL) {
            printf("\nErro na memoria");
            exit(1);
        }
    } else if (pdv->capacidadeProd == pdv->quantidadeProd) {
        pdv->capacidadeProd *= 2;
        Produtos *temp = realloc(pdv->addProd, pdv->capacidadeProd * sizeof(Produtos));
        if (temp == NULL) {
            printf("\nErro na memoria");
            exit(1);
        }
        pdv->addProd = temp;
    }
    pdv->addProd[pdv->quantidadeProd] = produto_novo;
    pdv->addProd[pdv->quantidadeProd].totalVendido = 0;
    pdv->quantidadeProd++;
}