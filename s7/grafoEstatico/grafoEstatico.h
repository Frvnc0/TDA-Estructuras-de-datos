

// aun no esta implementado del todo el grafo como tal

// aun no esta implementado del todo el grafo como tal

struct graph{
    int v; //numero de vertices
    int a; // numero de aristas
    int **matrizAdyacencia; // matriz de adyacencia

};


struct graph *crearGrafo(int v);

void insertarArista(struct graph *grafoInput, int vertice1, int vertice2);


int *crearArista(int vertice1, int vertice2);



