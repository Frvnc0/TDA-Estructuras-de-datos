
struct linkedList{

    struct nodo *head;
    int n;

};

struct linkedList *crearLista ();

// verifica si esta vacia la lista -> 1 si esta vacia ->0 si no esta vacia
int isEmpty(struct linkedList *listInput);

void LinkedListInsertaInicio(struct linkedList *listInput, struct nodo *nodoInput);

// busca un entero en la lista, retornando la direccion del nodo en el cual se encuentra el valor buscado, si no lo encuentra imprime un mensaje por pantalla y retorna NULL
struct nodo *buscarEnLista(struct linkedList *listInput, int search );

//inserta un elemento despues de la posicion del elemento a insertar
void linkedListInsertInPosition(struct linkedList *listInput, int elementToInsert, int position);

// elimina el primer elemento de la lista 
void linkedListDeleteFirst(struct linkedList *listInput);


// busca un entero en la lista, retornando la direccion del nodo en el cual se encuentra el valor buscado, si no lo encuentra imprime un mensaje por pantalla y retorna NULL
struct nodo *buscarAnteriorEnLista(struct linkedList *listInput, int search );


void linkedListDeleteLast(struct linkedList *listInput);



void printList(struct linkedList *listInput);

void actualizarLista(struct linkedList *listInput, int elementToUpdate, int elementToBeUpdated );

void linkedListDeleteInPosition(struct linkedList *listInput, int search);

