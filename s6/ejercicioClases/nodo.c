#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

struct lNodo *crearNodo(int inputData){

    struct lNodo *temp = (struct nodo*)malloc(sizeof(struct lNodo));
    temp->data = inputData;
    temp->next = NULL;
    return temp;

}
