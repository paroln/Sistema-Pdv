#include "validacoes.h"
#include "../Utilitarios/utils.h"
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
            printf("\n| Digite apenas numeros!\n");
            LimparBuffer();
            continue;
        }
        for(int i = 0; i < pdv->quantidadeProd; i++){
            if(pdv ->addProd[i].idProd == *id){
                repetido = 1;
                printf("\n| ID ja cadastrado!\n");
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
            printf("\n| Use apenas numeros para definicao de precos!");
            LimparBuffer();
            continue;
        }
        if (*valor < 0.50){
            printf("\n| O valor deve ser no minimo R$0.50!");
        }
    } while(retorno != 1 || *valor < 0.50);
}
void ValidarEstoque(int *estoque){
    int retorno;
    do {
        printf("\n| Estoque: ");
        retorno = scanf("%d", estoque);
        if(retorno != 1){
            printf("\n| Digite apenas numero!");
            LimparBuffer();
            continue;
        }
        if(*estoque <= 0){
            printf("\n| Deve-se ter ao menos 1 unidade no estoque");
            LimparBuffer();
        }
    } while(retorno != 1 || *estoque <= 0);
}
void ValidarTipo(int *tipo){
    int retorno;
    do{
        printf("\n1 - Mercado | 2 - Padaria");
        printf("\n| Digite o tipo do produto: ");
        retorno = scanf("%d", tipo);
        if(retorno != 1 || (*tipo != 1 && *tipo != 2)){
            printf("\n| Utilize apenas 1 ou 2 para o tipo dos produtos.");
            LimparBuffer();
            continue;
        }
    } while(retorno != 1 || (*tipo != 1 && *tipo != 2));
}
void ValidarNome(char nome[], Pdv *pdv, int indiceAtual) {
    LimparBuffer();
    
    int valido;
    do {
        valido = 1;
        printf("\n| Nome: ");
        fgets(nome, 40, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        if (strlen(nome) < 3) {
            printf("\n| Nome muito curto!");
            valido = 0;
        } else {
            for (int i = 0; nome[i] != '\0'; i++) {
                if(!isalpha((unsigned char)nome[i]) &&
                !isdigit((unsigned char)nome[i]) &&
                nome[i] != ' ') {
                    printf("\n| Nome invalido");
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

                if(i == indiceAtual ){
                    continue;
                }

                for(int j = 0;pdv->addProd[i].nomeProd[j]; j++)
                    cadastroMin[j] = tolower((unsigned char)pdv->addProd[i].nomeProd[j]);
                cadastroMin[strlen(pdv->addProd[i].nomeProd)] = '\0';
                if(strcmp(nomeMin, cadastroMin) == 0){
                    printf("\n| Produto ja cadastrado!");
                    valido = 0;
                    break;
                }
            }
        }
    } while (!valido);
}