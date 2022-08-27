#include <stdio.h>
#include <stdlib.h>
#include "grafoEstatico.h"


struct graph *crearGrafo(int v){

    struct graph *grafoRetorno = (struct graph*)malloc(sizeof(struct graph));    
    grafoRetorno->v = v;
    grafoRetorno->a = 0;
    int **matrizAdyacencia = (int**)malloc(sizeof(int*)*v);
    
    for (int i = 0; i < v; i++)
    {
        matrizAdyacencia[i] = (int*)malloc(sizeof(int)*v);

        for (int j = 0; j < v; j++)
        {
            matrizAdyacencia[i][j] = 0;
        }
        
    }
    
    grafoRetorno->matrizAdyacencia = matrizAdyacencia;

    return grafoRetorno;
}

void insertarArista(struct graph *grafoInput, int vertice1, int vertice2){


    //indicamos bidireccionalidad
    grafoInput->matrizAdyacencia[vertice1][vertice2] = 1;

    grafoInput->matrizAdyacencia[vertice2][vertice1] = 1;

    grafoInput->a += 2; //indicando que son dos los elementos que se conectan a traves de una arista
}


int *crearArista(int vertice1, int vertice2){

    int *arista = (int*)malloc(sizeof(int));
    arista[0] = vertice1;
    arista[1] = vertice2;

    return arista;
}

int obtenerGrado(struct graph *grafoInput , int vertice){

    int acum = 0;

    for (int i = 0; i < grafoInput->v; i++)
    {
        if (grafoInput->matrizAdyacencia[vertice][i] == 1)
        {
            acum += 1;
        }
        
    }
    
    printf("El grado corresponde a: %d", acum);
    
    return acum;

}



int main(){

    struct graph *grafoMain = crearGrafo(4); 
    insertarArista(grafoMain,1,4);
    obtenerGrado(grafoMain, 4); 

}