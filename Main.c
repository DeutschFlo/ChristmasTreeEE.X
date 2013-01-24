/**********************************************/
/*		SAPIN NOYEL				  */
/*											  */
/*			v1.0 FX M.	  */
/**********************************************/

#include <p18f4520.h>
#include <delays.h>
#include <stdlib.h>

//-------------------------------------
// INIT. MATERIELLE
//-------------------------------------
#pragma config OSC = INTIO67 // Oscillateur interne, RA6 etRA7 ports IO.
#pragma config WDT = OFF // WatchDog : OFF
#pragma config LVP = OFF // Single SUpply ICSP
#pragma config MCLRE = OFF //MasterClear : OFF
#pragma config PBADEN = OFF // Enable RB6 / RB7
//--------------------------
// VARIABLES - MACROS
//-------------------------------------
#define OFF 0
#define ON 1

#define NBR_BOUCLE 30
#define NBR_MOTIF 3
#define NBR_SAPIN 18

// Raccourcis multiple allumage
#define BOULE_0 PORTAbits.RA0
#define BOULE_1 PORTAbits.RA1
#define BOULE_2 PORTAbits.RA2
#define BOULE_3 PORTAbits.RA3
#define BOULE_4 PORTAbits.RA4
#define BOULE_5 PORTEbits.RE1
#define BOULE_6 PORTEbits.RE2
#define BOULE_7 PORTCbits.RC1
#define BOULE_8 PORTCbits.RC2
#define BOULE_9 PORTCbits.RC0
#define BOULE_10 PORTAbits.RA7
#define BOULE_11 PORTAbits.RA5
#define BOULE_12 PORTEbits.RE0
#define BOULE_13 PORTAbits.RA6
#define BOULE_14 PORTCbits.RC3

#define ETOILE PORTDbits.RD0

#define SAPIN_0 PORTDbits.RD2
#define SAPIN_1 PORTCbits.RC4
#define SAPIN_2 PORTDbits.RD4
#define SAPIN_3 PORTDbits.RD3
#define SAPIN_4 PORTCbits.RC6
#define SAPIN_5 PORTCbits.RC5
#define SAPIN_6 PORTCbits.RC7
#define SAPIN_7 PORTDbits.RD6
#define SAPIN_8 PORTBbits.RB0
#define SAPIN_8bis PORTDbits.RD1
#define SAPIN_9 PORTBbits.RB6
#define SAPIN_10 PORTBbits.RB2
#define SAPIN_11 PORTBbits.RB1
#define SAPIN_12 PORTBbits.RB7
#define SAPIN_13 PORTBbits.RB4
#define SAPIN_14 PORTBbits.RB5
#define SAPIN_15 PORTBbits.RB3
#define SAPIN_16 PORTDbits.RD7
#define SAPIN_17 PORTDbits.RD5

 //
//-------------------------------------
// FONCTIONS 74HC165 / 595 (entrées séries // Sorties parallèles)
//-------------------------------------

void BOULE_IMPAIRE_ON(){
          BOULE_1 = ON;
          BOULE_3 = ON;
          BOULE_5 = ON;
          BOULE_7 = ON;
          BOULE_9 = ON;
          BOULE_11 = ON;
          BOULE_13 = ON;
}
void BOULE_IMPAIRE_OFF(){
          BOULE_1 = OFF;
          BOULE_3 = OFF;
          BOULE_5 = OFF;
          BOULE_7 = OFF;
          BOULE_9 = OFF;
          BOULE_11 = OFF;
          BOULE_13 = OFF;
}
void BOULE_PAIRE_ON(){
          BOULE_0 = ON;
          BOULE_2 = ON;
          BOULE_4 = ON;
          BOULE_6 = ON;
          BOULE_8 = ON;
          BOULE_10 = ON;
          BOULE_12 = ON;
          BOULE_14 = ON;
}
void BOULE_PAIRE_OFF(){
          BOULE_0 = OFF;
          BOULE_2 = OFF;
          BOULE_4 = OFF;
          BOULE_6 = OFF;
          BOULE_8 = OFF;
          BOULE_10 = OFF;
          BOULE_12 = OFF;
          BOULE_14 = OFF;
}

void ALL_BOULE_OFF(){
    BOULE_0 = OFF;
      BOULE_1 = OFF;
      BOULE_2 = OFF;
      BOULE_3 = OFF;
      BOULE_4 = OFF;
      BOULE_5 = OFF;
      BOULE_6 = OFF;
      BOULE_7 = OFF;
      BOULE_8 = OFF;
      BOULE_9 = OFF;
      BOULE_10 = OFF;
      BOULE_11 = OFF;
      BOULE_12 = OFF;
      BOULE_13 = OFF;
      BOULE_14 = OFF;
}

void ALL_BOULE_ON(){
    BOULE_0 = ON;
      BOULE_1 = ON;
      BOULE_2 = ON;
      BOULE_3 = ON;
      BOULE_4 = ON;
      BOULE_5 = ON;
      BOULE_6 = ON;
      BOULE_7 = ON;
      BOULE_8 = ON;
      BOULE_9 = ON;
      BOULE_10 = ON;
      BOULE_11 = ON;
      BOULE_12 = ON;
      BOULE_13 = ON;
      BOULE_14 = ON;
}

void ALL_SAPIN_OFF(){
    SAPIN_0 = OFF;
      SAPIN_1 = OFF;
      SAPIN_2 = OFF;
      SAPIN_3 = OFF;
      SAPIN_4 = OFF;
      SAPIN_5 = OFF;
      SAPIN_6 = OFF;
      SAPIN_7 = OFF;
      SAPIN_8 = OFF;
      SAPIN_8bis = OFF;
      SAPIN_9 = OFF;
      SAPIN_10 = OFF;
      SAPIN_11 = OFF;
      SAPIN_12 = OFF;
      SAPIN_13 = OFF;
      SAPIN_14 = OFF;
      SAPIN_15 = OFF;
      SAPIN_16 = OFF;
      SAPIN_17 = OFF;
}

void ALL_SAPIN_ON(){
      SAPIN_0 = ON;
      SAPIN_1 = ON;
      SAPIN_2 = ON;
      SAPIN_3 = ON;
      SAPIN_4 = ON;
      SAPIN_5 = ON;
      SAPIN_6 = ON;
      SAPIN_7 = ON;
      SAPIN_8 = ON;
      SAPIN_8bis = ON;
      SAPIN_9 = ON;
      SAPIN_10 = ON;
      SAPIN_11 = ON;
      SAPIN_12 = ON;
      SAPIN_13 = ON;
      SAPIN_14 = ON;
      SAPIN_15 = ON;
      SAPIN_16 = ON;
      SAPIN_17 = ON;
}
void PAIR_SAPIN_OFF(){
      SAPIN_0 = OFF;
      SAPIN_2 = OFF;
      SAPIN_4 = OFF;
      SAPIN_6 = OFF;
      SAPIN_8 = OFF;
      SAPIN_9 = OFF;
      SAPIN_11 = OFF;
      SAPIN_13 = OFF;
      SAPIN_15 = OFF;
      SAPIN_17 = OFF;
}
void PAIR_SAPIN_ON(){
      SAPIN_0 = ON;
      SAPIN_2 = ON;
      SAPIN_4 = ON;
      SAPIN_6 = ON;
      SAPIN_8 = ON;
      SAPIN_9 = ON;
      SAPIN_11 = ON;
      SAPIN_13 = ON;
      SAPIN_15 = ON;
      SAPIN_17 = ON;
}

void IMPAIR_SAPIN_ON(){
      SAPIN_1 = ON;
      SAPIN_3 = ON;
      SAPIN_5 = ON;
      SAPIN_7 = ON;
      SAPIN_8bis = ON;
      SAPIN_10 = ON;
      SAPIN_12 = ON;
      SAPIN_14 = ON;
      SAPIN_16 = ON;
}

void IMPAIR_SAPIN_OFF(){
      SAPIN_1 = OFF;
      SAPIN_3 = OFF;
      SAPIN_5 = OFF;
      SAPIN_7 = OFF;
      SAPIN_8bis = OFF;
      SAPIN_10 = OFF;
      SAPIN_12 = OFF;
      SAPIN_14 = OFF;
      SAPIN_16 = OFF;
}

//----------------------------------------------------------------------------
// Main routine
//----------------------------------------------------------------------------
void main ()
{

    void BOULE_PAIRE_ON();
    void BOULE_PAIRE_OFF();
    void BOULE_IMPAIRE_ON();
    void BOULE_IMPAIRE_OFF();
    void ALL_BOULE_OFF();
    void ALL_BOULE_ON();
    void ALL_SAPIN_OFF();
    void ALL_SAPIN_ON();
    void PAIR_SAPIN_ON();
    void IMPAIR_SAPIN_ON();
    void PAIR_SAPIN_OFF();
    void IMPAIR_SAPIN_OFF();
 //void tab_boule[15] = {BOULE_0,BOULE_1,BOULE_2,BOULE_3,BOULE_4,BOULE_5,BOULE_6,BOULE_7,BOULE_8,BOULE_9,BOULE_10,BOULE_11,BOULE_12,BOULE_13,BOULE_14};
 //void tab_sapin[18] = {SAPIN_0,SAPIN_1,SAPIN_2,SAPIN_3,SAPIN_4,SAPIN_5,SAPIN_6,SAPIN_7,SAPIN_8,SAPIN_9,SAPIN_10,SAPIN_11,SAPIN_12,SAPIN_13,SAPIN_14, SAPIN_15, SAPIN_16, SAPIN_17};
 int toggle = 0;

 INTCONbits.GIEH = 0;	// inhibe les interuptions
 TRISA = 0x00;
 TRISB = 0x00; 			//RB0, RB1, RB2 en entrée
 TRISC = 0x00;
 TRISD = 0x00;
 TRISE = 0x00;			// RE0 et RE1 en sortie
 PORTA = 0x00;
 PORTB = 0x00;
 PORTC = 0x00;
 PORTD = 0x00;
 PORTE = 0x00;

 OSCCONbits.IRCF = 0x7;
 OSCCONbits.SCS = 0x2;

 ADCON1bits.PCFG = 0xF;

 INTCONbits.PEIE = 0;
 INTCONbits.GIEH = 0;


  do {

      // Declaration compteurs boucle
      int i=0;
      int compt_etoile;
      int compt_guir;
      int compt_clign;

      for(i=0;i<3;i++){
          BOULE_0 = ON;
          Delay10KTCYx(20);
          BOULE_0 = OFF;
          BOULE_1 = ON;
          Delay10KTCYx(20);
          BOULE_1 = OFF;
          BOULE_2 = ON;
          Delay10KTCYx(20);
          BOULE_2 = OFF;
          BOULE_3 = ON;
          Delay10KTCYx(20);
          BOULE_3 = OFF;
          BOULE_4 = ON;
          Delay10KTCYx(20);
          BOULE_4 = OFF;
          BOULE_5 = ON;
          Delay10KTCYx(20);
          BOULE_5 = OFF;
          BOULE_6 = ON;
          Delay10KTCYx(20);
          BOULE_6 = OFF;
          BOULE_7 = ON;
          Delay10KTCYx(20);
          BOULE_7 = OFF;
          BOULE_8 = ON;
          Delay10KTCYx(20);
          BOULE_8 = OFF;
          BOULE_9 = ON;
          Delay10KTCYx(20);
          BOULE_9 = OFF;
          BOULE_10 = ON;
          Delay10KTCYx(20);
          BOULE_10 = OFF;
          BOULE_11 = ON;
          Delay10KTCYx(20);
          BOULE_11 = OFF;
          BOULE_12 = ON;
          Delay10KTCYx(20);
          BOULE_12 = OFF;
          BOULE_13 = ON;
          Delay10KTCYx(20);
          BOULE_13 = OFF;
          BOULE_14 = ON;
          Delay10KTCYx(20);
          BOULE_14 = OFF;

          ETOILE = ON;
          Delay10KTCYx(10);
          ETOILE = OFF;
          Delay10KTCYx(10);
          ETOILE = ON;
          Delay10KTCYx(10);
          ETOILE = OFF;
          Delay10KTCYx(10);
          ETOILE = OFF;
          Delay10KTCYx(10);
          ETOILE = ON;
          Delay10KTCYx(10);
          ETOILE = OFF;

           if(toggle == 0) {
               ALL_SAPIN_ON();
          toggle = 1;
           }else{
               ALL_SAPIN_OFF();
          toggle = 0;
           }

          //// Clignotement Etoile 15ms
          ETOILE = ON;
          Delay10KTCYx(15);
          ETOILE = OFF;
          Delay10KTCYx(15);
          ETOILE = ON;
          Delay10KTCYx(15);
          ETOILE = OFF;
          Delay10KTCYx(15);
          ETOILE = ON;
          Delay10KTCYx(15);
          ETOILE = OFF;
          Delay10KTCYx(15);
      }
      ////// 2nd MOTIF

      for(i=0;i<2;i++){
		  
		  ALL_SAPIN_OFF();
		  ALL_BOULE_OFF();

          
    ///////////////// Eteint Etoile
          ETOILE = OFF ;

    ///////////////// Montée Guirlande vitesse progressive
          ALL_BOULE_OFF();
          Delay10KTCYx(20);

          BOULE_0 = ON;
          Delay10KTCYx(75);
          BOULE_0 = OFF;
          BOULE_1 = ON;
          Delay10KTCYx(70);
          BOULE_1 = OFF;
          BOULE_2 = ON;
          Delay10KTCYx(65);
          BOULE_2 = OFF;
          BOULE_3 = ON;
          Delay10KTCYx(60);
          BOULE_3 = OFF;
          BOULE_4 = ON;
          Delay10KTCYx(55);
          BOULE_4 = OFF;
          BOULE_5 = ON;
          Delay10KTCYx(50);
          BOULE_5 = OFF;
          BOULE_6 = ON;
          Delay10KTCYx(45);
          BOULE_6 = OFF;
          BOULE_7 = ON;
          Delay10KTCYx(40);
          BOULE_7 = OFF;
          BOULE_8 = ON;
          Delay10KTCYx(35);
          BOULE_8 = OFF;
          BOULE_9 = ON;
          Delay10KTCYx(30);
          BOULE_9 = OFF;
          BOULE_10 = ON;
          Delay10KTCYx(25);
          BOULE_10 = OFF;
          BOULE_11 = ON;
          Delay10KTCYx(20);
          BOULE_11 = OFF;
          BOULE_12 = ON;
          Delay10KTCYx(15);
          BOULE_12 = OFF;
          BOULE_13 = ON;
          Delay10KTCYx(10);
          BOULE_13 = OFF;
          BOULE_14 = ON;
          Delay10KTCYx(5);
          BOULE_14 = OFF;

          ////////////Clignotement étoile 10ms

          for (compt_etoile=0;compt_etoile<10;compt_etoile++){
          ETOILE = ON;
          Delay10KTCYx(10);
          ETOILE = OFF;
          Delay10KTCYx(10);
          }

          ///////////// Descente tout 10ms
          ETOILE = ON ;

          SAPIN_7 = ON;
          SAPIN_8bis = ON;
          BOULE_14 = ON;
          Delay10KTCYx(10);
          SAPIN_8 = ON;
          SAPIN_6 = ON;
          BOULE_13 = ON;
          Delay10KTCYx(10);
          SAPIN_9 = ON;
          SAPIN_5 = ON;
          BOULE_12 = ON;
          Delay10KTCYx(10);
          SAPIN_10 = ON;
          SAPIN_4 = ON;
          BOULE_11 = ON;
          Delay10KTCYx(10);
          SAPIN_11 = ON;
          SAPIN_3 = ON;
          BOULE_10 = ON;
          Delay10KTCYx(10);
          SAPIN_12 = ON;
          SAPIN_2 = ON;
          BOULE_9 = ON;
          Delay10KTCYx(5);
          BOULE_8 = ON;
          Delay10KTCYx(5);
          SAPIN_13 = ON;
          SAPIN_1 = ON;
          BOULE_7 = ON;
          Delay10KTCYx(5);
          BOULE_6 = ON;
          Delay10KTCYx(5);
          SAPIN_14 = ON;
          SAPIN_0 = ON;
          BOULE_5 = ON;
          Delay10KTCYx(5);
          BOULE_4 = ON;
          Delay10KTCYx(5);
          SAPIN_15 = ON;
          SAPIN_17 = ON;
          BOULE_3 = ON;
          Delay10KTCYx(5);
          BOULE_2 = ON;
          Delay10KTCYx(5);
          SAPIN_16 = ON;
          BOULE_1 = ON;
          Delay10KTCYx(5);
          BOULE_0 = ON;
          Delay10KTCYx(10);


          //////// Allumage guirlande paires/impaires

              for(compt_guir=0; compt_guir<NBR_SAPIN;compt_guir++){
                  BOULE_IMPAIRE_ON();
                  Delay10KTCYx(15);
                  BOULE_IMPAIRE_OFF();
                  //tab_sapin[compt_guir]=ON;
                  BOULE_PAIRE_ON();
                  Delay10KTCYx(15);
                  BOULE_PAIRE_OFF();
              }
       }
      //////// LAST MOTIF

      for(i=0;i<2;i++){
          ALL_SAPIN_OFF();

          ALL_BOULE_ON();

          SAPIN_8 = ON;
          Delay10KTCYx(20);
          SAPIN_9 = ON;
          Delay10KTCYx(20);
          SAPIN_10 = ON;
          Delay10KTCYx(20);
          SAPIN_11 = ON;
          Delay10KTCYx(20);
          SAPIN_12 = ON;
          Delay10KTCYx(20);
          SAPIN_13 = ON;
          Delay10KTCYx(20);
          SAPIN_14 = ON;
          Delay10KTCYx(20);
          SAPIN_15 = ON;
          Delay10KTCYx(20);
          SAPIN_16 = ON;
          Delay10KTCYx(20);
          SAPIN_17 = ON;
          Delay10KTCYx(20);
          SAPIN_0 = ON;
          Delay10KTCYx(20);
          SAPIN_1 = ON;
          Delay10KTCYx(20);
          SAPIN_2 = ON;
          Delay10KTCYx(20);
          SAPIN_3 = ON;
          Delay10KTCYx(20);
          SAPIN_4 = ON;
          Delay10KTCYx(20);
          SAPIN_5 = ON;
          Delay10KTCYx(20);
          SAPIN_6 = ON;
          Delay10KTCYx(20);
          SAPIN_7 = ON;
          Delay10KTCYx(20);
          SAPIN_8bis = ON;
          Delay10KTCYx(20);

          /// Clignotement altenatif SAPIN/GUIRLANDE
          for(compt_clign=0;compt_clign<20;compt_clign++){
              ALL_SAPIN_OFF();
              ALL_BOULE_ON();
              ETOILE = ON;
              Delay10KTCYx(15);
              ALL_SAPIN_ON();
              ALL_BOULE_OFF();
              ETOILE = OFF;
              Delay10KTCYx(15);
          }
      }
      for(i=0;i<2;i++){
          ALL_SAPIN_OFF();
          ALL_BOULE_OFF();
         //////////// Descente parallèle sapin 20ms

          SAPIN_7 = ON;
          SAPIN_8bis = ON;
          Delay10KTCYx(20);
          SAPIN_7 = OFF;
          SAPIN_8bis = OFF;

          SAPIN_8 = ON;
          SAPIN_6 = ON;
          Delay10KTCYx(20);
          SAPIN_8 = OFF;
          SAPIN_6 = OFF;

          SAPIN_9 = ON;
          SAPIN_5 = ON;
          Delay10KTCYx(20);
          SAPIN_9 = OFF;
          SAPIN_5 = OFF;

          SAPIN_10 = ON;
          SAPIN_4 = ON;
          Delay10KTCYx(20);
          SAPIN_10 = OFF;
          SAPIN_4 = OFF;

          SAPIN_11 = ON;
          SAPIN_3 = ON;
          Delay10KTCYx(20);
          SAPIN_11 = OFF;
          SAPIN_3 = OFF;

          SAPIN_12 = ON;
          SAPIN_2 = ON;
          Delay10KTCYx(20);
          SAPIN_12 = OFF;
          SAPIN_2 = OFF;

          SAPIN_13 = ON;
          SAPIN_1 = ON;
          Delay10KTCYx(20);
          SAPIN_13 = OFF;
          SAPIN_1 = OFF;

          SAPIN_14 = ON;
          SAPIN_0 = ON;
          Delay10KTCYx(20);
          SAPIN_14 = OFF;
          SAPIN_0 = OFF;

          SAPIN_15 = ON;
          SAPIN_17 = ON;
          Delay10KTCYx(20);
          SAPIN_15 = OFF;
          SAPIN_17 = OFF;

          SAPIN_16 = ON;
          Delay10KTCYx(20);
          SAPIN_16 = OFF;

          ////Allumage sapin bad --> haut / Parallèle 10ms
          SAPIN_16 = ON;
          Delay10KTCYx(10);
          SAPIN_15 = ON;
          Delay10KTCYx(10);
          SAPIN_17 = ON;
          Delay10KTCYx(10);
          SAPIN_14 = ON;
          Delay10KTCYx(10);
          SAPIN_0 = ON;
          Delay10KTCYx(10);
          SAPIN_13 = ON;
          Delay10KTCYx(10);
          SAPIN_1 = ON;
          Delay10KTCYx(10);
          SAPIN_12 = ON;
          Delay10KTCYx(10);
          SAPIN_2 = ON;
          Delay10KTCYx(10);
          SAPIN_11 = ON;
          Delay10KTCYx(10);
          SAPIN_3 = ON;
          Delay10KTCYx(10);
          SAPIN_10 = ON;
          Delay10KTCYx(10);
          SAPIN_4 = ON;
          Delay10KTCYx(10);
          SAPIN_9 = ON;
          Delay10KTCYx(10);
          SAPIN_5 = ON;
          Delay10KTCYx(10);
          SAPIN_8 = ON;
          Delay10KTCYx(10);
          SAPIN_6 = ON;
          Delay10KTCYx(10);
          SAPIN_8bis = ON;
          Delay10KTCYx(10);
          SAPIN_7 = ON;
          Delay10KTCYx(50);

          ALL_SAPIN_OFF();
          Delay10KTCYx(30);

          //Allumage pair/impair sapin+guirlande

         for(compt_guir=0; compt_guir<15;compt_guir++){
              ETOILE=ON;
              BOULE_PAIRE_OFF();
              IMPAIR_SAPIN_OFF();
              PAIR_SAPIN_ON();
              BOULE_IMPAIRE_ON();
              Delay10KTCYx(15);
              ETOILE=OFF;
              BOULE_IMPAIRE_OFF();
              BOULE_PAIRE_ON();
              Delay10KTCYx(15);
              ETOILE=ON;
              BOULE_PAIRE_OFF();
              IMPAIR_SAPIN_ON();
              PAIR_SAPIN_OFF();
              BOULE_IMPAIRE_ON();
              Delay10KTCYx(15);
              ETOILE=OFF;
              BOULE_IMPAIRE_OFF();
              BOULE_PAIRE_ON();
              Delay10KTCYx(15);
         }
          ALL_SAPIN_OFF();
          ALL_BOULE_OFF();
      }

/*
      *tab[0] = ON;
      *tab[14] = OFF;
      for(i=1;i<15;i++){
          *tab[i] = ON;
          *tab[i-1] = OFF;
          Delay10KTCYx(150);
      }*/

  }while(1);
} // end main
