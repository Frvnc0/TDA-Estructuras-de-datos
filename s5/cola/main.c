#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main (){

    struct cola *colita = crearColita();
    
    
    encolar(colita,4);
    encolar(colita,6);
    encolar(colita,8);

    desencolarTodo(colita);

}

