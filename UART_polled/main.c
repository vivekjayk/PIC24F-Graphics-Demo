/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ256DA210
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#define FCY 4000000UL
#include <libpic30.h>        // __delayXXX() functions macros 
#include "mcc_generated_files/uart1.h"
/*
                         Main application
 */
int main(void)
{
    char MyString[50] = "This is my first UART Demo. Press Y to repeat.\n";
    char* ptr = &MyString;
    char temp=0;
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
          
    //Print the string once first time entering while loop    
    while(*ptr != '\n')
    {
      if(UART1_is_tx_ready())
        {
         UART1_Write(*ptr++);
        }
    }
    
    //Keep reading input from RX
    temp =  UART1_Read();
    
    //if RX is a valid char, echo it back
    if(temp != 0)
    {
        UART1_Write('\n');
        UART1_Write(temp);
        //If rx char is y or Y, reset the ptr variable to beginning of string.
    if(((char)temp == 'y') || ((char)temp == 'Y'))
        {
            ptr = &MyString;
            UART1_Write('\n');
        }
    }
    //delay to avoid framing error.
       __delay_ms(1);   
    }
    
    

    return 1;
}
/**
 End of File
*/

