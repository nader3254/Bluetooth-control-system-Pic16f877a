/*
 * File:   led.c
 * Author: Nader
 *
 * Created on May 29, 2022, 4:11 AM
 */


#include <xc.h>
#include "led.h"

/************************************************************************************/
/*                              F U N T I O N S                                     */
 /***********************************************************************************/
void  new_led(unsigned char pin_number )
{
   
    switch(pin_number)
    {
        case A0:
            TRISAbits.TRISA0 = OUTPUT ;
            ADCON1=6;
            RA0=0;
            
            break;
        case E0:
            TRISEbits.TRISE0 = 0 ;
             PORTEbits.RE0=0;
           
            break;
        case D0:
            TRISDbits.TRISD0 = OUTPUT ;
             RD0=0;
            
            break;
        case C3:
            TRISCbits.TRISC3 = OUTPUT ;
             RC3=0;
            
            break;
        case A4:
            TRISAbits.TRISA4 = OUTPUT ;
             RA4=0;
            
            break;
        case A5:
            TRISAbits.TRISA5 = OUTPUT ;
             RA5=0;
            
            break;
        case B0:
            TRISBbits.TRISB0 = OUTPUT ;
             RB0=0;
            
            break;
        case B1:
           TRISBbits.TRISB1 = OUTPUT ;
             RB1=0;
            
            break;
        default:
            
            break;
    }
    
}
/*
void toggle(unsigned char pin_number,st ledstate)
{
    switch(pin_number) 
   {
       case A0:
           
           if(ledstate==off)
           {
               led_on(pin_number);
               ledstate=on;
           }
           else
           {
               led_off(pin_number);
               ledstate=off; 
           }
            
            break;
        case A1:
         
            
           
           
                
           
           
            break;
        case A2:
           
             RA2=0;
            break;
        case A3:
            
             RA3= ~RA3;
            break;
        case A4:
           
             RA4=0;
            
            break;
        case A5:
            
             RA5=0;
            break;
        case B0:
        
             RB0=0;
           
            break;
        case B1:
           
             RB1=0;
           
            break;
        default:
           
            break;
       
       
       
   }
      
}
*/
void led_on(unsigned char pin_number)
{
   switch( pin_number) 
   {
       case A0:
           
            PORTA |=(1<<RA0);
            
            
            break;
       case E0:
         
             RE0=1;
            
            break;
        case D0:
           
             RD0=1;
           
            break;
        case C3:
            
             RC3=1;
           
            break;
        case A4:
           
             RA4=1;
           
            break;
        case A5:
            
             RA5 = 1;
         
            break;
        case B0:
        
             RB0=1;
          
            break;
        case B1:
           
             RB1=1;
         
            break;
        default:
            
            break;
       
       
       
   }
}
void led_off(unsigned char pin_number)
{
       switch(pin_number) 
   {
       case A0:
           
            RA0=0;
            
            break;
        case E0:
         
             RE0=0;
            break;
        case D0:
           
             RD0=0;
            break;
        case C3:
            
             RC3=0;
            break;
        case A4:
           
             RA4=0;
            
            break;
        case A5:
            
             RA5 = 0;
            break;
        case B0:
        
             RB0=0;
           
            break;
        case B1:
           
             RB1=0;
           
            break;
        default:
           
            break;
       
       
       
   }
}

