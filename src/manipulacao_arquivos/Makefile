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
       Caixa/nucleo_caixa/vendas/vendas.c \
       Historico_Ordenacao/historico.c

TARGET = programa.exe

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)