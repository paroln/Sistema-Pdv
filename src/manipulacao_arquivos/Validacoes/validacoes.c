#include "validacoes.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void ValidarID(int *id, Pdv *pdv){
    int retorno;
    int repetido;
    do{
        repetido = 0;
        printf("\nDigite o ID: ");
        retorno = scanf("%d", id);
        if(retorno != 1){
            printf("\nDigite apenas numeros!\n");
            LimparBuffer();
            continue;
        }
        for(int i = 0; i < pdv->quantidadeProd; i++){
            if(pdv ->addProd[i].idProd == *id){
                repetido = 1;
                printf("\nID ja cadastrado\n");
                break;
            }
        }
    } while(retorno != 1 || repetido);
}
void ValidarPreco(float *valor){
    int retorno;
    do{
        printf("\nPreco: ");
        retorno = scanf("%f", valor);
        if(retorno != 1){
            printf("\nUse apenas numeros para definicao de precos");
            LimparBuffer();
            continue;
        }
        if (*valor < 0.50){
            printf("\nO valor deve ser no minimo R$0.50");
        }
    } while(retorno != 1 || *valor < 0.50);
}
void ValidarEstoque(int *estoque){
    int retorno;
    do {
        printf("\nEstoque: ");
        retorno = scanf("%d", estoque);
        if(retorno != 1){
            printf("\nDigite apenas numero!");
            LimparBuffer();
            continue;
        }
        if(*estoque <= 0){
            printf("\nDeve-se ter ao menos 1 unidade no estoque");
            LimparBuffer();
        }
    } while(retorno != 1 || *estoque <= 0);
}
void ValidarTipo(int *tipo){
    int retorno;
    do{
        printf("\nDigite o tipo do produto mercado (1), padaria (2)");
        retorno = scanf("%d", tipo);
        if(retorno != 1 || (*tipo != 1 && *tipo != 2)){
            printf("\nUtilize apenas 1 ou 2 para o tipo dos produtos");
            LimparBuffer();
            continue;
        }
    } while(retorno != 1 || (*tipo != 1 && *tipo != 2));
}
void ValidarNome(char nome[], Pdv *pdv) {
    LimparBuffer();
    int valido;
    do {
        valido = 1;
        printf("\nNome: ");
        fgets(nome, 40, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        if (strlen(nome) < 3) {
            printf("\nNome muito curto!");
            valido = 0;
        } else {
            for (int i = 0; nome[i] != '\0'; i++) {
                if (!isalpha((unsigned char)nome[i]) && nome[i] != ' ') {
                    printf("\nUse apenas letras!");
                    valido = 0;
                    break;
                }
            }
        }
        if (valido) {
            char nomeMin[40], cadastroMin[40];
            for(int i = 0; nome[i] != '\0'; i++){
                nomeMin[i] = tolower((unsigned char)nome[i]);
            }
            nomeMin[strlen(nome)] = '\0';

            for(int i = 0; i < pdv->quantidadeProd; i++){
                for(int j = 0;pdv->addProd[i].nomeProd[j]; j++)
                    cadastroMin[j] = tolower((unsigned char)pdv->addProd[i].nomeProd[j]);
                cadastroMin[strlen(pdv->addProd[i].nomeProd)] = '\0';
                if(strcmp(nomeMin, cadastroMin) == 0){
                    printf("\nProduto ja cadastrado!");
                    valido = 0;
                    break;
                }
            }
        }
    } while (!valido);
}