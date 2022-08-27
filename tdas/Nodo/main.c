#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"


int main(){
    
    struct nodo *nodoMain = crearNodo(3);
    struct nodo *nodoMain2 = crearNodo(4);

    setNodo(nodoMain, 4);
    setEnlaceNodo(nodoMain,nodoMain2);

    printf("El valor del nodo correponde a:  %d", nodoMain->dato);
    nodoMain = nodoMain->next;
    
    printf ("El valor del nodo iterado corresponde a: %d", nodoMain->dato);
    printf ("El valor del nodo iterado corresponde a: %d", getNodo(nodoMain2));
    return 0;
    }