//aqui ejecuto mis funciones

#include <stdio.h>
#include <stdlib.h>
#include "clase1.h"

int main (){

    struct punto *punto = createPunto();
    setPunto(punto,3,0,"x");
    printf("varible pp creada %p",punto);

}