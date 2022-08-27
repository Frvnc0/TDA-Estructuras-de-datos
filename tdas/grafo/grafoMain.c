#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
#include "listaDinamica.h"
#include "graph.h"

int main (){

    struct graph *grafo = createGraph(5);
    insertaArista(3,0,grafo);
    insertaArista(4,2,grafo);
    mostrarGrafo(grafo); 
    insertaArista(4,1,grafo);
    mostrarGrafo(grafo);
    pertenece_arista(grafo,3,0);


    remover_arista(grafo,4,0);
    mostrarGrafo(grafo);

    int *maxAndMin = maxAndMinGradeOfEachNode(grafo);
    printf("El maximo grado corresponde a %d\n",maxAndMin[0]);
    printf("El minimo grado corresponde a %d\n",maxAndMin[1]);

    int k = isKRegular(grafo);
//   int isSimple = isSimple(grafo); //! la expresión incluida delante del paréntesis de la llamada aparente debe tener un tipo de puntero a función 

    int simpleOrNot = isSimple(grafo); //esta funcion imprime bastantes valores, ya que las funciones a 
    //traves de las cuales lo implemente imprimern por defecto valores como si es que la lista se encuentra o no
    //vacia o si los elementos se encuentran y son retornados

}
