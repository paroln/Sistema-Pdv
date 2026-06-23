CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = main.c \
       Menu/menu.c \
       Caixa/nucleo_caixa/caixa.c \
       Caixa/controle_estoq/produtos.c \
       Utilitarios/utils.c \
       Validacoes/validacoes.c \
       Armazenamento/prod_alloc/pdalloc.c \
       Armazenamento/historico_alloc/halloc.c \
       Caixa/vendas/vendas.c \
       Historico_Ordenacao/historico.c \
       Persistencia/persistencia.c \
       Caixa/editar_produto/editar.c \
       Caixa/insercao_prods/inserir.c

TARGET = programa.exe

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)