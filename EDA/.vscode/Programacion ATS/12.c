#include <stdio.h>
#include <math.h>

int main(){
    float diameter, longitud;
    printf("Ingrese el valor del diametro de su circunferencia");
    scanf("%f",&diameter);
    longitud = M_PI * diameter;
    printf("El valor de la longitud corresponde a: %f \n", longitud);
    system("pause");

}