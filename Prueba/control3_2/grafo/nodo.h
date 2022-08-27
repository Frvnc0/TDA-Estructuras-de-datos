

struct nodo {
    int dato;
    struct nodo *next;
}typedef arista;

struct nodo *crearNodo(int dato);
void setNodo(struct nodo *nodo, int dato);
void setEnlaceNodo (struct nodo *prevNode, struct nodo *nextNode );
int getNodo( struct nodo *nodo);
