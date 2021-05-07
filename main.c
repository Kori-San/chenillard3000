#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>

// Function Prot
void Init_BP(void); //Function that Init the Button (Here Pin P2.5 and P2.0 are used)
void Init_Chenillard (void);
unsigned int GetState_Button(void);
unsigned int Push_BP(void);
void Chenillard(unsigned char Val,unsigned int Seq);
void delay_ms(unsigned int Time_in_ms);
// End Function Prot

// Global Var
unsigned int OldState_Button = 0;
unsigned int var_delay = 100 ;
unsigned int Sequence = 1 ;
// End Global Var

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
 // Pin Config
  Init_BP();         // Init Button
  Init_Chenillard(); //InitChenillard
 // End Pin Config
  OldState_Button  = GetState_Button();
  
 while(1)
 {
  Chenillard(0, Sequence);
 }
}

 void Init_BP(void)
 {
	P2DIR &= ~ (1<<5);
	P2REN |= (1<<5);
	P2OUT |= (1<<5); // P2.5 Out
	P2DIR |= (1<<0); // P2.0 Out
 }

 void Init_Chenillard (void)
 {
  //(Here the PINs for the LEDs P1.2,P4.3,P4.0,P3.7 and P3.0,P3.1,P2.6,P2.3)
  P1DIR |= (1<<2); // P3.7 Out LED:1
  P3DIR |= (1<<0); // P4.0 Out LED:2
  P4DIR |= (1<<3); // P4.3 Out LED:3
  P3DIR |= (1<<1); // P1.2 Out LED:4
  P4DIR |= (1<<0); // P3.0 Out LED:5
  P2DIR |= (1<<6); // P3.1 Out LED:6
  P3DIR |= (1<<7); // P2.6 Out LED:7
  P2DIR |= (1<<3); // P2.3 Out LED:8
 }

 unsigned int GetState_Button(void)
 {
  unsigned int state;
  if (!((P2IN & (1<<5)) == (1<<5)) ) {state=0;}
  else {state=1;}
  return state;
 }

 unsigned int Push_BP(void)
 {
  if ((OldState_Button==1)&&(GetState_Button()==0))
  {
   if (Sequence == 1)
   {
	Sequence = 2;
	Chenillard(1,0);
   }
   else if (Sequence == 2)
   {
	Sequence = 1;
	Chenillard(1,0);
   }
   OldState_Button  = GetState_Button();
   return EXIT_SUCCESS;
  }
  OldState_Button  = GetState_Button();
  return EXIT_FAILURE;
 }

 void Chenillard(unsigned char Val,unsigned int Seq)
 {
  if (Val == 0) //If 0 can do switches 1 and 2
  {
   if (Seq == 1)
   {
    P3OUT |= (1<<7);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<7); if (Push_BP() == 0) { return; } // LED:1 P3.7
    P4OUT |= (1<<0);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<0); if (Push_BP() == 0) { return; } // LED:2 P4.0
    P4OUT |= (1<<3);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<3); if (Push_BP() == 0) { return; } // LED:3 P4.3
    P1OUT |= (1<<2);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P1OUT &=  ~(1<<2); if (Push_BP() == 0) { return; } // LED:4 P1.2
    P3OUT |= (1<<0);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<0); if (Push_BP() == 0) { return; } // LED:5 P3.0
    P3OUT |= (1<<1);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<1); if (Push_BP() == 0) { return; } // LED:6 P3.1
    P2OUT |= (1<<6);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P2OUT &=  ~(1<<6); if (Push_BP() == 0) { return; } // LED:7 P2.6
    P2OUT |= (1<<3);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P2OUT &=  ~(1<<3); if (Push_BP() == 0) { return; } // LED:8 P2.3
    P2OUT |= (1<<6);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P2OUT &=  ~(1<<6); if (Push_BP() == 0) { return; } // LED:7 P2.6
    P3OUT |= (1<<1);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<1); if (Push_BP() == 0) { return; } // LED:6 P3.1
    P3OUT |= (1<<0);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<0); if (Push_BP() == 0) { return; } // LED:5 P3.0
    P1OUT |= (1<<2);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P1OUT &=  ~(1<<2); if (Push_BP() == 0) { return; } // LED:4 P1.2
    P4OUT |= (1<<3);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<3); if (Push_BP() == 0) { return; } // LED:3 P4.3
    P4OUT |= (1<<0);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<0); if (Push_BP() == 0) { return; } // LED:2 P4.0
    P3OUT |= (1<<7);  if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<7); if (Push_BP() == 0) { return; } // LED:1 P3.7
   }
   else if (Seq == 2)
   {
    P3OUT |= (1<<7) ; P2OUT |= (1<<3); if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P3OUT &=  ~(1<<7); P2OUT &=  ~(1<<3); if (Push_BP() == 0) { return; } // LED:1 P3.7 and LED:8 P2.3
    P4OUT |= (1<<0) ; P2OUT |= (1<<6); if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<0); P2OUT &=  ~(1<<6); if (Push_BP() == 0) { return; } // LED:2 P4.0 and LED:7 P2.6
    P4OUT |= (1<<3) ; P3OUT |= (1<<1); if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P4OUT &=  ~(1<<3); P3OUT &=  ~(1<<1); if (Push_BP() == 0) { return; } // LED:3 P4.3 and LED:6 P3.1
    P1OUT |= (1<<2) ; P3OUT |= (1<<0); if (Push_BP() == 0) { return; } ; delay_ms(var_delay); P1OUT &=  ~(1<<2); P3OUT &=  ~(1<<0); if (Push_BP() == 0) { return; } // LED:4 P1.2 and LED:5 P3.0
   }
  }
  else if (Val == 1) //if 1 all LEDs are off
  {
   P3OUT &=  ~(1<<7);
   P2OUT &=  ~(1<<3);
   P4OUT &=  ~(1<<0);
   P2OUT &=  ~(1<<6);
   P4OUT &=  ~(1<<3);
   P3OUT &=  ~(1<<1);
   P1OUT &=  ~(1<<2);
   P3OUT &=  ~(1<<0);
  }
 }

 void delay_ms(unsigned int Time_in_ms)
 {
   while (Time_in_ms--)
   {
     __delay_cycles(1000); // 1 for 1MHz
   }
 }
