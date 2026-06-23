#ifndef CAIXA_H
#define CAIXA_H
typedef struct{
    int idVendas;
    float totalVendas;
    int quantVendas;
} Venda;
typedef struct{
    int idProd;
    char nomeProd[40];
    int tipoProd;
    float precoProd;
    int estoqueProd;
    int disponivelProd;
    int totalVendido;
} Produtos;
typedef struct{
    float saldoTotal;
    float saldoInicial;
    float saldoVendas;
    int caixaAberto;
    Venda *historicoVendas;
    int capacidadeVendas;
    int quantidadeVendas;    
    Produtos *addProd;
    int quantidadeProd;
    int capacidadeProd;
} Pdv;
 
void AbrirCaixa(Pdv *pdv);


#endif