#include <stdlib.h>
#include <stdio.h>
#include "listaDinamica.h"
#include "graph.h"

int main (int argc, char *argv[]){

    float averageWeight = 0;
    struct graph *grafo = leerArchivo(argv[1], &averageWeight);

 

    printf("El numero de aristas del grafo es : %d" , grafo->nE);
    mostrarGrafo(grafo);

    printf("El grado promedio del grafo, corresponde a %f\n", averageGrade(grafo));

    printf("El peso promedio del grafo corresponde a %f, la cantidad de aristas que exceden el peso promedio corresponden a %d\n", averageWeight, leerArchivoAristas(argv[1],averageWeight));

    printf("La densidad del grafo corresponde a: %f",densidadGrafo(grafo));

}
