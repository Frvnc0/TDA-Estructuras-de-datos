#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct linkedList{

    struct nodo *head;
    int n;

};

struct linkedList *crearLista (){// ok

    struct linkedList *returnList = (struct linkedList*)malloc(sizeof(struct linkedList)); // se genera espacio para el puntero
    returnList->head = NULL;
    returnList->n = 0;

}

// verifica si esta vacia la lista -> 1 si esta vacia ->0 si no esta vacia
int isEmpty(struct linkedList *listInput){//ok

    if (listInput->head == NULL){

        printf("La lista se encuentra vacia\n");
        return 1;
    
    }

    else{

        printf("La lista no se encuentra vacia\n");
        return 0;
    
    }

}

void LinkedListInsertaInicio(struct linkedList *listInput, struct nodo *nodoInput){ //ok

    nodoInput->next = listInput->head;
    listInput->head = nodoInput;
    listInput->n += 1;

}

// busca un entero en la lista, retornando la direccion del nodo en el cual se encuentra el valor buscado, si no lo encuentra imprime un mensaje por pantalla y retorna NULL
struct nodo *buscarEnLista(struct linkedList *listInput, int search ){ //ok
    int flag = 0;
    struct nodo *temp = listInput->head;// initialization
    
    if (isEmpty(listInput) == 1 ) // verificacion de si esta vacia
    {
        printf("La lista no posee elementos, imposible buscar el elemento\n");
        return NULL;
    }    

    while (temp != NULL)
    {
        if (temp->dato == search)
        {
            printf("El elemento fue hallado y retornado exitosamente\n");
            int flag = 1;
            return temp;
        }
        temp = temp->next;
    }
    if(flag == 0 ){
        printf("No se ha encontrado el elemento buscado en la lista\n");
        return NULL;
    }

}

//inserta un elemento despues de la posicion del elemento a insertar
void linkedListInsertInPosition(struct linkedList *listInput, int elementToInsert, int position){ // ok

    if(isEmpty(listInput) == 1){
        
        printf("El elemento fue insertado en la primera posicion\n");
        LinkedListInsertaInicio(listInput, crearNodo(elementToInsert));
        
    }
    
    else {

        struct nodo *nodoToInsert = crearNodo(elementToInsert); // nodo que sera insertado en la lista dinamica
        struct nodo *tempToBeInserted = buscarEnLista(listInput, position);
        struct nodo *nodoAux = tempToBeInserted->next; // nodo auxiliar donde se guarda la direccion de memoria del siguiente nodo del encontrado

        //asignacion de elementos
        tempToBeInserted->next = nodoToInsert;
        nodoToInsert->next = nodoAux;
        printf("El elemento fue insertado exitosamente\n");
        listInput->n ++;
    }

}


void linkedListDeleteFirst(struct linkedList *listInput){ // ok

    if ( isEmpty(listInput) == 1) { // si esta vacia
        printf("Imposible eliminar el primer elemento debido a que la lista se encontraba vacia\n");
    }

    else{
    
        struct nodo *aux = listInput->head;
        listInput->head = listInput->head->next;
        aux->next = NULL;
        printf("El primer nodo fue eliminado exitosamente\n");
        free(aux);
        listInput->n -=1;
    }

}




void printList(struct linkedList *listInput){

    struct nodo *temp = listInput->head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        printf("El elemento en la posicion %d corresponde a: %d\n", i , temp->dato);
        temp = temp->next;
    }

}

void actualizarLista(struct linkedList *listInput, int elementToUpdate, int elementToBeUpdated ){

    struct nodo *toBeUpdated = buscarEnLista(listInput, elementToBeUpdated); //busca el elemento a ser actualizado
    if (toBeUpdated == NULL){
        printf("No se ha logrado actualizar el elemento\n");
    }
    else
    {    
        toBeUpdated->dato = elementToUpdate; // actualiza el elemento
        printf("Se ha logrado actualizar el elemento exitosamente\n");
    }

};

int main (){

    struct linkedList *listaEnlazada = crearLista();
    LinkedListInsertaInicio(listaEnlazada, crearNodo(1));//1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(2));//2,1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(3));//3,2,1
    LinkedListInsertaInicio(listaEnlazada, crearNodo(4));//4,3,2,1,
    LinkedListInsertaInicio(listaEnlazada, crearNodo(5));//5,4,3,2,1

    printf("El valor del head es : %d\n", listaEnlazada->head->dato); //!!! error     print("El valor del head es : %d", listaEnlazada->head->dato);

    struct nodo *busqueda = buscarEnLista(listaEnlazada, 3);
    printf("El elemento buscado corresponde a %d\n", busqueda->dato);

    linkedListInsertInPosition(listaEnlazada, 3, 4);

    printList(listaEnlazada);

    linkedListDeleteFirst(listaEnlazada);

    printList(listaEnlazada);

    actualizarLista(listaEnlazada, 3, 20);

    printList(listaEnlazada);

}

