#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "../utilitarios/utils.h"

void ValidarID(int *id, Pdv *pdv);
void ValidarPreco(float *valor);
void ValidarEstoque(int *estoque);
void ValidarNome(char nome[], Pdv *pdv);
void ValidarTipo(int *tipo);

#endif