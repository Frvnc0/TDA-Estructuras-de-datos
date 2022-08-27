#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   int i, n;
   time_t t;
   
   n = 4;
   
   /* Intializes random number generator */
   srand(time(NULL));

   /* Print 5 random numbers from 0 to 50 */
   for( i = 0 ; i < n ; i++ ) {
        
        for(int j = 0; j < n; j++){
            int number = rand() %10;
            printf("%i",number);
            
        }
   }
   

}