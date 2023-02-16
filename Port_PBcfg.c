/*******************************************************************************************************
 * Module : Port
 *
 * File Name :Port_PBcfg.c
 *
 *  Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *    
 * Author: Doha Eid
 *********************************************************************************************************/

#include"Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* Post Build  structure used with Port_Init API */
/*config 6 ports 0-5
 * config there 8 pins 0-7
 */
/*
 * Struct contains
 * 1- Port number
 * 2- Pin number
 * 3- Direction
 * 4-  Mode (GPIO -UART.... etc)
 * 5- internal resistor in case Pull-up resistor
 * 6- value in case output pin
 * 7- Direction changeable or not at run time
 * 8- Mode changeable or not at run time
 */
/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration ={
	 /*******************************************************PORT A****************************************************************************/
     PORT_A_ID,     PIN_0_ID,     INPUT_PIN,     U0Rx_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_1_ID,     OUTPUT_PIN,    U0Tx_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_2_ID,     INPUT_PIN,     ADC_MODE,      PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_A_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT B****************************************************************************/
     PORT_B_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_4_ID,     INPUT_PIN,     AIN10_MODE,    OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_B_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT C****************************************************************************/
     PORT_C_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_C_ID,     PIN_7_ID,     INPUT_PIN,     WT1CCP1_MODE,  PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT D****************************************************************************/
     PORT_D_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_D_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT E****************************************************************************/
     PORT_E_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_E_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_E_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_E_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_E_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_E_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT F****************************************************************************/
     PORT_F_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_F_ID,     PIN_1_ID,     OUTPUT_PIN,    GPIO_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_F_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_F_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORT_F_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE  };



