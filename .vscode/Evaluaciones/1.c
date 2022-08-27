/*#include <stdio.h>

int main(){

    int a[5] = {2,1,4,5,6};
    
    int lenA = sizeof(a) / sizeof(int);
    int middle = lenA /2;
    printf("%i", middle);

    int i = 0;
    int j = 0;

    
    while ( i < lenA){
        if (i%2 == 0){
            a[i] = a[j];
            i += 1;
            j += 1;
        }
        else{
            a[i] = a[middle];
            i += 1;
            middle += 1;
        }
    }
    printf("El arreglo corresponde a: %i", a);

system("pause");


}
*/