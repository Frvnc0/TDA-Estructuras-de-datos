#include <stdio.h>

int main(){

int a [9] = {1,2,3,4,5,6,7,8,9};
int i = 0;
int largoArreglo = 9;
int middle = largoArreglo/2;
int auxsWAP; // NOS AYUDARA A HACER EL SWAP

while (i < middle ){
    if (middle % 2 == 0  ){ // en el caso de que middle sea par
        printf("Entro en el primer if");
        int j = 0; // indicador de cuantos swaps tengo que hacer
        int k = largoArreglo; //para hacer el swap desde el final
        int w = middle + 1; // para tomar el elemento de al lado del elemento central
        
        while (j < (middle / 2)){ // trabajamos con el lado impar del arreglo
            printf("%i,%i", k,w);
            auxsWAP = a[k];
            a[k] = a[w];
            a[w] = auxsWAP;
            w += 1;
            k -=1;
            j +=1;
        }
    
    
    }
    i += 1;

}
for (int i =0; i<largoArreglo; i +=1){
        printf("%d",a[i]);
    }
system("pause");
}