#include <stdio.h>

int main (){
    //Declarando largos de la matriz
    int rows = 3;
    int columns = 3;

    //declarando matriz

   // int a [rows][columns] = {}; #FIXME: no puedo inicializar con las llaves, ya que no estoy almacenando nada en el array
    int a [rows][columns];

    for (int i = 0 ; i< rows; i++){

        for (int j = 0; j < columns; j++){
            printf("Ingrese el elemento %i,%i",i,j);
            //se podra hacer con un scanf?
            scanf("%i",&a[i][j]);
        }
    
    }

    //imprimiento matriz
    for (int i = 0 ; i< rows; i++){

        for (int j = 0; j < columns; j++){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    
    }

}