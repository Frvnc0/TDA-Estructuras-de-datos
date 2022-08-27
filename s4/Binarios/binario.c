#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int intToBinIterI(int dec)
{
    int binary = 0;
    int cast = 1;
    while (dec != 0)
    {
        binary = (binary + ((dec % 2) * cast));
        cast *= 10;
        dec /= 2;
    }
    return binary;
}


int addBinary(int bin1, int bin2){
    int result = 0;
    int acarreo = 0;
    int tAdd = 0;
    int add1 = 0;
    int add2 = 0;
    int i =1;
    if (bin1> bin2){
        while (bin1 != 0)
        {
            add1 = bin1%10;
            add2= bin2%10;
            tAdd = add1 + add2+acarreo ;

            if (tAdd == 2){
                i *= 10;   
                result += i;
                acarreo +=1;                     
            }
            else if(tAdd == 3){
                
            }

        }
        
    }
    else{

    }

}



int main()
{

    printf("%i", intToBinIterI(10));
}




/*
char intToChar(int n)
{ // clave ver el codigo ascii
    char castChar = n + 48;
    return castChar;
}

void intToBinIterC(int decimal, char *binario)
{
    int i = 0;
    while (decimal != 0)
    {
        printf("hola");
        binario[i] = intToChar((decimal % 2));
        decimal = decimal / 2;
        i++;
    }
    binario[i] = '0';
}
 */




/*     int n = 3;
    n = n/2;
    n= n/2;
    printf("%i",n);
 */

/*
int intToBin(int n, char *nombre, int i){
    if (n <= 0 )
    {
        printf("hola");
        nombre[i] = '0';
        return 0;
    }
    else{
        int resto = n%2;
        nombre[i] = resto;
        n = n/2;
        return (n,nombre,i+1); // ! estaba poniendo i-1
    }
}

 */
