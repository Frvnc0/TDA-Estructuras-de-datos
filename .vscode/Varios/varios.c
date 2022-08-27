#include <stdio.h>

int main(){
    int numero;
    int contador = 0;
    printf("%i", contador);
    printf("Ingrese un numero deseado: ");
    scanf("%i",&numero);

    while(numero <= 0){
        
        printf("Ingrese un numero deseado: ");
        scanf("%i",&numero); 
    }
    if(numero > 0){
        for(int i=1; i<=numero; ++i){
            if(numero%i==0){
                printf("hola");

                contador = contador + 1;
            }
        }
        printf("La cantidad de numeros divisores son: %i",contador);
        system("pause");
    }
    

}