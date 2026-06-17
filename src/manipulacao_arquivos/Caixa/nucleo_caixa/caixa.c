#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Utilitarios/utils.h"
void AbrirCaixa(Pdv *pdv){
        if(pdv->caixaAberto == 1){
            printf("\nSeu caixa ja foi aberto");
            return;
        }
        int retorno;
        do{
            printf("\nDigite o valor para abertura do caixa");
            retorno = scanf("%f", &pdv->saldoInicial);
            if(retorno!=1){
                printf("\nUtilize apenas numeros!");
                LimparBuffer();
                continue;
            }
            if(pdv->saldoInicial <= 0){
            printf("\nO valor nao pode ser negativo!");
            }
        }while (retorno!=1 || pdv->saldoInicial<=0);

        pdv->saldoTotal = pdv->saldoInicial;
        pdv->caixaAberto = 1;
}
        