#include <stdlib.h>
struct pilaEstatica{
    int *datos;
    int tope;
};

struct pilaEstatica *crearPilaEstatica(int largoPila){
    struct pilaEstatica *pilaTemp = (struct pilaEstatica*)malloc(sizeof(struct pilaEstatica));
    
    int *datos = (int*)malloc(sizeof(int)*largoPila);
    pilaTemp->datos = pilaTemp; // seteamos el puntero datos como la lista de datos
    pilaTemp->tope = 0;

    return pilaTemp;
}

void apilar(struct pilaEstatica pilita, int elem){
    
}


int main (){




}