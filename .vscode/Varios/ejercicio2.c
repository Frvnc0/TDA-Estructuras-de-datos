#include <stdio.h>
#include <stdlib.h>

int main (){

    //Solución que se me ocurrió a mi 
    int array [] = {1,2,3,4,5,6,7,8,9,10};
    int max = array[0];
    for (int i = 1; i < 10; i++){
        if ( array[i] > max ){
            max = array[i];
        }
    }
    printf("El mayor numero corresponde a %i",max);

    max = 0; //Redefiniendo la variable
    for (int i = 1; i < 10; i++){
        if (array[max] < array[i]){
            max = i;
        }
    }
    printf("El mayor numero corresponde a %i", array[max]);
    

}