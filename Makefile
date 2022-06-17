create:
	gcc main.o encomenda.o id_generator.o

comp: Models/encomenda.h Generators/id_generator.h 
	gcc -c main.c Models/encomenda.c Generators/id_generator.c 

clean:
	rm -rf *.o
	find . -name \*.gch -delete