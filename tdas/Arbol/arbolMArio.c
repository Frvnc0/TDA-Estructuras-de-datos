#include <stdio.h>
#include <stdlib.h>

struct node {

    struct node *leftSon;
    struct node *rightBrother;
    int dato;
    int nivel;

};




void recorreGrafo(struct node *treeInput){

    struct node *aux = treeInput;

    if(treeInput->dato !=NULL){

        printf("El elemento corresponde a: %d",treeInput->dato);

    }

    if(treeInput->leftSon != NULL){

        treeInput->leftSon->nivel = treeInput->nivel +1;
        recorreGrafo(treeInput->leftSon);

    }

    if(treeInput->rightBrother != NULL){

        treeInput->rightBrother->nivel = treeInput->nivel;  
        recorreGrafo(treeInput->rightBrother);

    }

}


int main(){

    


}