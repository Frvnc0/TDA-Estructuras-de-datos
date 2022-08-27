#include <stdio.h>
#include <stdlib.h>



struct info{
    int dato;
    int nivel;
    int visitado;
    int predecesor;
};

struct node{

    struct info *info;
    struct node *leftSon;
    struct node *rightSon;


};


//todo: operaciones de una cola
struct nodeQueue{

    int data;
    struct nodeQueue *next;

};



struct queue{

    struct nodeQueue *nodIni;
    struct nodeQueue *nodFin;

};

struct queue *createQueue(){
    
    struct queue *queueReturn = (struct queue*)malloc(sizeof(struct queue));
    queueReturn->nodIni= NULL;
    queueReturn->nodFin = NULL;
    return queueReturn;

}

struct nodeQueue *createQueueNode(int dataInput){
    
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

int dequeue(struct queue *queueInput){

    if(queueInput->nodIni != NULL){

        char charReturn = queueInput->nodIni->data;
        queueInput->nodIni = queueInput->nodIni->next;        
        return charReturn;

    }    

}








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
struct node *searchInTree(struct node *tree, int searchInput){

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




int *leerArchivo(char *nombreArchivo, int *quantifyOfnodes)
{

    FILE *fp = fopen("tree.txt", "r");

    fscanf(fp, "%d", quantifyOfnodes); // se obtiene la cantidad de iteraciones que se deben realizar

    int *arrRepresentationReturn = (int *)malloc(sizeof(int)); // se reserva el espacio para el array que sera retornado
    int stop = *quantifyOfnodes;
    int aux;

    for (int i = 0; i < stop; i++) // ! posible bug
    {
        fscanf(fp, "%d", &arrRepresentationReturn[i]);
    }

    return arrRepresentationReturn;
}

struct node *verifyTreeCreation(int *arrTreeRepresentation, int quantifYOfnodes)
{

    int iter = quantifYOfnodes;

    if (arrTreeRepresentation[0] == -1)
    {

        struct node *treeReturn = createTree(0);

        printf("La raiz del ar %d",treeReturn->info->dato);

        for (int i = 1; i < iter; i++)
        {
            insert(treeReturn, arrTreeRepresentation[i], i); // se insertan cada uno de los nodos en la posicion de desreferenciacion y se inserta el elemento i
            printf("hola");
        }

        return treeReturn;

    }

}



int main(){


    int quantifyOfNodes;

    int *arrayRepresentation = leerArchivo("tree.txt", &quantifyOfNodes);

    struct node *tree = verifyTreeCreation(arrayRepresentation, quantifyOfNodes);



}