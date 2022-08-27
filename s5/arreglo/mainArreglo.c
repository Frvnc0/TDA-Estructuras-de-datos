#include <stdio.h>
#include <stdlib.h>
#include "arreglo.h"


int main(){
    struct arreglo *A = crearArreglo(5);
    printf("Arreglo creado");
    int agregar = agregarElemento(A, 4);
    printf("Elemento agregado %i", A->lista[0]);
}