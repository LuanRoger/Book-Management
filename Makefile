create:
	gcc main.o encomenda.o pedido.o usuario.o id_generator.o user_verification.o list.o queue.o bst.o

comp: Models/encomenda.h Models/pedido.h Models/usuario.h Generators/id_generator.h Users/user_verification.h Data-structures/list.h Data-structures/queue.h Data-structures/bst.h
	gcc -c main.c Models/encomenda.c Models/pedido.c Models/usuario.c Generators/id_generator.c Users/user_verification.c Data-structures/list.c Data-structures/queue.c  Data-structures/bst.c

clean:
	rm -rf *.o
	find . -name \*.gch -delete