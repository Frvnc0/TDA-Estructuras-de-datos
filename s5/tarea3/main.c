#include <stdio.h>
#include <stdlib.h>
#include "tdas.h"

int main()
{

    struct cola *colita = crearColita();

    encolar(colita, 4);
    encolar(colita, 6);
    encolar(colita, 8);

    desencolarTodo(colita);

    struct pilaD *pilita = crearPila();

    apilar(pilita, 4);
    apilar(pilita, 5);
    apilar(pilita, 6);

    tope(pilita);
    desapilar(pilita);

    tope(pilita);
}