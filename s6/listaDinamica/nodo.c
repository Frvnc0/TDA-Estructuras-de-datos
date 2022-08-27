#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

struct Nodo* crearNodo(int inputData){

    struct Nodo *temp = (struct Nodo*)malloc(sizeof(struct Nodo));
    temp->data = inputData;
    temp->next = NULL;
    return temp;

}
