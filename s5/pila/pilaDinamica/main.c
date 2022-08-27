#include <stdio.h>
#include <stdlib.h>
#include "pilaDin.h"


int main (){

struct pilaD *pilita = crearPila();

apilar(pilita,4);
apilar(pilita,5);
apilar(pilita,6);

tope(pilita);
desapilar(pilita);

tope(pilita);
}