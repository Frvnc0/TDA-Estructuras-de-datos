#include <stdio.h>

int main(){
    
    int a [6] = {1,2,3,4,5,6};

    int lenA = sizeof(a)/sizeof(int);
    int middle = lenA/2;
    int aux ;
    int i = 1;

    if (lenA %2 == 1){
        while (i < middle + 1){
            aux = a[middle];

            int j = 0;
            int move = middle - i;
            int auxmove = middle;
            while (move > j  ){
                a[auxmove] = a[auxmove-1];
                auxmove -= 1;
                j += 1;

            }
            
            a[i] = aux;
            i += 2;
            middle += 1;
        }
        for (int i = 0; i < lenA; i++){
        printf("%i",a[i]);
        }
    } 
    else{
        
        while (i < middle + 1 ){
            
            aux = a[middle];
            int j = 0;
            int move = middle - i;
            int auxmove = middle;
            
            while (move > j  ){
                a[auxmove] = a[auxmove-1];
                auxmove -= 1;
                j += 1;

            }
            a[i] = aux;
            i += 2;
            middle += 1;

        }
        for (int i = 0; i < lenA; i++){
        printf("%i",a[i]);
    
    }
    }
    
system("pause");

}
