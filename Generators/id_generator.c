#include "id_generator.h"

int id_generator(){
    int ids[15] = {500, 250, 750, 125, 325, 625, 875, 62, 187, 256, 581, 603, 650, 780, 937};
    
    static int count = 0;

    int id = ids[count];
    count++;
    return id;
}