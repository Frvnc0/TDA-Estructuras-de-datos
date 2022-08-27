#include <stdio.h>
#include <stdlib.h>
#include "arreglo.h"


// esta funcion crea un arreglo como puntero y retorna un puntero 
struct arreglo *crearArreglo( int largo ){

    struct arreglo *A = (struct arreglo*)malloc(sizeof(struct arreglo));
    A->lista = (int*)malloc(sizeof(int)*largo);
    A->largoUtilizado = 0;
    return A;
}


//esta funcion retorna la posicion del elemento buscado
int buscarElemento(struct arreglo *A, int search){
    for (int i = 0; i < A->largoTotal; i++)
    {
        if (A->lista[i]== search)
        {
            return i;
        }
    }
}
// esta funcion agrega un elemento al final del arreglo
int agregarElemento(struct arreglo *A, int elem){

    if (A->largoUtilizado == A->largoTotal)
    {
        printf("El arreglo esta lleno, no es posible insertar mas elementos");
        return 0;     
    }
    else
    {
    
        A->lista[A->largoUtilizado] = elem;
        A->largoUtilizado = A->largoUtilizado +1;
        return 1;
    }
    
}


//funcion que recibe como parametro un arreglo, un elemento a ser eliminado del array
void eliminarElemento(struct arreglo *A, int elemEliminado ){
    
    int eliminar = buscarElemento(A,elemEliminado);
    
    for (int  i = eliminar; i < A->largoUtilizado-1; i++)
    {
        A->lista[i] = A->lista[i+1];
    }
     // indicando que el elemento fue retornado exitosamente
}

void mostrarArreglo(struct arreglo *A){
    
    for (int i = 0; i < A->largoUtilizado; i++)
    {
        printf("%c", A->lista[i]);
    }

}