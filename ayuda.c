#include <stdio.h>


int main (){

    char Rut[100] = "20.117.821-4";
    int rutSinDvNiPunto[100];

    int i = 0;
    int j = 0;
    int aux = 0;
/* 
    for (int i = 0; i < 30; i++)
    {
        printf("%c", Rut[i]);
    }
 */
    while (Rut[i] != '-')
    {
        if(Rut[i] == '.'){
            
            i= i + 1;
            continue;
        }
        else
        {
            aux = Rut[i] - '0';
            rutSinDvNiPunto[j] = aux;
            i++;
            j++;
        }
    }

printf("%d",j);
    for (int i = 0; i < j; i++)
    {
        printf("%i", rutSinDvNiPunto[i]);
    }
/* 
     */
    
    
    

}
/* 
    for (int i = 0; i < 20; i++)
    int count = 0;
    int i = 0;
    while (rutSinDv[i] != NULL)
    {
        count ++;
    }
    
    printf("%d", count);

    for (int i = 0; i < 4; i++)
    {
        printf("%c", rutSinDv[i]);
    }
    

    {
        printf(" ¿Aun queda otro digito del rut?. 1:si 0:no ");
        scanf("%d", &flag);
        if (flag == 0){
            break;
        }

        printf("Ingrese el digito de su rut: \n");
        scanf("%c", &auxContent);

    }
    
 */


