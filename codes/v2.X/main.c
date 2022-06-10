/*
 * File:   main.c
 * Author: Nader
 *
 * Created on May 29, 2022, 3:51 AM
 */


#include <xc.h>
#include "config.h"
#include "led.h"
#include "lcd.h"
#include "uart.h"

/******************************************************************/
/*                   D E F I N I T I O N S 
*******************************************************************/   

#define BLUE_LED_ON     49  /*     ASCI VALUE  OF 1 IS 49   */  
#define RED_LED_ON      51  /*     ASCI VALUE  OF 2 IS 50   */ 
#define GREEN_LED_ON    53  /*     ASCI VALUE  OF 3 IS 51   */ 
#define YELLOW_LED_ON   55  /*     ASCI VALUE  OF 4 IS 52   */ 
#define WHITE_LED_ON    80  /*     ASCI VALUE  OF 5 IS 53   */ 

#define BLUE_LED_OFF     50  /*     ASCI VALUE  OF 2 IS 50   */  
#define RED_LED_OFF      52  /*     ASCI VALUE  OF 4 IS 55   */ 
#define GREEN_LED_OFF    54  /*     ASCI VALUE  OF 8 IS 56   */ 
#define YELLOW_LED_OFF   56  /*     ASCI VALUE  OF 9 IS 57   */ 
#define WHITE_LED_OFF    90  /*     ASCI VALUE  OF : IS 58  */ 

#define BLUE_LED     A0  /*      BLUE LED ON PIN A0       */  
#define RED_LED      E0  /*      BLUE LED ON PIN E0       */ 
#define GREEN_LED    C3  /*      BLUE LED ON PIN A2       */ 
#define YELLOW_LED   D0  /*      BLUE LED ON PIN A3       */ 
#define WHITE_LED    B0  /*      BLUE LED ON PIN B0       */ 


uint8_t start_once =1;
/**********************************************************************/ 
/*                      P R O T O T Y P I N G                        */
/*********************************************************************/
unsigned char RecievedData =0;

void  start_led_actions();
void  start_led_actions2();
void  splash_screen();
void  led_testing();
void  screen_saver();
void  instruction_screen();


void main(void) 
{
  /*      initialize lcd           */
  LCD_Init();
  LCD_Set_Cursor(1,1);
  /*     initialize the uart      */
  UART_RX_Init();
  
  
  

 
//_______________ O P E R E A T I N G     L O O P ____________________//
  
   while(1)
   {
       if(start_once==1)
       {
          splash_screen(); 
          start_once =0;
       }
       
    if(UART_Read()=='1')  
    {
        led_on(BLUE_LED); 
    }
    start_led_actions();

    
       screen_saver();
       instruction_screen();
     
       
     
       
   }
    
    return;
}
/**********************************************************************/
/*_____U A R T___I N T E R R U P T____S E R V I C E____R O U T I N E___/                                                     */
/**********************************************************************/
void interrupt ISR (void)
{
   
    if (Is_Data_Recieved() == 1)
  {  
     
  //  RecievedData =  UART_Read();
   // Clear_Recieved_Status();
   // start_led_actions();  
       
  }
    
 
}
/*************************************************************************/
/*______T H I S____I S_____T H E____S P L A S H____S C R E E N__________*/
/************************************************************************/
//later mission : this methods should be in the bootloader section //
void splash_screen()
{
     /*************** WELECOME *****************/
  /*
   *   LCD_Clear();
    
    LCD_Write_String(" Welecome To ");
    LCD_Set_Cursor(2,1);
    LCD_Write_String("BLUETOOTH PIC .....");
    __delay_ms(2000);
   
   /************* TEAM NAMES *******************/
    
 /*   LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("FAKHRY AHMED  ");
    LCD_Set_Cursor(2,1);
    LCD_Write_String("MAHMOUD RASHAD ");
    __delay_ms(2000);
    
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("AMR GAMAL  ");
    LCD_Set_Cursor(2,1);
    LCD_Write_String("YOUSEF MOHAMED ");
    __delay_ms(2000);
    
      LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("MAHMOUD ABDALRAHMAN ");
    LCD_Set_Cursor(2,1);
    LCD_Write_String("MAHMOUD METWALY ");
    __delay_ms(2000);
    
       LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("MAHMOUD REDA  ");
    LCD_Set_Cursor(2,1);
    LCD_Write_String("NADER HANY");
    __delay_ms(2000);*/
    
    /**************** INITIALIZING **********************/
  /*  LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("INITIALIZING..... \0");
    LCD_Set_Cursor(2,1);
    for(int i=0;i<16;i++)
    {
        LCD_Write_Char('#');
        __delay_ms(50);
    }
    /*     initialize the leds     */
    new_led(BLUE_LED);
    new_led(RED_LED);
    new_led(GREEN_LED);
    new_led(YELLOW_LED);
    new_led(WHITE_LED);
    __delay_ms(800);
    LCD_Clear();
    
    /***************** TESTING ********************/ 
 /*   LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("TESTING..... \0");
    LCD_Set_Cursor(2,1);
    for(int i=0;i<16;i++)
    {
        LCD_Write_Char('#');
        __delay_ms(50);
    }*/
    led_testing();
   // __delay_ms(800);
   // LCD_Clear();
    
    /***************** TEST SUCCESSFUL **********************/ 
 /*   LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("TEST OK.... \0");
    LCD_Set_Cursor(1,1);
    LCD_Write_String("System is ready.... \0");
    __delay_ms(800);*/
    
}
/****************************************************************************/
/*                   M O D U L E      T E S T I N G                         */
/***************************************************************************/
void  led_testing()
{
       RecievedData = BLUE_LED_ON;
       start_led_actions2();
       __delay_ms(100);
      RecievedData = BLUE_LED_OFF;
      start_led_actions2();
       __delay_ms(100);
       
       RecievedData = RED_LED_ON;
       start_led_actions2();
       __delay_ms(100);
      RecievedData = RED_LED_OFF;
      start_led_actions2();
       __delay_ms(100);
       
          RecievedData = GREEN_LED_ON;
       start_led_actions2();
       __delay_ms(100);
      RecievedData = GREEN_LED_OFF;
      start_led_actions2();
       __delay_ms(100);
       
       RecievedData = YELLOW_LED_ON;
       start_led_actions2();
       __delay_ms(100);
      RecievedData = YELLOW_LED_OFF;
      start_led_actions2();
       __delay_ms(100);
       
    
       
       
       RecievedData = WHITE_LED_ON;
       start_led_actions2();
       __delay_ms(100);
      RecievedData = WHITE_LED_OFF;
      start_led_actions2();
       __delay_ms(100);
     
   
   
    led_on(WHITE_LED)   ;
    led_on(RED_LED)     ;
    led_on(BLUE_LED)    ;
    led_on(GREEN_LED)   ;
    led_on(YELLOW_LED)  ;
    
    
     __delay_ms(200);
    
   led_off(WHITE_LED)   ;
    led_off(RED_LED)    ;
    led_off(BLUE_LED)   ;
    led_off(GREEN_LED)  ;
    led_off(YELLOW_LED) ;
   
     __delay_ms(100);
}

/****************************************************************************/
/*           T H I S   W I L L    S T A R T    T H E    L E D S            */
/***************************************************************************/
//this will called by the uart isr 
void start_led_actions()
{
    
    switch (RecievedData)
    {
        case BLUE_LED_ON   : led_on(BLUE_LED); LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("BLUE LED ON...");__delay_ms(1000);LCD_Clear();
        break; 
        case RED_LED_ON    : led_on(RED_LED) ; LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("RED LED ON...");__delay_ms(1000);    LCD_Clear();   
        break;
        case GREEN_LED_ON  : led_on(GREEN_LED); LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("GREEN LED ON...");__delay_ms(1000);  LCD_Clear();       
        break;
        case YELLOW_LED_ON : led_on(YELLOW_LED); LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("YELLOW LED ON...");__delay_ms(1000);  LCD_Clear();      
        break;
        case WHITE_LED_ON  : led_on(WHITE_LED);  LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("WHITE LED ON...");__delay_ms(1000);  LCD_Clear();    
        break;
        
        
        case BLUE_LED_OFF : led_off(BLUE_LED) ; LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("BLUE LED OFF...");__delay_ms(1000);LCD_Clear();
        break; 
        case RED_LED_OFF  : led_off(RED_LED) ;  LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("RED LED OFF...");__delay_ms(1000);  LCD_Clear();    
        break;
        case GREEN_LED_OFF : led_off(GREEN_LED) ; LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("GREEN LED OFF...");__delay_ms(1000); LCD_Clear();     
        break;
        case YELLOW_LED_OFF : led_off(YELLOW_LED) ; LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("YELLOW LED OFF...");__delay_ms(1000);  LCD_Clear();    
        break;
        case WHITE_LED_OFF : led_off(WHITE_LED) ;   LCD_Clear(); LCD_Set_Cursor(1,1) ;LCD_Write_String("WHITE LED OFF...");__delay_ms(1000); LCD_Clear();    
        break;
        
        default :                   break;
    }
   
    
    
}
/****************************************************************************/
/*           T H I S   W I L L    S T A R T    T H E    L E D S            */
/***************************************************************************/
//this will called by the test mode function
void start_led_actions2()
{
     switch (RecievedData)
    {
        case BLUE_LED_ON   : led_on(BLUE_LED); 
        break; 
        case RED_LED_ON    : led_on(RED_LED) ; 
        break;
        case GREEN_LED_ON  : led_on(GREEN_LED); 
        break;
        case YELLOW_LED_ON : led_on(YELLOW_LED); 
        break;
        case WHITE_LED_ON  : led_on(WHITE_LED); 
        break;
        
        
        case BLUE_LED_OFF : led_off(BLUE_LED) ; 
        break; 
        case RED_LED_OFF  : led_off(RED_LED) ;  
        break;
        case GREEN_LED_OFF : led_off(GREEN_LED) ;      
        break;
        case YELLOW_LED_OFF : led_off(YELLOW_LED) ; 
        break;
        case WHITE_LED_OFF : led_off(WHITE_LED) ;  
        break;
        
        default :                   break;
    }
   
    
    
}
/****************************************************************************/
/*                      S C R E E N    S A V E R                           */
/***************************************************************************/
void  screen_saver()
{
  LCD_Clear();
  LCD_Set_Cursor(1,1);
  LCD_Write_String(" Ready ");
  
  for(int i=0;i<9;i++)
  {
      LCD_SR();
      __delay_ms(150);
  }
   for(int i=0;i<9;i++)
  {
      LCD_SL();
      __delay_ms(150);
  }
 // __delay_ms(500);
  LCD_Clear();
  LCD_Write_String("                       ");
  LCD_Set_Cursor(2,1);
  LCD_Write_String(" Ready "); 
  for(int i=0;i<9;i++)
  {
      LCD_SR();
      __delay_ms(80);
  }
   for(int i=0;i<9;i++)
  {
      LCD_SL();
      __delay_ms(80);
  }
}
/****************************************************************************/
/*              D I S P L A Y       I N S T R U C T I O N S                */
/***************************************************************************/
void  instruction_screen()
{
  LCD_Clear();
  LCD_Set_Cursor(1,1);
  LCD_Write_String("__INSTRUCTIONS__  ");
  __delay_ms(1000);
  
  LCD_Clear();
  LCD_Set_Cursor(1,1);
  LCD_Write_String(" connect your device using bluetooth ");
   __delay_ms(500);
  for(int i=0;i<20;i++)
  {
      LCD_SL();
      __delay_ms(500);
  }
  
  
  LCD_Clear();
  LCD_Write_String(" to hc05 and enjoy controlling...");
   __delay_ms(800);
   for(int i=0;i<20;i++)
  {
      LCD_SL();
      __delay_ms(500);
  }

}
























/*
 for(int i=0; i<4; i++)
        {
          __delay_ms(1);
          LCD_SR();
        }
       for(int i=0; i<4; i++)
       {
          __delay_ms(1);
          LCD_SL();
        }
 * 
 * 
 * 
 *  // LCD_Write_String("Nader Hany\0");
  //LCD_Set_Cursor(2,1);
 // LCD_Write_String(" WOLF OF DREAMS \0");
 // UART_TX_Init();
 * 
 *  /// LCD_Set_Cursor(2,1);
//  LCD_Write_String(" Hello a7a world\0");
 * 
 * 
 * 
 * if (Is_Data_Recieved() == 1)
  {  
      LCD_Clear();
      char * string ;
      UART_Read_String(string,10);
     // LCD_Write_String(string);
      LCD_Write_String(string);
    //__delay_ms(600);
        //
      
     // Clear_Recieved_Status();
      
       
  }
 * 
 *  toggle(ld);
 * 
 * 
 *   // UART_Write_String("A7A hello world");
        //UART_Write('a');
           
       // __delay_ms(500);
       //  UART_Write_String("FUCK YOU");
        //UART_Write('c');
       
   //LCD_Write_String("text");
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */