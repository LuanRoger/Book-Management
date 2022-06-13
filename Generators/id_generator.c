#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int id_generator(){
    srand(time(NULL));

    int id = rand() % 9999;
    return id;
}