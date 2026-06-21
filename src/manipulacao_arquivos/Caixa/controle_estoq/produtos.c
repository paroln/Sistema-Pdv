#include "produtos.h"
#include <stdio.h>
#include "../../Validacoes/validacoes.h"
#include "../../Armazenamento/prod_alloc/pdalloc.h"

void CadastrarProdutos(Pdv *pdv){
    Produtos p1;
    if(pdv->caixaAberto == 0){
        printf("\nAbra seu caixa primeiro!");
        return;
    }
    p1.disponivelProd = 1;
    ValidarNome(p1.nomeProd, pdv );
    ValidarID(&p1.idProd, pdv);
    ValidarTipo(&p1.tipoProd);
    ValidarEstoque(&p1.estoqueProd);
    ValidarPreco(&p1.precoProd);
    CapacidadeProdutos(pdv, p1);
}