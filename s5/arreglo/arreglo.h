struct arreglo{
    int *lista;
    int largoTotal;
    int largoUtilizado;
};

// esta funcion crea un arreglo como puntero y retorna un puntero 
struct arreglo *crearArreglo( int largo );


//esta funcion retorna la posicion del elemento buscado
int buscarElemento(struct arreglo *A, int search);

// esta funcion agrega un elemento al final del arreglo
int agregarElemento(struct arreglo *A, int elem);



//funcion que recibe como parametro un arreglo, un elemento a ser eliminado del array
void eliminarElemento(struct arreglo *A, int elemEliminado );

//mue
void mostrarArreglo(struct arreglo *A);