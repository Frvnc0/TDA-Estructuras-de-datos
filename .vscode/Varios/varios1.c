#include <stdio.h>

int main(){
    int number = 0;
    while (number <=7){
        if (number == 2){
            continue;
        }
        printf("%i", number);
        number++; // lo que sucede si es que ponemos el number aquí, es que reasignamos el valor de la variable despues del if, por lo tanto el bucle queda en un ciclo infinito

    }

    system("pause");
}