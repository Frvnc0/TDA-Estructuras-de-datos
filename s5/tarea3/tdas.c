#include <stdio.h>
#include<stdlib.h>
#include "tdas.h"

struct nodo *crearNodo(int value){
    struct nodo *tempNode = (struct nodo*)malloc(sizeof(struct nodo));
    tempNode->next =NULL;
    tempNode->dato = value;
    return tempNode;
}

struct cola *crearColita(){
    struct cola *colita = (struct cola*)malloc(sizeof(struct cola));
    colita->nodFin = NULL;
    colita->nodIni = NULL;
    return colita;
}

void encolar(struct cola *cola, int elem){
    struct nodo *tempNode = crearNodo(elem);
    
    if(cola->nodIni == NULL){
        cola->nodIni = tempNode;
        cola->nodFin = tempNode;
    }
    else
    {
        cola->nodFin->next = tempNode;
        cola->nodFin =tempNode;
    }
}


// recibe una cola y printea el ultimo elemento de la cola
void desencolar(struct cola *cola){
  
    if (cola->nodIni == NULL)
    {
        printf("La cola esta vacia");    
    }
    else
    {

        struct nodo *aux = cola->nodIni;
        printf("El elemento: %i, fue desapilado", aux->dato);
        cola->nodIni = cola->nodIni->next;
        aux->next = NULL;
        free(aux);

    }

}

int frente(struct cola *colaEnt){
    
    if (colaEnt->nodIni != NULL){
        int retorno = colaEnt->nodIni->dato;
        return retorno;
    }
    
}
void desencolarTodo(struct cola *colaEnt){
    
    struct nodo *auxNode = colaEnt->nodIni;
    int i = 0;
    while (auxNode != NULL)
    {
        printf("El elemento %i, corresponde a: %i",i, auxNode->dato);
        auxNode = auxNode->next;
        i++;
    }
}




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
        tempNode->next = pilaInput->tope;
        pilaInput->tope = tempNode;
        printf("El elemento %i, se ha apilado correctamente\n",pilaInput->tope->dato);
    }
}

int desapilar(struct pilaD *pilaInput){

if (pilaInput->tope != NULL)
{
    struct nodo *auxN = pilaInput->tope; // guardamos el nodo que se pierde
    int elementoRetorno = auxN->dato; 
    pilaInput->tope = pilaInput->tope->next;     
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


