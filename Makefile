HEDERS_FILE = Models/encomenda.h Models/pedido.h Models/usuario.h Generators/id_generator.h \
Users/user_verification.h Data-structures/list_usuario.h Data-structures/queue_pedido.h Data-structures/bst_encomenda.h \
Workflows/cadastrar_encomenda_workflow.h Workflows/cadastrar_pedido_workflow.h

OBJ_FILES = main.o encomenda.o pedido.o usuario.o id_generator.o \
user_verification.o list_usuario.o queue_pedido.o bst_encomenda.o \
cadastrar_encomenda_workflow.o cadastrar_pedido_workflow.o 

C_FILES = main.c Models/encomenda.c Models/pedido.c Models/usuario.c \
Generators/id_generator.c Users/user_verification.c Data-structures/list_usuario.c Data-structures/queue_pedido.c \
Data-structures/bst_encomenda.c Workflows/cadastrar_encomenda_workflow.c Workflows/cadastrar_pedido_workflow.c

create:
	gcc $(OBJ_FILES)

comp: $(HEDERS_FILE)
	gcc -c $(C_FILES)

all: comp create

clean:
	rm -rf *.o
	find . -name \*.gch -delete