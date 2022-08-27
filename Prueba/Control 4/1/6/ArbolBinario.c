#include <stdio.h>
#include <stdlib.h>



struct info{
    char dato;
    int nivel;
    int visitado;
    char predecesor;
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








struct info* createInfo(char input){

    struct info *infoReturn = (struct info*)malloc(sizeof(struct info));
    infoReturn->dato = input;
    infoReturn->visitado = 0;

    return infoReturn;


}


struct node* createTree(char dato){

    struct node *tree = (struct node*)malloc(sizeof(struct node));
    tree->info = createInfo(dato);
    tree->leftSon = NULL;
    tree->rightSon = NULL;
    return tree;

};



// el paso clave en esta recursion, corresponde a poder utilizar la variable aux para poder llamar la recursion
// en varias ocasiones
//busca un elemento en el arbol -> null si no lo encuentra, -> direccion del elemento si lo encuentra
struct node *searchInTree(struct node *tree, char searchInput ){

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
int insert(struct node *T,char father, char x){

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

int countLeafs(struct node *tree){
    
    if(tree->leftSon != NULL && tree->rightSon != NULL){

        return countLeafs(tree->leftSon) + countLeafs(tree->rightSon);

    }
    else
    {
        return 1;
    }
    
}

int isLeaf(struct node *tree){

    if(tree->leftSon == NULL && tree->rightSon == NULL){
        return 1;
    }
    else
    {
        return 0;
    }
    

}

void inOrdenPrintingNodesAndLevels(struct node *tree){

    if(tree == NULL){
        return;
    }

    inOrdenPrintingNodesAndLevels(tree->leftSon);
    printf("El nivel del elemento %c, corresponde a %d \n",tree->info->dato, tree->info->nivel);
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


int levelOfNode(struct node *tree, char search){

    BFSTree(tree,0); // se realiza el BFS

    struct node *nodeReturn = searchInTree(tree,search); // se busca el nodo

    return nodeReturn->info->nivel; // se retorna el nivel del nodo 

}

int countNodes(struct node *tree){

    if(tree == NULL){
        return 0;
    }
    else{
        return countNodes(tree->leftSon) + countNodes(tree->rightSon) + 1 ;
    }

}


int deepOfNode(struct node *tree, char search){

    BFSTree(tree,0);
    struct node *searchedDeepReturn = searchInTree(tree, search);
    return searchedDeepReturn->info->nivel;

}

int heightNode(struct node *tree, char searched){

    if(tree == NULL){
        return 0;
    }
    
    else
    {
        if(heightNode(tree->leftSon, searched)+1 >= heightNode(tree->rightSon, searched)+1){

            return heightNode(tree->leftSon, searched)+1;
        }

        else
        {
            return heightNode(tree->rightSon, searched)+1;
        }
        

    }
    

}



int main (){

    struct node *tree = createTree('A'); 

    insert(tree, 'A','B');
    insert(tree, 'A','C');
    insert(tree, 'B','E');
    insert(tree, 'B','F');
    insert(tree, 'E','I');
    insert(tree, 'E','J');
    insert(tree, 'F','K');
    insert(tree, 'F','L');
    insert(tree, 'F','L');
    insert(tree, 'C','D');
    insert(tree, 'C','X');
    insert(tree, 'D','G');
    insert(tree, 'D','H');
    insert(tree, 'X','Z');

    struct node *searched = searchInTree(tree, 'B');
    
    struct node *fatherSearched  = searchFather(tree, 'B');
    printf("test");

    printf("El nodo buscado corresponde a: %c \n", searched->info->dato);    
    printf("El padre del nodo buscado corresponde a: %c \n", fatherSearched->info->dato);    

    int quantifyOfNodes = countNodes(tree);
    printf("La cantidad de nodos existentes en el arbol corresponde a: %d\n", quantifyOfNodes);

    int quantifyOFLeafs = countLeafs(tree);
    printf("La cantidad de hojas existentes en el arbol, corresponde a: %d", quantifyOFLeafs);

    BFSTree(tree,0);


//todo: se realizan verificaciones de los niveles de los nodos correspondientes
    printf("El nivel de la raiz corresponde a: %d\n",tree->info->nivel);
    printf("El nivel del hijo izquierdo de la raiz corresponde a: %d\n",tree->leftSon->info->nivel);
    printf("el nivel mas bajo: %d\n", tree->leftSon->leftSon->leftSon->info->nivel);

    inOrdenPrintingNodesAndLevels(tree);
    
    char search = 'C';
    printf("El nivel del elemento ,%c, corresponde a %d\n", search, levelOfNode(tree, search));
    printf("La altura desde el nodo %c, a la raiz corresponde a %d",search, heightNode(tree->rightSon, search));




}
