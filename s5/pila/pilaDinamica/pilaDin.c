#include <stdio.h>
#include <stdlib.h>
#include "pilaDin.h"



struct pilaD *crearPila(){

    struct pilaD *pilaRetorno = (struct pilaD*)malloc(sizeof(struct pilaD));
    pilaRetorno->tope = NULL;

}

void apilar(struct pilaD *pilaInput, int elem){

    struct nodo *tempNode = (struct nodo*)malloc(sizeof(struct nodo));
    tempNode->dato = elem;

    if(pilaInput->tope == NULL){
        pilaInput->tope = tempNode;
        printf("El elemento %i, se ha apilado correctamente\n", pilaInput->tope->dato);  
    }
    
    else{
        tempNode->sig = pilaInput->tope;
        pilaInput->tope = tempNode;
        printf("El elemento %i, se ha apilado correctamente\n",pilaInput->tope->dato);
    }
}

int desapilar(struct pilaD *pilaInput){

if (pilaInput->tope != NULL)
{
    struct nodo *auxN = pilaInput->tope; // guardamos el nodo que se pierde
    int elementoRetorno = auxN->dato; 
    pilaInput->tope = pilaInput->tope->sig;     
    free(auxN);
    printf("El elemento fue desapilado exitosamente\n");
}
else
{
    printf("La matriz se encuentra vacia\n");
    printf("No fue posible eliminar el elemento\n");
}
}

int isEmpty(struct pilaD *pilaInput){
    if(pilaInput->tope == NULL){
        printf("La pila esta vacia\n");
        return 1;
    }
    else{

        printf("La pila contiene elementos\n");
        return 0;
    } 
}

int tope(struct pilaD *pilaInput){
    int topeRetorno = pilaInput->tope->dato; // estaba llamando la funcion asi pilaInput->tope //! lo cual retorna un puntero, no el dato almacenado en el puntero a tope
    printf("El elemento que se encuentra en el tope corresponde a: %i\n",topeRetorno);
    return topeRetorno;
}

void destruirPila(struct pilaD *pilaInput){
    while (pilaInput->tope != NULL){
        desapilar(pilaInput);
    }
}


