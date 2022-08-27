/* Realizar un programa en c que pida 5 calificaciones y calcule el promedio de ellas*/

#include <stdlib.h>
#include <stdio.h>
int main (){
    float promedio = 0; // declaramos el acumulador como cero para cerciorarnos de que parta en 0
    float nota;

    for (int i = 0; i<5; i ++){
        printf("Ingrese la nota %i", i,"del alumno");
        //nota = scanf("%i",&nota);  FIXME: con el scanf no es necesario ponerlo en una variable
        scanf("%f",&nota);  
        promedio += nota;
        printf("%f,",promedio);
        printf("%f",nota);
    }

    promedio /= 5;
    printf("El promedio de los valores corresponde a: %f", promedio);

}

