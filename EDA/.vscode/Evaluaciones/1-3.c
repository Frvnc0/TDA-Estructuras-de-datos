#include <stdio.h>

int main(){

int arreglo[9] = {1,2,3,4,5,6,7,8,9};
int largoArreglo = 9;
int middle = largoArreglo/2;
int i = 0;
int aux = 0;
while (i < largoArreglo){
    int j = i;
    while (j <= middle){
        aux = arreglo[middle];
        int j = i;
        int k = middle;
        while (k< middle){
            arreglo[k] = arreglo[k-1];

        }
    }
       
}
for (int i = 0; i < largoArreglo; i++){
    printf("%i", arreglo[i]);
}



}