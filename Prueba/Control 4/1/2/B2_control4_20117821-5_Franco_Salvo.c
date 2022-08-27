#include <stdio.h>
#include <stdlib.h>

// se escoge representar el arbol como un arbol binario, ya que del patron de entradas, se asume
// que cada uno de l

// TODO: STRUCT ARBOL

struct info
{
    int dato;
    int nivel;
    int visitado;
    char predecesor;
};

struct node
{

    struct info *info;
    struct node *leftSon;
    struct node *rightSon;
};

// TODO: STRUCT COLA

struct nodeQueue
{

    char data;
    struct nodeQueue *next;
};

struct queue
{

    struct nodeQueue *nodIni;
    struct nodeQueue *nodFin;
};

// TODO: OPERACIONES DE COLA

struct queue *createQueue()
{

    struct queue *queueReturn = (struct queue *)malloc(sizeof(struct queue));
    queueReturn->nodIni = NULL;
    queueReturn->nodFin = NULL;
    return queueReturn;
}

struct nodeQueue *createQueueNode(char dataInput)
{

    struct nodeQueue *nodeReturn = (struct nodeQueue *)malloc(sizeof(struct nodeQueue));
    nodeReturn->data = dataInput;
    nodeReturn->next = NULL;
    return nodeReturn;
}

void enqueue(struct queue *qInput, char dato)
{

    struct nodeQueue *aux = qInput->nodIni;

    if (aux == NULL)
    {

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

char dequeue(struct queue *queueInput)
{

    if (queueInput->nodIni != NULL)
    {

        char charReturn = queueInput->nodIni->data;
        queueInput->nodIni = queueInput->nodIni->next;
        return charReturn;
    }
}

// TODO: OPERACIONES DE ARBOLES

struct info *createInfo(int input)
{

    struct info *infoReturn = (struct info *)malloc(sizeof(struct info));
    infoReturn->dato = input;
    infoReturn->visitado = 0;
    return infoReturn;

}

// 
struct node *createTree(int dato)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->info = createInfo(dato);
    tree->leftSon = NULL;
    tree->rightSon = NULL;
    return tree;
};

// verifica si un nodo es hoja: si no es hoja -> 0, si es hoja -> 1
int isLeaf(struct node *tree)
{

    if (tree->leftSon == NULL && tree->rightSon == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
// el paso clave en esta recursion, corresponde a poder utilizar la variable aux para poder llamar la recursion
// en varias ocasiones

// busca un elemento en el arbol -> null si no lo encuentra, -> direccion del elemento si lo encuentra
struct node *searchInTree(struct node *tree, int searchInput)
{

    if (tree->info->dato == searchInput)
    {
        return tree;
    }

    else
    {
        struct node *aux = NULL;

        if (tree->leftSon != NULL)
        {
            aux = searchInTree(tree->leftSon, searchInput);
        }

        if (aux != NULL && aux->info->dato == searchInput)
        {
            return aux;
        }

        else
        {
            if (tree->rightSon != NULL)
            {
                aux = searchInTree(tree->rightSon, searchInput);
            }
            if (aux != NULL && aux->info->dato == searchInput)
            {
                return aux;
            }
        }

        return aux;
    }
}


// inserta un nodo en la posicion especificada del padre
// arbol, nodo padre y un nodo a insertar, -> 0 si no fue posible la insercion, 1 si la insercion fue exitosa
int insert(struct node *T, int father, int x)
{

    struct node *searched = searchInTree(T, father); // se busca el nodo padre

    if (searched == NULL)
    {
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

//arbol -> imprime los nodos y sus profundidades de todo el arbol
void printingNodesAndDeeps(struct node *tree)
{

    if (tree == NULL)
    {
        return;
    }

    if (isLeaf(tree))
    {
        printf("La profundidad del elemento %d, corresponde a: %d \n", tree->info->dato, tree->info->nivel);
    }
    else
    {
        printingNodesAndDeeps(tree->leftSon);
        printf("La profundidad del elemento %d, corresponde a: %d \n", tree->info->dato, tree->info->nivel);
        printingNodesAndDeeps(tree->rightSon);

    }
    

}

// TODO: OPERACIONES PROPIAS DEL PROGRAMA
// se verifica que el primer elemento corresponde al -1, para poder proceder a la insercion de los nodos en el arbol
//arreglo de enteros, cantidad de nodos -> arbol creado
struct node *verifyTreeCreation(int *arrTreeRepresentation, int quantifYOfnodes)
{

    int iter = quantifYOfnodes;

    if (arrTreeRepresentation[0] == -1)
    {

        struct node *treeReturn = createTree(0);

        for (int i = 1; i < iter; i++)
        {
            insert(treeReturn, arrTreeRepresentation[i], i); // se insertan cada uno de los nodos en la posicion de desreferenciacion y se inserta el elemento i
        }

        return treeReturn;
    }
}


//TODO: RECORRIDOS DE ARBOLES
//recorrido en preOrden recibe el arbol e imprime los nodos
void preOrden(struct node *tree)
{

    if (tree == NULL)
    {
        return;
    }

    if (isLeaf(tree))
    {
        printf("%d\n", tree->info->dato);
    }
    else
    {

        printf("%d\n", tree->info->dato);
        preOrden(tree->leftSon);
        preOrden(tree->rightSon);
    }
}
//recorrido en inOrden recibe el arbol e imprime los nodos
void inOrden(struct node *tree)
{

    if (tree == NULL)
    {
        return;
    }

    if (isLeaf(tree))
    {
        printf("%d\n", tree->info->dato);
    }
    else
    {

        inOrden(tree->leftSon);
        printf("%d\n", tree->info->dato);
        inOrden(tree->rightSon);
    }
}
//recorrido en postOrden recibe el arbol e imprime los nodos
void postOrden(struct node *tree)
{

    if (tree == NULL)
    {
        return;
    }

    if (isLeaf(tree))
    {
        printf("%d\n", tree->info->dato);
    }
    else
    {

        postOrden(tree->leftSon);
        postOrden(tree->rightSon);
        printf("%d\n", tree->info->dato);
    }
}

// TODO : RECORRIDOS DE GRAFOS

//recorrido simple por amplitud
void BFSTree(struct node *tree, int nivel)
{

    struct queue *q = createQueue();
    enqueue(q, tree->info->dato);
    tree->info->nivel = nivel;

    printf("El nivel del elemento %d, corresponde a :%d\n", tree->info->dato,tree->info->nivel );

    while (q->nodIni != NULL)
    {

        struct node *visit = searchInTree(tree, dequeue(q)); // se busca el nodo desencolado, para poder marcarlo como visitado //! estoy asignando a un nodo visit, el char de dequeue

        visit->info->visitado = 1; // marcamos el nodo como visitado

        if (visit->leftSon != NULL && visit->leftSon->info->visitado == 0)
        { // si el hijo izquierdo es no nulo y ademas, no esta visitado, encolalo y mrcalo visitado

            visit->info->visitado = 1;
            visit->leftSon->info->nivel = visit->info->nivel + 1;
            enqueue(q, visit->leftSon->info->dato); // se encolan los nodos adyacentes al elemento visitado
        
            //todo: printingByLevels
            printf("El nivel de elemento %d, corresponde a :%d\n", visit->leftSon->info->dato, visit->leftSon->info->nivel);
        
        }

        if (visit->rightSon != NULL && visit->rightSon->info->visitado == 0)
        {

            visit->info->visitado = 1;
            visit->rightSon->info->nivel = visit->info->nivel + 1;
            enqueue(q, visit->rightSon->info->dato); // se encolan los nodos adyacentes al elemento visitado

            //todo: printingByLevels
            printf("El nivel de elemento %d, corresponde a :%d\n", visit->rightSon->info->dato, visit->rightSon->info->nivel);


        }
    }

}

// TODO : OPERACIONES DE ARCHIVOS

// se ingresa el nombre del archivo y la cantidad de nodos -> la representacion del arbol como arreglo
int *leerArchivo(char *nombreArchivo, int *quantifyOfnodes)
{

    FILE *fp = fopen(nombreArchivo, "r");

    fscanf(fp, "%d", quantifyOfnodes); // se obtiene la cantidad de iteraciones que se deben realizar
    int stop = *quantifyOfnodes;

    int *arrRepresentationReturn = (int *)malloc(sizeof(int) * stop); // se reserva el espacio para el array que sera retornado
    int aux;

    for (int i = 0; i < stop; i++) // ! posible bug
    {
        fscanf(fp, "%d", &arrRepresentationReturn[i]);
    }

    return arrRepresentationReturn;
}


int main( int argc, char *argv[])
{

    int quantifyOfNodes;

    int *arrayRepresentation = leerArchivo(argv[1], &quantifyOfNodes);

    struct node *tree = verifyTreeCreation(arrayRepresentation, quantifyOfNodes);

    // se asume que siempre iniciara con el -1 la secuencia, por ende es posible observar que el primer elemento ingresado
    // corresponde al 0

    BFSTree(tree, 0); // se asignan los niveles a cada nodo

    printf("El recorrido en preorden corresponde a: \n");
    preOrden(tree);

    printf("El reorrido InOrden corresponde a: \n");
    inOrden(tree);

    printf("El recorrido en postOrden corresponde a: \n");
    postOrden(tree);

    printf("Las profundidades corresponden a: \n");
    printingNodesAndDeeps(tree);



}