
struct nodo{
    int dato;
    struct nodo *next;
};

struct cola{
    struct nodo *nodIni;
    struct nodo *nodFin;
};


//CREA UN NODO Y SETEA NEXT EN NULL, RETORNA UN NODO
struct nodo *crearNodo(int value);

struct cola *crearColita();

void encolar(struct cola *cola, int elem);


// recibe una cola y printea el ultimo elemento de la cola
void desencolar(struct cola *cola);

int frente(struct cola *colaEnt);
void desencolarTodo(struct cola *colaEnt);