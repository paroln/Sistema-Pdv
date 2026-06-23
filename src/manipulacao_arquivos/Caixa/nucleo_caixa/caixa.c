#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Utilitarios/utils.h"
void AbrirCaixa(Pdv *pdv){
        if(pdv->caixaAberto == 1){
            printf("\n===== Seu caixa ja foi aberto! =====");
            return;
        }
        int retorno;
        do{
            printf("\n| Valor inicial: R$ ");
retorno = scanf("%f", &pdv->saldoInicial);
            if(retorno!=1){
                printf("\n===== Utilize apenas numeros! =====");
                LimparBuffer();
                continue;
            }
            if(pdv->saldoInicial <= 0){
            printf("\n===== O valor nao pode ser negativo! =====");
            }
        }while (retorno!=1 || pdv->saldoInicial<=0);

        pdv->saldoTotal = pdv->saldoInicial;
        pdv->caixaAberto = 1;
}
        