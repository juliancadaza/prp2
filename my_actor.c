#include "my_actor.h"
#include "cbw.h"
#include <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

unsigned int OUT_s;             //Zustände Speichern
unsigned int IN_s;

void init(){
    cbDConfigPort(0, FIRSTPORTA, DIGITALOUT);
    cbDConfigPort(0, FIRSTPORTB, DIGITALIN);
    cbDConfigPort(0, FIRSTPORTCL, DIGITALOUT);
    cbDConfigPort(0, FIRSTPORTCH, DIGITALIN);
    OUT_s = 0;
    IN_s = 0;
}


void updateProcess(){
    unsigned short temp = 0;
    IN_s = 0;
    cbDIn(0, FIRSTPORTCH, &temp);
    IN_s = temp << 8;
    cbDIn(0, FIRSTPORTB, &temp);
    IN_s = IN_s | temp ;
    dez_bin(IN_s);
}



void applyOutputToProcess (){

    cbDOut(0, FIRSTPORTCL, (OUT_s >> 8) );
    cbDOut(0, FIRSTPORTA, OUT_s);
    dez_bin(OUT_s);
}







bool isBitSet (unsigned short int bit_mask){
    return (IN_s & bit_mask) != 0;
}

void setBitInOutput (unsigned short int bit_mask){
    OUT_s = OUT_s | bit_mask;

}

void clearBitInOutput (unsigned short int bit_mask){
    OUT_s = OUT_s & (~ bit_mask);
    
}

void resetOutputs (){
     OUT_s = 0;
     
}


void delay_ms(int milli){
    long pause = 0;
    clock_t now;                //aktuelle Systemzeiten 
    clock_t then;
   
    pause = milli*(CLOCKS_PER_SEC/1000);   //Systemtakt 
    
    now = then = clock();       //Aktuelle Zeit 
    while ((now-then)< pause)
        now = clock();
}



void dez_bin(unsigned int n) {
    
        //Deklaration und Initialisierung von Variablen 
    int bin[100];
  
    int quot = 0;
    int i = 0;
    quot = n;
   
        //Umrechnen mit eine 'while' Schleife
    while(quot != 0){
        bin [i] = quot%2;
        quot = quot/2;
        i++;
    }
    i--;    //Zähler muss wieder eins runtergezogen werden
            //Ausgabe des Ergebnisses (i wird jetzt von oben runtergezählt)
   printf("\nEingegeben wurde : %X\n", n);
   // printf("\nUmgerechnet in Binaer : ");
    while (i >= 0){
        printf ("%d", bin[i]);
        if (i%4 == 0)
            printf(" | ");
        i--;
    }
   printf("\n");
     

}

void sensorwerte (){

    char a;
    bool x;
    printf("Buchstabe eingeben e-k: ");
    scanf("%c",&a);
    fflush(stdin);
    
    switch(a) {
    
        case 'e':  if(x = isBitSet (WERKSTUECK_IN)){
        
                    printf("Werkstueck liegt nicht im Einlauf");}
                    else{printf("Werkstueck liegt im Einlauf");
                   }
                 break;
        
       case 'f':  if(x = isBitSet (WERKSTUECK_H_MESSUNG)){
        
                    printf("Werkstueck nicht im Bereich der Hoehenmessung");}
                    else{printf("Werkstueck im Bereich der Hoehenmessung");
                    }
                 break;
                 
                 
       case 'g':  if(x = isBitSet (WERKSTUECK_WEICHE)){
        
                    printf("Kein Werkstueck im Bereich der Weiche");
       
       }
                    else if(x = isBitSet (WERCKSTUECK_MET)){
                        printf("Metalisches Werkstueck");
                    }
                    else{printf("kein metalisches Werkstueck");}
                    
                 break;
               
                 
       case 'h':  if(x = isBitSet (RUTCHE_VOLL )){
        
                    printf("die Rutsche ist nicht voll");}
                    else{printf("die Rutsche ist voll");
                    }
                 break;
                 
       case 'i':  if(x = isBitSet (STOP_T )){
        
                    printf("stop taste wurde nicht gedruckt");}
                    else{printf("stop taste wurde gedruckt");
                    }
                 break;
                 
        case 'j':  if(x = isBitSet (RESET_T )){
        
                    printf("reset taste wurde gedruckt");}
           else{printf("reset taste wurde nicht gedruckt");
                    }
                 break; 
                 
       case 'k':  if(x = isBitSet (E_STOP )){
        
                    printf("der Not-Aus-Taster wurde nicht gedruckt");}
           else{printf("der Not-Aus-Taster wurde gedruckt ");
                    }
                 break; 
                 
        
    
    }
    
}

