
struct nodo{
    int dato;
    struct nodo *next;
};

struct cola{
    struct nodo *nodIni;
    struct nodo *nodFin;
};

struct pilaD{
    struct nodo *tope;
};


struct nodo *crearNodo(int value);

struct cola *crearColita();

void encolar(struct cola *cola, int elem);


// recibe una cola y printea el ultimo elemento de la cola
void desencolar(struct cola *cola);

int frente(struct cola *colaEnt);

void desencolarTodo(struct cola *colaEnt);

struct pilaD *crearPila();

void apilar(struct pilaD *pilaInput, int elem);

int desapilar(struct pilaD *pilaInput);

int isEmpty(struct pilaD *pilaInput);

int tope(struct pilaD *pilaInput);

void destruirPila(struct pilaD *pilaInput);


