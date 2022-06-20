create:
	gcc main.o encomenda.o id_generator.o user_verification.o

comp: Models/encomenda.h Generators/id_generator.h Users/user_verification.h
	gcc -c main.c Models/encomenda.c Generators/id_generator.c  Users/user_verification.c

clean:
	rm -rf *.o
	find . -name \*.gch -delete