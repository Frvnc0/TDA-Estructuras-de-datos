#include <stdio.h>
#include<stdlib.h>
#include "cola.h"


//CREA UN NODO Y SETEA NEXT EN NULL, RETORNA UN NODO
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

