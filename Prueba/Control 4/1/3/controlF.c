#include<stdio.h>
#include <stdlib.h>



struct info{
    int dato;
    int nivel;
    int visitado;
};

struct node{

    struct info *info;
    struct node *leftSon;
    struct node *rightSon;


};


//todo: operaciones de una cola
struct nodeQueue{

    char data;
    struct nodeQueue *next;

};



struct queue{

    struct nodeQueue *nodIni;
    struct nodeQueue *nodFin;

};


//TODO: OPERACIONES DE COLAS

struct queue *createQueue(){
    
    struct queue *queueReturn = (struct queue*)malloc(sizeof(struct queue));
    queueReturn->nodIni= NULL;
    queueReturn->nodFin = NULL;
    return queueReturn;

}

struct nodeQueue *createQueueNode(char dataInput){
    
    struct nodeQueue *nodeReturn = (struct nodeQueue*)malloc(sizeof(struct nodeQueue));
    nodeReturn->data = dataInput;
    nodeReturn->next = NULL; 
    return nodeReturn;
    
}


void enqueue(struct queue *qInput, char dato){
    
    struct nodeQueue *aux = qInput->nodIni;
    
    if(aux == NULL){
    
        qInput->nodIni = createQueueNode(dato);
        qInput->nodFin = qInput->nodIni;

    }
    else
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        
        aux->next = createQueueNode(dato);
        qInput->nodFin = aux->next;

    }
}

char dequeue(struct queue *queueInput){

    if(queueInput->nodIni != NULL){

        char charReturn = queueInput->nodIni->data;
        queueInput->nodIni = queueInput->nodIni->next;        
        return charReturn;

    }    

}






//TODO: OPERACIONES DE ARBOL

struct info* createInfo(int input){

    struct info *infoReturn = (struct info*)malloc(sizeof(struct info));
    infoReturn->dato = input;
    infoReturn->visitado = 0;

    return infoReturn;


}


struct node* createTree(int dato){

    struct node *tree = (struct node*)malloc(sizeof(struct node));
    tree->info = createInfo(dato);
    tree->leftSon = NULL;
    tree->rightSon = NULL;
    return tree;

};



// el paso clave en esta recursion, corresponde a poder utilizar la variable aux para poder llamar la recursion
// en varias ocasiones
//busca un elemento en el arbol -> null si no lo encuentra, -> direccion del elemento si lo encuentra
struct node *searchInTree(struct node *tree, int searchInput ){

    if(tree->info->dato == searchInput){
        return tree;
    }

    else
    {
        struct node *aux = NULL;
        
        if(tree->leftSon != NULL){
            aux = searchInTree(tree->leftSon, searchInput);
        }

        if(aux != NULL && aux->info->dato == searchInput){
            return aux;
        }

        else
        {
            if(tree->rightSon != NULL){
                aux = searchInTree(tree->rightSon, searchInput);
            }
            if(aux != NULL && aux->info->dato == searchInput){
                return aux;
            }
        }

        return NULL;
    }
}


// inserta un nodo -> 1 si la insercion fue exitosa -> -0 si la insercion no fue exitosa
void insert(struct node *T,int father, int x){

    struct node *searched = searchInTree(T,father); // se busca el nodo padre

    if (searched == NULL){
        printf("No se ha encontrado al padre del nodo");
    }
    else
    {
        if(searched->leftSon == NULL){
            searched->leftSon = createTree(x);
        }
        else
        {
            searched->rightSon = createTree(x);
        }
        
    }
    
};


//TODO: OPERACION ARCHIVO


int *leerArchivo(char *nombreArchivo, int *quantifyOfnodes)
{

    FILE *fp = fopen("tree.txt", "r");

    fscanf(fp, "%d", quantifyOfnodes); // se obtiene la cantidad de iteraciones que se deben realizar
    int stop = *quantifyOfnodes;

    int *arrRepresentationReturn = (int*)malloc(sizeof(int)*stop); // se reserva el espacio para el array que sera retornado
    



    for (int i = 0; i < stop; i++) // ! posible bug
    {
        fscanf(fp, "%d", &arrRepresentationReturn[i]);
    }

    return arrRepresentationReturn;
}

struct node *veirifyTreeCreation (int *arrRepresentation, int quantifyOfNodes  ){

    if(arrRepresentation[0] == -1){

        struct node *treeReturn = createTree(0);
    
        int stop = quantifyOfNodes;
        printf("%d", stop);

        for (int i = 1; i < stop; i++)
        {
            insert(treeReturn,arrRepresentation[i],i);
        }
        
        return treeReturn;
    
    }

}


int main(){

    struct node *treeMain =   createTree(0);

    int quantifyOfnodes;
    int *arrRepresentation = leerArchivo("tree.txt",&quantifyOfnodes);

    struct node *tree = veirifyTreeCreation(arrRepresentation,quantifyOfnodes);

    printf("%d", )    

    printf("Recorrido en preOrden: \n");



}
