/*5.	Crear un programa que compare dos archivos e indique el carácter 
donde ellos difieran (si es que difieren)*/
# include <stdio.h>
#include <stdbool.h>
int main() {

    FILE *dataFlux1 = fopen("archivo1.txt", "r");
    FILE *dataFlux2 = fopen("archivo2.txt", "r");
    //Q: E el tipo de dato booleano en c
    // A: Es necesario incluir la librería <stdbool.h> y respetar la sintaxis  
    //https://eleckia.wordpress.com/2019/07/09/programando-avr-en-c-tipo-de-dato-booleano-operadores-booleanos-y-de-comparacion/
    bool isEqual = true;
    char differ1, differ2;

    while (fgetc(dataFlux1) != EOF || fgetc(dataFlux2) != EOF ){ //Mientras los dos no lleguen al final itera
        if ( fgetc(dataFlux1) != fgetc(dataFlux2) ){

            isEqual = false;
            differ1 = (char)fgetc(dataFlux1);
            differ2 = (char)fgetc(dataFlux2);
            printf("%c, \n",differ1);
            printf("%c, \n",differ2);

            break;
        }
        else{
            isEqual == true;
        }
    }    

    if (isEqual == true){
        printf("Ambos textos son iguales");
    }
    else{
        printf("Ambos archivos son diferentes y difieren en %c, y %c", differ1,differ2);
    }
    
    system("pause");    
}