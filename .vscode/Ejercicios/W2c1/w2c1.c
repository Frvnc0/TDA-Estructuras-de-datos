//Qlearn: Cuals son las funciones existentes para el manejo de archivos
// A: https://medium.com/10-goto-10/manejo-de-archivos-en-c-19f85b31ddd

#include <stdio.h>
int main(){

    FILE *fp;
    FILE *copia;
    
    char linea[200], caracter;
    char nombre[4] = "W2c1.c";

    // como usar la variiable char ¿Que se puede y que no se puede hacer?
/*
    printf("Nombre archivo a leer:\n");
    scanf("%s",nombre);
*/

    copia = fopen( "copia.txt", "w" );
    if(copia == NULL){
        printf("Error al abrir archivo %s\n",nombre);
        return 0;
    }

    fp = fopen(nombre,"r");
    if(fp == NULL){
        printf("Error al abrir archivo %s\n",nombre);
        return 0;
    }
    while((caracter = getc(fp)) != EOF){
        fprintf( copia, "%c",caracter );
    }
    fclose(fp);
    fclose(copia);
}	
