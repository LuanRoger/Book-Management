#include "id_generator.h"

int id_generator(BSTEncomendas* bst) {
    int id = 5000;
    srand(time(NULL));
    
    if(bst->root != NULL)
        id = rand() % 9999;

    return id;
}