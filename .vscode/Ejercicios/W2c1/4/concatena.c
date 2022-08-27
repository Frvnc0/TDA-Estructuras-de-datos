#include <stdio.h>

int main(){

    char nombre[25] = "archivo1.txt";
    char caracter1, caracter2;
    FILE *flujo1 = fopen("archivo1.txt", "r");
    FILE *flujo2 = fopen("archivo2.txt", "r");
    FILE *flujo3 = fopen("escritura.txt", "w" );

    while (feof(flujo1) == 0 || feof(flujo2) == 0 ){
       
        if (feof(flujo1) == 0){
            caracter1 = fgetc(flujo1);
            fprintf(flujo3,"%c",caracter1);
        }

        //FIXME: else if (feof(flujo2) == 0){
        if (feof(flujo2) == 0){ // había puesto un else if, lo que producía que entrara solo en el primer if, hasta terminar el archivo
            caracter2 = fgetc (flujo2);
            fprintf(flujo3,"%c",caracter2);
        }       

    }
    
}