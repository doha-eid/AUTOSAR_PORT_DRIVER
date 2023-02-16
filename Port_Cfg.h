/*************************************************************************************************************
 * Module : Port
 *
 * File Name:Port_Cfg.h
 *
 *  Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - PORT Driver
 *    
 *      Author: Doha Eid
 *************************************************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)
/**********************************************************************************
 *                    Module Definitions                                          *
 **********************************************************************************/
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT_API               (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                	(STD_OFF)

/* Pre-compile option for Pin Direction Changeable API */
#define PORT_PIN_DIRECTION_CHANGEABLE_API       (STD_ON)

/* Pre-compile option for Pin Mode Changeable API */
#define PORT_PIN_MODE_CHANGEABLE_API            (STD_ON)

/*Number of configurable ports*/
#define PORT_NUMBERS 							(6U)

/* Number of the configured Pins  */
#define PORT_CONFIGURED_PINS              		(43U)
 /*Tiva-C Ports*/
#define  PORT_A_ID 								(0U)
#define  PORT_B_ID 								(1U)
#define  PORT_C_ID 								(2U)
#define  PORT_D_ID 								(3U)
#define  PORT_E_ID 								(4U)
#define  PORT_F_ID 								(5U)

/*Tiva-Pins*/
#define PIN_0_ID 								(0U)
#define PIN_1_ID 								(1U)
#define PIN_2_ID 								(2U)
#define PIN_3_ID 								(3U)
#define PIN_4_ID 								(4U)
#define PIN_5_ID 								(5U)
#define PIN_6_ID 								(6U)
#define PIN_7_ID 								(7U)

 /*Pin Modes */
/**************************GROUP 1***********************************/
#define GROUP_1_ID 								(1U)
#define U0Rx_MODE                               (Port_PinModeType)1
#define U0Tx_MODE                              	(Port_PinModeType)1
#define U1Rx_MODE                              	(Port_PinModeType)1
#define U1Tx_MODE                               (Port_PinModeType)1
#define U4Rx_MODE                              	(Port_PinModeType)1
#define U4Tx_MODE                              	(Port_PinModeType)1
#define U3Rx_MODE                              	(Port_PinModeType)1
#define U3Tx_MODE                              	(Port_PinModeType)1
#define SSI3Clk_MODE                           	(Port_PinModeType)1
#define SSI3Fss_MODE                           	(Port_PinModeType)1
#define SSI3Rx_MODE                            	(Port_PinModeType)1
#define SSI3Tx_MODE                            	(Port_PinModeType)1
#define U6Rx_MODE                              	(Port_PinModeType)1
#define U6Tx_MODE                              	(Port_PinModeType)1
#define U2Rx_MODE                              	(Port_PinModeType)1
#define U2Tx_MODE                              	(Port_PinModeType)1
#define U7Rx_MODE                              	(Port_PinModeType)1
#define U7Tx_MODE                              	(Port_PinModeType)1
#define U5Rx_MODE                              	(Port_PinModeType)1
#define U5Tx_MODE                              	(Port_PinModeType)1
#define U1RTS_MODE                             	(Port_PinModeType)1
#define U1CTS_MODE                             	(Port_PinModeType)1

/**************************JTAG/SWD/SWO Pins****************************/
//#define TCK_MODE                              (Port_PinModeType)1
//#define SWLCK_MODE                            (Port_PinModeType)1
//#define TMS_MODE                              (Port_PinModeType)1
//#define SWDIO_MODE                            (Port_PinModeType)1
//#define TDI_MODE                              (Port_PinModeType)1
//#define TDO_MODE                              (Port_PinModeType)1
//#define SWO_MODE                              (Port_PinModeType)1

/************************** GROUP 2***********************************/
#define GROUP_2_ID                              (2U)
#define SSI0Clk_MODE                            (Port_PinModeType)2
#define SSI0Fss_MODE                            (Port_PinModeType)2
#define SSI0Rx_MODE                             (Port_PinModeType)2
#define SSI0Tx_MODE                             (Port_PinModeType)2
#define SSI2Clk_MODE                            (Port_PinModeType)2
#define SSI2Fss_MODE                            (Port_PinModeType)2
#define SSI2Rx_MODE                             (Port_PinModeType)2
#define SSI2Tx_MODE                             (Port_PinModeType)2
#define U1Rx_PC4_MODE                           (Port_PinModeType)2
#define U1Tx_PC5_MODE                           (Port_PinModeType)2
#define SSI1Clk_MODE                            (Port_PinModeType)2
#define SSI1Fss_MODE                            (Port_PinModeType)2
#define SSI1Rx_MODE                             (Port_PinModeType)2
#define SSI1Tx_MODE                             (Port_PinModeType)2
#define SSI1Rx_MODE                             (Port_PinModeType)2
#define SSI1Tx_MODE                             (Port_PinModeType)2
#define SSI1Clk_MODE                            (Port_PinModeType)2
#define SSI1Fss_MODE                            (Port_PinModeType)2
/************************** GROUP 3***********************************/
#define GROUP_3_ID                              (3U)
#define I2C1SCL_MODE                            (Port_PinModeType)3
#define I2C1SDA_MODE                            (Port_PinModeType)3
#define I2C0SCL_MODE                            (Port_PinModeType)3
#define I2C0SDA_MODE                            (Port_PinModeType)3
#define I2C3SCL_MODE                            (Port_PinModeType)3
#define I2C3SDA_MODE                            (Port_PinModeType)3
#define I2C2SCL_MODE                            (Port_PinModeType)3
#define I2C2SDA_MODE                            (Port_PinModeType)3
#define CAN0Rx_MODE                             (Port_PinModeType)3
#define CAN0Tx_MODE                             (Port_PinModeType)3

/************************** GROUP 4***********************************/
#define GROUP_4_ID                              (4U)
#define M0PWM3_MODE                             (Port_PinModeType)4
#define M0PWM0_MODE                             (Port_PinModeType)4
#define M0PWM1_MODE                             (Port_PinModeType)4
#define M0PWM6_MODE                             (Port_PinModeType)4
#define M0PWM7_MODE                             (Port_PinModeType)4
#define M0PWM6_MODE                             (Port_PinModeType)4
#define M0PWM7_MODE                             (Port_PinModeType)4
#define M0FAULT0_MODE                           (Port_PinModeType)4
#define M0FAULT0_MODE                           (Port_PinModeType)4
#define M0PWM4_MODE                             (Port_PinModeType)4
#define M0PWM5_MODE                             (Port_PinModeType)4
#define M0FAULT0_MODE                           (Port_PinModeType)4

/************************** GROUP 5***********************************/
#define GROUP_5_ID                              (5U)
#define M1PWM2_MODE                             (Port_PinModeType)5
#define M1PWM3_MODE                             (Port_PinModeType)5
#define M1PWM0_MODE                             (Port_PinModeType)5
#define M1PWM1_MODE                             (Port_PinModeType)5
#define M1PWM2_MODE                             (Port_PinModeType)5
#define M1PWM3_MODE                             (Port_PinModeType)5
#define M1PWM4_MODE                             (Port_PinModeType)5
#define M1PWM5_MODE                             (Port_PinModeType)5
#define M1PWM6_MODE                             (Port_PinModeType)5
#define M1PWM7_MODE                             (Port_PinModeType)5
#define M1FAULT0_MODE                           (Port_PinModeType)5

/************************** GROUP 6***********************************/
#define GROUP_6_ID                              (6U)
#define IDX1_MODE                               (Port_PinModeType)6
#define PhA1_MODE                               (Port_PinModeType)6
#define PhB1_MODE                               (Port_PinModeType)6
#define IDX0_MODE                               (Port_PinModeType)6
#define PhA0_MODE                               (Port_PinModeType)6
#define PhB0_MODE                               (Port_PinModeType)6

/************************** GROUP 7***********************************/
#define GROUP_7_ID                              (7U)
#define T2CCP1_MODE                             (Port_PinModeType)7
#define T3CCP0_MODE                             (Port_PinModeType)7
#define T3CCP1_MODE                             (Port_PinModeType)7
#define T1CCP0_MODE                             (Port_PinModeType)7
#define T1CCP1_MODE                             (Port_PinModeType)7
#define T0CCP0_MODE                             (Port_PinModeType)7
#define T0CCP1_MODE                             (Port_PinModeType)7
#define WT0CCP0_MODE                            (Port_PinModeType)7
#define WT0CCP1_MODE                            (Port_PinModeType)7
#define WT1CCP0_MODE                            (Port_PinModeType)7
#define WT1CCP1_MODE                            (Port_PinModeType)7
#define WT2CCP0_MODE                            (Port_PinModeType)7
#define WT2CCP1_MODE                            (Port_PinModeType)7
#define WT3CCP0_MODE                            (Port_PinModeType)7
#define WT3CCP1_MODE                            (Port_PinModeType)7
#define WT4CCP0_MODE                            (Port_PinModeType)7
#define WT4CCP1_MODE                            (Port_PinModeType)7
#define WT5CCP0_MODE                            (Port_PinModeType)7
#define WT5CCP1_MODE                            (Port_PinModeType)7
#define T0CCP0_MODE                             (Port_PinModeType)7
#define T0CCP1_MODE                             (Port_PinModeType)7
#define T1CCP0_MODE                             (Port_PinModeType)7
#define T1CCP1_MODE                             (Port_PinModeType)7
#define T2CCP0_MODE                             (Port_PinModeType)7

/************************JTAG/SWD/SWO Pins***************************/
//#define T4CCP0_MODE                           (Port_PinModeType)7
//#define T4CCP1_MODE                           (Port_PinModeType)7
//#define T5CCP0_MODE                           (Port_PinModeType)7
//#define T5CCP1_MODE                           (Port_PinModeType)7

/************************** GROUP 8***********************************/
#define GROUP_8_ID                              (8U)
#define CAN1Rx_MODE                             (Port_PinModeType)8
#define CAN1Tx_MODE                             (Port_PinModeType)8
#define CAN0Rx_PB4_MODE                         (Port_PinModeType)8
#define CAN0Tx_PB5_MODE                         (Port_PinModeType)8
#define U1RTS_PC4_MODE                          (Port_PinModeType)8
#define U1CTS_PC5_MODE                          (Port_PinModeType)8
#define USB0EPEN_MODE                           (Port_PinModeType)8
#define USB0PFLT_MODE                           (Port_PinModeType)8
#define NMI_MODE                                (Port_PinModeType)8
#define CAN0Rx_PE4_MODE                         (Port_PinModeType)8
#define CAN0Tx_PE5_MODE                         (Port_PinModeType)8
#define USB0EPEN_MODE                           (Port_PinModeType)8

/************************** GROUP 9***********************************/
#define GROUP_9_ID                              (9U)
#define C0o_MODE                                (Port_PinModeType)9
#define C1o_MODE                                (Port_PinModeType)9

/************************** GROUP 10***********************************/
#define GROUP_10_ID                             (10U)
#define TRD1_MODE                               (Port_PinModeType)10
#define AIN10_MODE                              (Port_PinModeType)10
#define AIN11_MODE                              (Port_PinModeType)10
#define AIN7_MODE                               (Port_PinModeType)10
#define AIN6_MODE                               (Port_PinModeType)10
#define AIN5_MODE                               (Port_PinModeType)10
#define AIN4_MODE                               (Port_PinModeType)10
#define AIN3_MODE                               (Port_PinModeType)10
#define AIN2_MODE                               (Port_PinModeType)10
#define AIN1_MODE                               (Port_PinModeType)10
#define AIN0_MODE                               (Port_PinModeType)10
#define AIN9_MODE                               (Port_PinModeType)10
#define AIN8_MODE                               (Port_PinModeType)10

/************************** GROUP 11***********************************/
#define GROUP_11_ID                             (11U)
#define C1_NEGATIVE_MODE                        (Port_PinModeType)11
#define C1_POSITIVE_MODE                        (Port_PinModeType)11
#define C0_POSITIVE_MODE                        (Port_PinModeType)11
#define C0_NEGATIVE_MODE                        (Port_PinModeType)11
/************************** GROUP 12***********************************/
#define GROUP_12_ID                             (12U)
#define USB0DM_MODE                             (Port_PinModeType)12
#define USB0DP_MODE                             (Port_PinModeType)12
#define USB0ID_MODE                             (Port_PinModeType)12
#define USB0VBUS_MODE                           (Port_PinModeType)12

/************************** GROUP 14***********************************/
#define GROUP_14_ID                             (14U)
#define TRD1_PF1_MODE                           (Port_PinModeType)14
#define TRD0_MODE                               (Port_PinModeType)14
#define TRCLK_MODE                              (Port_PinModeType)14


/****************************SPECIAL GROUPS****************************/
#define GPIO_MODE 		 		(Port_PinModeType)0
#define ADC_MODE 		 		(Port_PinModeType)10
#define ANALOG_COMPARATOR_MODE 		 	(Port_PinModeType)11
#define ANALOG_MODE 		 		(Port_PinModeType)12


#endif /* PORT_CFG_H_ */
