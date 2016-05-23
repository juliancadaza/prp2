/* 
 * File:   main.c
 * Author: abv250
 *
 * Created on 27. Oktober 2015, 12:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_actor.h"
#include "cbw.h"

int main() {

    
    init();
  
    updateProcess();
    sensorwerte ();
    
   /*while (1) {
       
       
   updateProcess();
   delay_ms(5000);
      
   }*/
    return (EXIT_SUCCESS);


}