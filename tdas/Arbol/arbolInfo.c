#include <stdlib.h>
#include <stdio.h>


struct info
{
    char caracter;
    int number;

};


struct node {
    struct info *info;
    struct node *leftSon;
    struct node *rightSon;
};

//permite ingresar un entero y asignar el valor de info en el entero

struct info *crearInfo(int dataInput){

    struct info *infoReturn = (struct info*)malloc(sizeof(struct info));
    
    infoReturn->number = dataInput;
    
    return infoReturn;

};


struct node *crearNodo(int input){

    struct node *nodeReturn = (struct node*)malloc(sizeof(struct node));

    //se setean en null los hijos del arbol
    nodeReturn->leftSon = NULL;
    nodeReturn->rightSon = NULL;
    nodeReturn->info = crearInfo(input);

   
    return nodeReturn;

};

// se asume que la comprobacion de que el arbol no sea null, se realiza en el main
void insertarNodoOrdenado(struct node *tree, int inputNumber){

        

}



int main (){

    struct node *arbol = crearNodo(3);

    printf("%d", arbol->info->number);

}