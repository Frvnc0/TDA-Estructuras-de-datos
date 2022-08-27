#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"
#include "nodo.h"

//todo: operaciones de la lista enlazada programables
struct linkedList *crearLista (){// ok

    struct linkedList *returnList = (struct linkedList*)malloc(sizeof(struct linkedList)); // se genera espacio para el puntero
    returnList->head = NULL;
    returnList->n = 0;
    
    return returnList;

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

// busca un entero en la lista, retornando la direccion del nodo en el cual se encuentra el valor buscado, si no lo encuentra imprime un mensaje por pantalla y retorna NULL
struct nodo *buscarAnteriorEnLista(struct linkedList *listInput, int search ){ //ok
    int flag = 0;
    struct nodo *temp = listInput->head;// initialization
    
    if (isEmpty(listInput) == 1 ) // verificacion de si esta vacia
    {
        printf("La lista no posee elementos, imposible buscar el elemento\n");
        return NULL;
    }    


    if (temp->dato == search){
        printf("El primer elemento de la lista corresponde al elemento buscado");
    }
    while (temp != NULL)
    {
        
        if (temp->next->dato == search)
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

struct nodo *anterior(struct linkedList *listInput, int search){
    
    struct nodo *temp = listInput->head;

    while (temp->next->dato != search){
        
        temp = temp->next;

    }
    
    return temp;

}


void linkedListDeleteInPosition(struct linkedList *listInput, int search){

    if(isEmpty(listInput) == 1){

        struct nodo *auxToBeDeleted = buscarEnLista(listInput,search);        
        if (auxToBeDeleted != NULL){
            if(auxToBeDeleted == listInput->head){
                
                linkedListDeleteFirst(listInput);
            
            }
            else{
                if (auxToBeDeleted->next == NULL)
                {
                    linkedListDeleteLast(listInput);
                }
                else
                {

                    auxToBeDeleted = anterior(listInput, search);

                }
                
                
            }
            printf("El nodo de la posicion %d, fue eliminado exitosamente",search);
            
        }
    }


}


//funcion que solo es posible de ser utilizada si es que la lista no se encuentra vacia
struct nodo *penultimate(struct linkedList *listInput){

    struct nodo *temp = listInput->head;

    while (temp->next->next != NULL){

        temp = temp->next;
    
    }

    return temp;

}

void linkedListDeleteLast(struct linkedList *listInput){
 
    if (isEmpty(listInput)== 0){

        struct nodo *aux = penultimate(listInput);
        struct nodo *auxToBeDeleted= aux->next;
        free(auxToBeDeleted);
        aux->next = NULL;
        printf("El nodo fue eliminado exitosamente\n");

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
