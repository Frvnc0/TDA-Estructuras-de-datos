//todo: struct del grafo
struct graph{
    struct linkedList **aristas;
    int nV;
    int nE;
};


struct nodo {
    int dato;
    int costo;
    struct nodo *next;
};

struct edge{
    int u;
    int v;
    int w;

};


struct nodo *crearNodo(int dato, int costo);
void setNodo(struct nodo *nodo, int dato);
void setEnlaceNodo (struct nodo *prevNode, struct nodo *nextNode );
int getNodo( struct nodo *nodo);



//todo: archivos

float averageGrade(struct graph *g);


int quantifyExceedAverage(struct edge **aristas, struct graph *g, float averageWeigt);

struct graph* leerArchivo(char *nombreArchivo, float *averageWeight);
float densidadGrafo(struct graph *grafo);

int leerArchivoAristas(char *nombreArchivo, int averageWeight );
//todo: llamados de cabecera del struct graph
struct graph *createGraph(int vertices);

 //! cuidado que puede estar mala
//recibe el valor de una arista en formato entero, recibe el nodo adjacente y el grafo en el cual sera insertado
void insertaArista(int u, int v, int w,  struct graph *graphInput);

void mostrarGrafo(struct graph *graphInput);
// recibe un grafo y un vertice  → arreglo de vértices adyacentes
struct linkedList* obtener_adyacentes_vertice(struct graph *graphInput, int vertice);
//? fix it
//recibe un grafo, arista → void
void remover_arista(struct graph *graphInput, int edgeToBeDeleted, int vertexAdj);
// recibe un grafo y una arista  → 1 si es que el elemento se encuentra e imprime un mensaje → 0 si es que el elemento no se encuentra y retorna 
int pertenece_arista(struct graph *graphInput, int edge, int vertexAdj);
//recibe un grafo y un vertice  → entero
int obtener_grado_vertice(struct graph *graphInput, int vertex);
//recibe un grafo  → arreglo de aristas
struct linkedList** obtener_aristas(struct graph *graphInput);
// recibe vértice, vértice → arista
int *crear_arista(int vertexAdj, int edgeValue);

int *maxAndMinGradeOfEachNode(struct graph *graphInput);

int isKRegular(struct graph *graphInput);


//Verificar si un grafo es simple
// *grafo -> 1: Si es que es simple 0: si es que no es simple 
int isSimple(struct graph *graphInput);



void prim(struct graph *graphInput, int *pred, int *weight);