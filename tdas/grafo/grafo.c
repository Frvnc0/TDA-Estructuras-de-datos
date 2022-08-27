#include <stdio.h>
#include <stdlib.h>

#include "listaDinamica.h"
#include "graph.h"
#include "nodo.h"


// crea un grafo, recibiendo el numero de vertices
// SE ASUME QUE CUANDO SE CREA EL GRAFO, LOS VERTICES EXISTEN (TODOS), AUNQUE NO POSEEN ARCOS U ARISTAS ENTRE ELLOS
struct graph *createGraph(int vertices)
{

    struct graph *graphReturn = (struct graph *)malloc(sizeof(struct graph));
    graphReturn->aristas = (struct linkedList **)malloc(sizeof(struct linkedList *) * vertices); // guardamos el espacio para cada una de las aristas

    for (int i = 0; i < vertices; i++)
    {
        graphReturn->aristas[i] = crearLista(); // creamos cada una de las listas en el grafo
    }
    printf("El grafo fue creado exitosamente\n");

    graphReturn->nV = vertices;

    return graphReturn;
}

// recibe el valor de una arista en formato entero, recibe el nodo adjacente y el grafo en el cual sera insertado
void insertaArista(int edgeToInsert, int adj, struct graph *graphInput)
{

    LinkedListInsertaInicio(graphInput->aristas[adj], crearNodo(edgeToInsert)); // se accede a la linked list refernte al nodo adyacente y se inserta al inicio del nodo
    LinkedListInsertaInicio(graphInput->aristas[edgeToInsert], crearNodo(adj)); // se accede a la linked list refernte al nodo adyacente y se inserta al inicio del nodo
    graphInput->nE += 1;
    printf("La arista fue creada exitosamente\n");
}

void mostrarGrafo(struct graph *graphInput)
{

    for (int i = 0; i < graphInput->nV; i++)
    {

        struct nodo *temp = graphInput->aristas[i]->head;

        while (temp != NULL)
        {

            printf("El elemento del vertice %d, corresponde a : %d\n", i, temp->dato);
            temp = temp->next;
        }
    }
}

// recibe un grafo y un vertice  → arreglo de vértices adyacentes
struct linkedList *obtener_adyacentes_vertice(struct graph *graphInput, int vertice)
{

    return graphInput->aristas[vertice];
}

//? fix it
// recibe un grafo, arista → void
void remover_arista(struct graph *graphInput, int edgeToBeDeleted, int vertexAdj)
{

    linkedListDeleteInPosition(graphInput->aristas[vertexAdj], edgeToBeDeleted);
    linkedListDeleteInPosition(graphInput->aristas[edgeToBeDeleted], vertexAdj);

    graphInput->nE += 1;

    printf("La arista fue eliminada exitosamente\n");
}

// recibe un grafo y una arista  → 1 si es que el elemento se encuentra e imprime un mensaje → 0 si es que el elemento no se encuentra y retorna
int pertenece_arista(struct graph *graphInput, int edge, int vertexAdj)
{

    struct nodo *temp = buscarEnLista(graphInput->aristas[vertexAdj], edge);
    if (temp == NULL)
    {
        return 0;
        printf("La arista no se encuentra\n");
    }
    else
    {
        printf("La arista se encuentra\n");
        return 1;
    }
}

// recibe un grafo y un vertice  → entero
int obtener_grado_vertice(struct graph *graphInput, int vertex)
{

    return graphInput->aristas[vertex]->n;
}

// recibe un grafo  → arreglo de aristas
struct linkedList **obtener_aristas(struct graph *graphInput)
{

    return graphInput->aristas;
}

// recibe vértice, vértice → arista
int *crear_arista(int vertexAdj, int edgeValue)
{

    int *edgeReturn = (int *)malloc(sizeof(int *));

    return edgeReturn;
}

// todo: funciones por crear

// recibe un grafo e indica el maximo y minimo Grado de un nodo

// todo: tdd y copiar y pegar a archivo de cabecera
int *maxAndMinGradeOfEachNode(struct graph *graphInput)
{

    int *maxAndMin = (int *)malloc(sizeof(int) * 2); // arreglo de dos elementos que contendra a cada uno de los nodos

    int max = 0;                  // asumimos que el menor grado que puede tener un grafo con un solo elemento o vacio es 0
                                  // definimos el numero de aristas que posee el grafo
    int min = graphInput->nV + 1; // suponemos que el maximo grado es el numero de vertices mas uno lo que representaria infinito en un busqueda lineal, ya que se sabe que en grafo completo cada nodo posee n-1 aristas
    // linear Search
    for (int i = 0; i < graphInput->nV; i++)
    {

        if (max < graphInput->aristas[i]->n)
        {
            max = graphInput->aristas[i]->n;
        }

        if (min > graphInput->aristas[i]->n)
        {
            min = graphInput->aristas[i]->n;
        }
    }
    maxAndMin[0] = max;
    maxAndMin[1] = min;
    //! return
    return maxAndMin;
}

// Verificar si un grafo es k regular (indicar el valor de k)
// recibe un grafo e indica si el grafo es k regular -> int k
int isKRegular(struct graph *graphInput)
{

    struct linkedList **temp1 = graphInput->aristas; // recorriendo listas de listas

    int k = graphInput->aristas[0]->n; // se extrae manualmente el grado del primer vertice
    int i = 1;

    while (temp1 != NULL) // mientras alguna de las listas no este vacia, recorremos //todo: usar isEmpty
    {
        i++;
        if (graphInput->aristas[i]->n != k)
        { // si el grado de alguna de las siguientes aristas es diferente entonces
            printf("El grafo no es k Regular, se ha retornado el valor 0\n");
            return 0;
        }
        temp1 = graphInput->aristas;
    }

    printf("El grafo es k regular, se ha retornado el valor de k \n");
    return k;
}
// recibe un grafo y retorna una lista con el grado de cada nodo
int *gradeOfEachNode(struct graph *graphInput)
{

    int *gradeOfEachNode = (int *)malloc(sizeof(int) * graphInput->nV);

    for (int i = 0; i < graphInput->nV; i++)
    {
        gradeOfEachNode[i] = graphInput->aristas[i]->n;
    }

    return gradeOfEachNode;
}

// Verificar si un grafo es simple
//  *grafo -> 1: Si es que es simple 0: si es que no es simple
int isSimple(struct graph *graphInput)
{

    // verificar si es que alguno de las aristas conectan consigo mismo, lo que implicaria que el grafo, no es simple
    for (int i = 0; i < graphInput->nV; i++)
    {
        // si es que alguno de las listas es vacia, itera hacia la siguiente lista
        if (graphInput->aristas[i] == NULL)
        {
            continue;
        }

        struct nodo *flag = buscarEnLista(graphInput->aristas[i], i);
        if (flag != NULL)
        { // si es que logra encontrar el elemento, entonces el grafo no es simple
            return 0;
            printf("El grafo ingresado no es regular, la funcion ha retornado 0\n");
        }
    }

    // verificar si es que alguno de los elementos se encuentran en dos ocasiones en el mismo grafo
    //  se realizan dos ciclos aparte, solo para simplificar la codificacion aunque de igual forma, dan de onden n^2
    for (int i = 0; i < graphInput->nV; i++)
    {

        if (graphInput->aristas[i] == NULL)
        {
            continue;
        }

        for (int j = 0; j < graphInput->nV; j++)
        {
            struct nodo *flag = buscarEnLista(graphInput->aristas[i], j); // se busca el elemento en la lista
            linkedListDeleteInPosition(graphInput->aristas[i], j);        // se elementa el elemento en la lista

            if (buscarEnLista(graphInput->aristas[i], j) != NULL) // si es que se vuelve a encontrar el elemento, entonces el elemento se encuentra conectado dos veces
            {
                LinkedListInsertaInicio(graphInput->aristas[i], crearNodo(j)); // insertamos el elemento nuevamente, para poder volver la lista a su normalidad
                printf("El grafo ingresado no es regular, la funcion ha retornado 0\n");
                return 0; // salimpos de la funcion
            }

            LinkedListInsertaInicio(graphInput->aristas[i], crearNodo(j)); // insertamos el elemento nuevamente, para poder volver la lista a su normalidad
        }
    }
    printf("El grafo ingresado es regular, la funcion ha retornado 1");
    return 1;
}

void BFS(struct graph *grafo){

}
/*
Verifica si un conjunto de vértices es una clique
//recibe un grafo y una cantidad de vertices a ingresar y verfica si es clique -> 1 si es clique -> 0 si no es clique
int isClique(){

}

 */

// todo: funciones por crear
/*
Verificar si un conjunto ordenado de vértices es un tour

Generar el grafo complemento (guardar en archivo)
•
• */