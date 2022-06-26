HEDERS_FILE = Models/encomenda.h Models/pedido.h Models/usuario.h Generators/id_generator.h \
Users/user_verification.h Structures/lista_usuario.h Structures/fila_pedido.h Structures/bst_encomenda.h \
Workflows/cadastrar_encomenda_workflow.h Workflows/cadastrar_pedido_workflow.h

OBJ_FILES = main.o encomenda.o pedido.o usuario.o id_generator.o \
user_verification.o lista_usuario.o fila_pedido.o bst_encomenda.o \
cadastrar_encomenda_workflow.o cadastrar_pedido_workflow.o 

C_FILES = main.c Models/encomenda.c Models/pedido.c Models/usuario.c \
Generators/id_generator.c Users/user_verification.c Structures/lista_usuario.c Structures/fila_pedido.c \
Structures/bst_encomenda.c Workflows/cadastrar_encomenda_workflow.c Workflows/cadastrar_pedido_workflow.c

create:
	gcc $(OBJ_FILES)

comp: $(HEDERS_FILE)
	gcc -c $(C_FILES)

all: comp create

clean:
	rm -rf *.o
	find . -name \*.gch -delete