/* ###################################################################
**     Filename    : main.c
**     Project     : RS-422
**     Processor   : MC9S12ZVCA192MKH
**     Version     : Driver 01.14
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2021-07-10, 15:55, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.14
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AD1.h"
#include "AS1.h"
#include "WAIT1.h"
#include "MCUC1.h"
#include "CAN1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


dword messageID = 0x07;
dword messageID1 = 0x08;
dword messageID2 = 0x09;
unsigned error;
unsigned char t_data[21];
unsigned char t1_data[8];
unsigned char t2_data[8];
unsigned char t3_data[8];
const byte analog = 0;
const byte analog1 = 1;
unsigned int data1 = 48;
unsigned int data2= 49;
unsigned int data3= 50;
unsigned int data4 = 51;
unsigned int data5 = 52;
unsigned int current= 519;
unsigned int val = 0;
unsigned int aa = 0;
unsigned int dd = 0;
unsigned int ee = 0;
unsigned int ff = 0;
unsigned int bb = 0;
unsigned int cc = 0;
unsigned char buff[5];
dword id;
byte type,len;
byte Value;
word Sent;
/* User includes (#include below this line is not maintained by Processor Expert) */
/*******Functions*******/
void data_frame_send_RS422();
void analog_measure();
void data_frame_send_CAN();
void CAN1_OnFullRxBuffer(void)
{
	CAN1_ReadFrame(&id,&type,0,&len,buff);
}
void data_frame_send_CAN()
{
	unsigned int data1_binler_yuzler_basamak = 0;
	unsigned int data1_birler_onlar_basamak = 0;
data1_binler_yuzler_basamak = current/10;
data1_birler_onlar_basamak = current - data1_binler_yuzler_basamak*10;
t1_data[0] = data2;
t1_data[1] = data2;
t1_data[2] = data2;
t1_data[3] = data2;
t1_data[4] = data2;
t1_data[5] = data2;
t1_data[6] = data2;
t1_data[7] = data1;
	CAN1_SendFrame(1,messageID,DATA_FRAME,8,t1_data);
	WAIT1_Waitms(100);
t2_data[0] = data2;
t2_data[1] = data2;
t2_data[2] = data2;
t2_data[3] = data2;
t2_data[4] = data2;
t2_data[5] = data2;
t2_data[6] = data2;
t2_data[7] = data2;
	CAN1_SendFrame(1,messageID1,DATA_FRAME,8,t2_data);
	WAIT1_Waitms(100);
t3_data[0] = data2;
t3_data[1] = data2;
t3_data[2] = data2;
t3_data[3] = data2;
t3_data[4] = data2;
t3_data[5] = data2;
t3_data[6] = data1_binler_yuzler_basamak;
t3_data[7] = data1_birler_onlar_basamak;
	CAN1_SendFrame(1,messageID2,DATA_FRAME,8,t3_data);
	WAIT1_Waitms(100);	
}
void data_frame_send_RS422()
{
	unsigned int data1_binler_yuzler_basamak = 0;
	unsigned int data1_birler_onlar_basamak = 0;
data1_binler_yuzler_basamak = current/10;
data1_birler_onlar_basamak = current - data1_binler_yuzler_basamak*10;

t_data[0] = data2;
t_data[1] = data2;
t_data[2] = data2;
t_data[3] = data2;
t_data[4] = data2;
t_data[5] = data2;
t_data[6] = data2;
t_data[7] = data2;
t_data[8] = data2;
t_data[9] = data2;
t_data[10] = data2;
t_data[11] = data2;
t_data[12] = data2;
t_data[13] = data2;
t_data[14] = data2;
t_data[15] = data2;
t_data[16] = data2;
t_data[17] = data2;
t_data[18] = data2;
t_data[19] = data1_binler_yuzler_basamak;
t_data[20] = data1_birler_onlar_basamak;
	AS1_SendBlock((byte*)&t_data,sizeof(t_data),&Sent);
	WAIT1_Waitms(100);
}
void analog_measure()
{
	AD1_MeasureChan(1,analog);
	AD1_GetChanValue8(analog,&Value);
	val=(int)Value;
}
/*******Functions END*******/
void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
   PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  while(1)
  {
	  analog_measure();
	  data_frame_send_RS422();
	  data_frame_send_CAN();

  }

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS12Z series of microcontrollers.
**
** ###################################################################
*/
