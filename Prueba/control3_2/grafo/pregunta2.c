#include <stdlib.h>
#include <stdio.h>
#include "listaDinamica.h"
#include "graph.h"

int main (int argc, char *argv[]){

    float averageWeight = 0;
    struct graph *grafo = leerArchivo(argv[1], &averageWeight);
    mostrarGrafo(grafo);
    int *pred = (int*)malloc(sizeof(int)*grafo->nV);
    int *weight = (int*)malloc(sizeof(int)*grafo->nV);
    
    //prim(grafo, pred, weight); //se intenta implementa prim, pero de momentono se logra exitosamente

}
