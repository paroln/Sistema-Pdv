#ifndef VALIDACOES_H
#define VALIDACOES_H
#include "../Caixa/nucleo_caixa/caixa.h"

void ValidarID(int *id, Pdv *pdv);
void ValidarPreco(float *valor);
void ValidarEstoque(int *estoque);
void ValidarNome(char nome[], Pdv *pdv, int indiceAtual);
void ValidarTipo(int *tipo);

#endif