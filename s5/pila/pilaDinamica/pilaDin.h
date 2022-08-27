
#include <stdio.h>
#include <stdlib.h>


struct nodo{
    int dato;
    struct nodo *sig;
};


struct pilaD{
    struct nodo *tope;
};

//CREA UN PUNTERO A UNA PILA Y RETORNA UNA PILA VACIA
struct pilaD *crearPila();

// RECIBE UNA PILA, UN ELEMENTO, EL CUAL ES APILADO
void apilar(struct pilaD *pilaInput, int elem);


// RECIBE UNA PILA Y DESAPILA EL ELEMENTO DEL TOPE
int desapilar(struct pilaD *pilaInput);

// VERIFICA SI LA PILA ESTA VACIA, RETORNA 1 SI ESTA VACIA Y 0 SI NO ESTÁ VACIA
int isEmpty(struct pilaD *pilaInput);


//MUESTRA EL ELEMENTO DEL TOPE
int tope(struct pilaD *pilaInput);

void destruirPila(struct pilaD *pilaInput);




