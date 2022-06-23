#include "../Models/encomenda.h"
#include "../Data-structures/bst_encomenda.h"
#include "../Generators/id_generator.h"

#ifndef CADASTRAR_ENCOMENDA_WORKFLOW_H
#define CADASTRAR_ENCOMENDA_WORKFLOW_H

#define STRING_BUFFER_SIZE 256*sizeof(char)

Encomenda* CadastrarEncomendaWorkflow(int id);

#endif