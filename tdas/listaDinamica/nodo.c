#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

// crea un nodo 
struct nodo *crearNodo(int dato){

    struct nodo *temp = (struct nodo*)malloc(sizeof(struct nodo));
    temp->dato = dato;
    temp->next = NULL;
    
    return temp;
}

void setNodo(struct nodo *nodo, int dato){
    nodo->dato = dato;
}

void setEnlaceNodo (struct nodo *prevNode, struct nodo *nextNode ){
    prevNode->next = nextNode;
}

int getNodo( struct nodo *nodo){
    return nodo->dato;
}
