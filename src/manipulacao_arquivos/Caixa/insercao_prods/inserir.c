#include <stdio.h>
#include "inserir.h"
#include "../../Armazenamento/prod_alloc/pdalloc.h"
    void InserirProd(Pdv *pdv, Produtos produto){
        
        CapacidadeProdutos(pdv);

        pdv->addProd[pdv->quantidadeProd] = produto;
        pdv->addProd[pdv->quantidadeProd].totalVendido = 0;
        pdv->quantidadeProd++;
    }