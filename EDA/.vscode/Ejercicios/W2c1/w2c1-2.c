#include <stdio.h>

int main(){
    FILE *fp;
    FILE *sumas = fopen("suma.txt","w");



    int filedate = 0, suma = 0;

    
    fp = fopen("numeros.txt","r");
    if (fp == NULL){
        printf("El archivo \"numeros.txt\", no pudo ser abierto "); //¿Como usar secuencias de escape?
        //A: https://es.stackoverflow.com/questions/391298/caracteres-especiales-en-c
    }

    while ( feof(fp) == 0){ //Como usar fscanf 
    //https://www.youtube.com/watch?v=Q3P3KdDkmUc
        printf("hola");
        //FIXME: fscanf(fp, "%i", filedate);
        fscanf(fp, "%i", &filedate); // Me había olvidado de poner el & !!!!!! #FIXME:  
        printf("\n %i \n", filedate);
        suma = suma + (int)filedate; //¿Como convertir tipos de datos en c, porque tengo la sospecha de que caracter es un tipo de dato el cuall no se puede sumar con un entero u flotante, al leerlo desde un txt
    
    }

    fprintf(sumas,"La suma, corresponde a: %i",suma);
    system("pause");
}