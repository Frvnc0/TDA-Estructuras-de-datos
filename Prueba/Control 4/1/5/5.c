#include <stdio.h>
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


void enqueue(struct queue *qInput, int dato){
    
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

        int charReturn = queueInput->nodIni->data;
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

        return aux;
    }
}

struct node *searchFather(struct node *treeInput, int x){

    if(treeInput->leftSon->info->dato == x || treeInput->rightSon->info->dato == x){
        
        return treeInput;
    }

    else
    {

    struct node *searched = NULL;
    searched = searchFather(treeInput->leftSon, x);
        if( searched != NULL && searched->info->dato == x){
            return searched; // en caso de que encuentre al padre
        }

        else
        {
            
            searched = searchFather(treeInput->rightSon, x);
            if(searched != NULL && searched->info->dato == x){
                return searched;
            }

            else{
                return searched;
            }

        }
        

    }
}


// inserta un nodo -> 1 si la insercion fue exitosa -> -0 si la insercion no fue exitosa
int insert(struct node *T,int father, int x){

    struct node *searched = searchInTree(T,father); // se busca el nodo padre

    if (searched == NULL){
        printf("No se ha encontrado al padre del nodo");
        return 0;
    }
    else if (searched->leftSon == NULL)
    {
        searched->leftSon = createTree(x); 
        return 1;
    }
    else if (searched->rightSon == NULL)
    {
        searched->rightSon = createTree(x);
        return 1;
    }

};


void inOrdenPrintingNodesAndLevels(struct node *tree){

    if(tree == NULL){
        return;
    }

    inOrdenPrintingNodesAndLevels(tree->leftSon);
    printf("El nivel del elemento %d, corresponde a %d \n",tree->info->dato, tree->info->nivel);
    inOrdenPrintingNodesAndLevels(tree->rightSon);

}

//todo: recorridos de grafos
void BFSTree(struct node *tree, int nivel){

    struct queue *q = createQueue();
    enqueue(q, tree->info->dato);
    tree->info->nivel = nivel;

    while (q->nodIni != NULL)
    {

        struct node *visit = searchInTree(tree,dequeue(q)); // se busca el nodo desencolado, para poder marcarlo como visitado //! estoy asignando a un nodo visit, el char de dequeue

        visit->info->visitado = 1;// marcamos el nodo como visitado


        if(visit->leftSon != NULL && visit->leftSon->info->visitado == 0){ // si el hijo izquierdo es no nulo y ademas, no esta visitado, encolalo y mrcalo visitado
        
            visit->info->visitado =1;
            visit->leftSon->info->nivel = visit->info->nivel+1;
            enqueue(q,visit->leftSon->info->dato); // se encolan los nodos adyacentes al elemento visitado

        }
        
        if(visit->rightSon != NULL && visit->rightSon->info->visitado == 0){
        
            visit->info->visitado =1;
            visit->rightSon->info->nivel = visit->info->nivel+1;
            enqueue(q,visit->rightSon->info->dato); // se encolan los nodos adyacentes al elemento visitado
        
        }

    }


}

int *leerArchivo(char *nombreArchivo, int *quantifyOfnodes)
{

    FILE *fp = fopen("tree.txt", "r");

    fscanf(fp, "%d", quantifyOfnodes); // se obtiene la cantidad de iteraciones que se deben realizar
    int *arrRepresentationReturn = (int*)malloc(sizeof(int)); // se reserva el espacio para el array que sera retornado
    int stop = *quantifyOfnodes;

    int aux;

    for (int i = 0; i < stop; i++) // ! posible bug
    {
        fscanf(fp, "%d", &arrRepresentationReturn[i]);
        
    }

    return arrRepresentationReturn;

}

struct node *verifyTreeCreation(int *arrRepresentation, int quantifyOfNodes){

    int iter = quantifyOfNodes;

    if(arrRepresentation[0] == -1){

        struct node * treeReturn = createTree(0);

        printf("%d", treeReturn->info->dato);
        for (int i = 1; i < iter; i++)
        {
            insert(treeReturn, arrRepresentation[i],i);
        }
        
    }

}



int main (){

    int quantifyOfNodes;
    int *arrRepresentation = leerArchivo("tree.txt", &quantifyOfNodes);

    printf("%i", arrRepresentation[2]);

    struct node *tree = verifyTreeCreation(arrRepresentation,quantifyOfNodes);


    return 0;
}