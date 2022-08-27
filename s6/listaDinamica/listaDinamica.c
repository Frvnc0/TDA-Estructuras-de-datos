#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "listaDinamica.h"






struct linkedList *crearLista(){

    struct linkedList *lReturn = (struct linkedList*)malloc(sizeof(struct linkedList));
    lReturn->head = NULL;
    return lReturn;

};

void insertaInicio(struct linkedList *lInput, int elem){

    struct Nodo *nInput = crearNodo(elem);
    if (lInput->head == NULL)
    {
        lInput->head = nInput;    
    }
    else
    {
        nInput->next = lInput->head;
        lInput->head = nInput;
    }

}
/* 
void insertaNodo(struct linkedList *lInput, int elemInput, int elem){
    
    struct lNodo *nodoInput = crearNodo (elemInput);
    
    struct lNodo *temp = lInput->head;
    struct lNodo *aux = lInput->head;
    
    
    while(temp->next != elem){

        temp = temp->next

    }
    

}

 */
void insertaFinal(struct linkedList *lInput, int elem){

    struct Nodo *temp = lInput->head;
    struct Nodo *nInput = crearNodo(elem);


    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nInput;

}


int main(){

    struct linkedList *lista = crearLista();


}
