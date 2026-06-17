#ifndef CAIXA_H
#define CAIXA_H
typedef struct{
    int idVendas;
    float totalVendas;
    int quantidadeVendas;
} Venda;
typedef struct{
    int idProd;
    char nomeProd[40];
    int tipoProd;
    float precoProd;
    int estoqueProd;
    int disponivelProd;
} Produtos;
typedef struct{
    float saldoTotal;
    float saldoInicial;
    float saldoVendas;
    int caixaAberto;
    Venda *historicoProd;
    int capacidadeVendas;
    int quantidadeVendas;
    
    Produtos *addProd;
    int quantidadeProd;
    int capacidadeProd;
} Pdv;
 
void AbrirCaixa(Pdv *pdv);


#endif