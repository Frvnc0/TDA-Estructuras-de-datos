#include <stdio.h>

void printDirCont(int A[], int len){

    for (int i = 0; i < len; i++)
    {
        printf("El contenido el elemento %i, corresponde a: %i y su direccion de memoria corresponde %p\n", i, A[i], (A+i));
    }
}

int main(){

    int A[] = {1,2,3,4,5,6,7,8,9,10};
    printDirCont(A,10);

}