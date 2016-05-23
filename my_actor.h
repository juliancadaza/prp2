/* 
 * File:   my_actor.h
 * Author: abv250
 *
 * Created on 27. Oktober 2015, 13:03
 */

#ifndef MY_ACTOR_H
#define	MY_ACTOR_H

#include <stdbool.h>
#include <time.h>


//#define actor               0x00
//Port A (Ausgabe Port)
//für 1
#define M_RECHTS                    0x01      //Band rechts
#define M_LINKS                     0x02      //Band links
#define M_LANGSAM                   0x04      //0 = langsam nach rechts; 1 = langsam nach links
#define M_STOP                      0x08      //Band läuft nicht
#define WEICHE_AUF                  0x10      //Weiche auf 
#define A_GRUEN                     0x20      //Grün an 
#define A_GELB                      0x40      //Gelb an
#define A_ROT                       0x80      //Rot an 

//Port B (Eingabe Port)

#define WERKSTUECK_IN               0x01      //
#define WERKSTUECK_H_MESSUNG        0x02      //
#define HOECHE_1                    0x04      //
#define WERKSTUECK_WEICHE           0x08      //
#define WERCKSTUECK_MET             0x10      //
#define WEICHE_OFFEN                0x20      //
#define RUTCHE_VOLL                 0x40      //
#define WERKSTUECK_OUT              0x80      //

//Port C (IN/OUT Port)

#define LED_START_T                 0x0100      //
#define LED_RESET_T                 0x0200      //
#define LED_Q1                      0x0400     //
#define LED_Q2                      0x0800      //

#define TEST_T                      0x100      //
#define STOP_T                      0x200      //
#define RESET_T                     0x400      //
#define E_STOP                      0x800      //


void init();

void updateProcess();
void applyOutputToProcess();


bool isBitSet (unsigned short int bit_mask);
void setBitInOutput (unsigned short int bit_mask);
void clearBitInOutput (unsigned short int bit_mask);
void resetOutputs ();
void delay_ms(int );
void dez_bin(unsigned int n);
void sensorwerte ();


#endif	/* MY_ACTOR_H */

