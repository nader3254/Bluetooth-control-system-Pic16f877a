/*
 * File:   uart.c
 * Author: Nader
 *
 * Created on May 29, 2022, 11:36 PM
 */


#include "uart.h"
#include <math.h>
#include "lcd.h"

/********************************************************************/
/*                        F U N C T I O N S                        */
/******************************************************************/
void    UART_TX_Init(void) 
{
  
     TXSTAbits.BRGH = 1;
 
    SPBRG = Baud;                  //Writing SPBRG Register
  
  //--[ Enable The Ascynchronous Serial Port ]--
  TXSTAbits.SYNC = 0;
  RCSTAbits.SPEN = 1;
  //--[ Set The RX-TX Pins to be in UART mode (not io) ]--
  TRISCbits.TRISC6 = 1;           // As stated in the datasheet
  TRISCbits.TRISC7 = 1;           // As stated in the datasheet
  TXSTAbits.TXEN = 1;             // Enable UART Transmission
}
/******************************************************************/
void    UART_RX_Init()
{
  TXSTAbits.BRGH = 1;
  SPBRG = Baud;                  //Writing SPBRG Register
 
  // Enable The Ascynchronous Serial Port
  TXSTAbits.SYNC = 0;
  RCSTAbits.SPEN = 1;
  // Set The RX-TX Pins to be in UART mode (not io)
  TRISCbits.TRISC6 = 1;                 // As stated in the datasheet
  TRISCbits.TRISC7 = 1;                // As stated in the datasheet
  //--[ Enable UART Receiving Interrupts ]--
  PIE1bits.RCIE = 1;                 // UART Receving Interrupt Enable Bit
 
  INTCONbits.PEIE = 1;              // Peripherals Interrupt Enable Bit
  INTCONbits.GIE = 1;               // Global Interrupt Enable Bit
  //------------------
  
  RCSTAbits.CREN = 1;           // Enable Data Continous Reception
}

void    UART_Write(uint8_t data)
{
  while(!UART_TX_Empty());
  TXREG = data;
   
}
/******************************************************************/
void UART_Write_String(unsigned char *text)
{
  uint16_t i;
  for(i=0;text[i]!='\0';i++)
    UART_Write(text[i]);
}
/******************************************************************/
uint8_t UART_Read()
{
  while(!RCIF); // Wait Untill a Data Frame is Received
  return RCREG;
}
/*****************************************************************/
void UART_Read_String(uint8_t *Output, uint16_t length)  //has alot of bugs 
{
  uint16_t i;
  for(int i=0;i<length;i++){
      Output[i] = UART_Read();
      //LCD_Write_Char('i');
       Clear_Recieved_Status();
  }
  
  
  
  
   
  
}
/******************************************************************/
uint8_t UART_TX_Empty()
{
 // Check the output (transmitter) buffer emptiness
  return TXSTAbits.TRMT;
}
/******************************************************************/
uint8_t Is_Data_Recieved()
{
    return PIR1bits.RCIF;       //this flag will be set when receiving data
}
/******************************************************************/
void    Clear_Recieved_Status()
{
    PIR1bits.RCIF = 0 ;
}
/******************************************************************/

