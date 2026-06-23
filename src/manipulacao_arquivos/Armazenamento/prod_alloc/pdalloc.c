#include "pdalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Utilitarios/utils.h"

void CapacidadeProdutos(Pdv *pdv){
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

}