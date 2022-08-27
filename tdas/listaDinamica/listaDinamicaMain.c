#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "listaDinamica.h"



int main (){

    struct linkedList *listaEnlazada = crearLista();
    LinkedListInsertaInicio(listaEnlazada, crearNodo(1));//1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(2));//2,1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(3));//3,2,1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(4));//4,3,2,1,
    LinkedListInsertaInicio(listaEnlazada, crearNodo(5));//5,4,3,2,1

//    printf("El valor del head es : %d\n", listaEnlazada->head->dato); //!!! error     print("El valor del head es : %d", listaEnlazada->head->dato);

    struct nodo *busqueda = buscarEnLista(listaEnlazada, 3);
    
    printf("El elemento buscado corresponde a %d\n", busqueda->dato);

    linkedListInsertInPosition(listaEnlazada, 3, 4);

    printList(listaEnlazada);

    linkedListDeleteFirst(listaEnlazada);

    printList(listaEnlazada);

    actualizarLista(listaEnlazada, 3, 20);

    printList(listaEnlazada);

    linkedListDeleteLast(listaEnlazada);

    printList(listaEnlazada);

    linkedListDeleteInPosition(listaEnlazada,3);

    printList(listaEnlazada);    
    
}


