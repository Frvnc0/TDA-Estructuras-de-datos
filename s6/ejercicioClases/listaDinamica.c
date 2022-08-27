#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "listaDinamica.h"
#include "cola.h"



struct linkedList *crearLista(){

    struct linkedList *lReturn = (struct linkedList*)malloc(sizeof(struct linkedList));
    lReturn->head = NULL;
    return lReturn;

};

void insertaInicio(struct linkedList *lInput, int elem){

    struct lNodo *nInput = crearNodo(elem);
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


void insertaFinal(struct linkedList *lInput, int elem){

    struct lNodo *temp = lInput->head;
    struct lNodo *nInput = crearNodo(elem);


    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nInput;

}

float promedioLinkedList(struct linkedList *lInput){


    float acum = 0;
    int count =0;
    struct lNodo *temp = lInput->head;
    
    
    while (temp->next != NULL)
    {
        count ++;
        acum = acum + temp->data;
    }
    
    return acum/count;
}


int main(){

    struct cola *colita = crearColita();
    struct linkedList *listita = crearLista();

    insertaInicio(listita,3);
    insertaInicio(listita,4);
    insertaInicio(listita,5);
    insertaInicio(listita,6);
    insertaInicio(listita,7);

    printf("El promedio corresponde a: %f", promedioLinkedList(listita));


}
