 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Doha Eid
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and PORT Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/*Hold the pointer of port_configtype*/
STATIC const Port_ConfigPin * Port_Pins = NULL_PTR;

/*Check the status of the port if initialized or not */
STATIC uint8 PORT_Status = PORT_NOT_INITIALIZED;

/***********************************************************************************
 *                         Function Deceleration                                  *
 **********************************************************************************/
/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr){

#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		PORT_Status  = PORT_INITIALIZED;
                
		/*Address of the first pin structure */
		Port_Pins = ConfigPtr->Port_Pins;
                
		/* for loop for looping on all pins */
		for (Port_PinType Pin=0;Pin<PORT_CONFIGURED_PINS;Pin++){
                  
			/* point to the required Port Registers base address */
			 volatile uint32 * PortGpio_Ptr = NULL_PTR;
                         
                         /*Variable as a clock cycles consumer until the Port clock gets intialized*/
			 volatile uint32 delay = 0;
    /************************************************************************PORT NUMBER****************************************************************************************/
			 switch(Port_Pins[Pin].port_num)
			     {
			         case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
			 		 break;
			         case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
			 		 break;
			         case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
			 		 break;
			         case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
			 		 break;
			         case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
			 		 break;
			         case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
			 		 break;
			     }
                         
			 /*Enable Clock for port */
			 SYSCTL_REGCGC2_REG |=(1<<Port_Pins[Pin].pin_num);
			 delay=SYSCTL_REGCGC2_REG;

			 /*Locking pins so we need to unlock then commit */
			 if( ((Port_Pins[Pin].port_num == PORT_D_ID) && (Port_Pins[Pin].pin_num == PIN_7_ID)) || ((Port_Pins[Pin].port_num == PORT_F_ID) && (Port_Pins[Pin].pin_num == PIN_0_ID)) ) /* PD7 or PF0 */
			     {

				 	 /* Unlock the GPIOCR register */
			         *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = UNLOCKING_VALUE;

			         /* Set the corresponding bit in GPIOCR register (Commit register) to allow changes on this pin */
			         SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[Pin].pin_num);

			     }

			     else if( (Port_Pins[Pin].port_num == PORT_C_ID) && (Port_Pins[Pin].pin_num <= PIN_3_ID) ) /* PC0 to PC3 */

			     {
			         /* Do Nothing ...  this is the JTAG pins */
			     }
			     else
			     {
			         /* Do Nothing ... No need to unlock the commit register for this pin */
			     }

   /*****************************************************************PIN DIRECTION***********************************************************************************************/
                         
			     /*Check pin direction is output or not  */
			     if(Port_Pins[Pin].port_pinDirection == OUTPUT_PIN)
			     {
			    	 /* Set the corresponding bit in Direction Register (GPIODIR) register to configure it as output pin */
			    	 SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);

			    	 /*if the pin direction is output check the initial value of the pin logic high or logic low */
			         if(Port_Pins[Pin].Port_initialValue == STD_HIGH)
			         {
			        	 /* Set the corresponding bit in Data Register (GPIODATA) register to provide initial value 1 */
			             SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
			         else
			         {
			        	 /* Clear the corresponding bit in Data Register (GPIODATA) register to provide initial value 0 */
			             CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
			     }

			     /*Check pin direction is input or not  */
			     else if(Port_Pins[Pin].port_pinDirection == INPUT_PIN)
			     {
			    	 /* Clear the corresponding bit in Direction Register (GPIODIR)  to configure it as input pin */
			         CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);

			         /*if the pin direction is input check the internal resistor is PULL-UP or PULL-DOWN */
			         if(Port_Pins[Pin].port_pinResistor == PULL_UP)
			         {
			        	 /* Set the corresponding bit in PULL-UP Register (GPIOPUR)  to enable the internal pull up pin */
			             SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
			         else if(Port_Pins[Pin].port_pinResistor == PULL_DOWN)
			         {
			        	 /* Set the corresponding bit in PULL-DOWN Register (GPIOPDR)  to enable the internal pull down pin */
			             SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
			         else
			         {
			        	 /* Clear the corresponding bit in PULL-UP Register (GPIOPUR)  to disable the internal pull up pin */
			             CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[Pin].pin_num);
                                     
			             /* Clear the corresponding bit in PULL-DOWN Register (GPIOPDR) to disable the internal pull down pin */
			             CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
			     }
			     else
			     {
			         /* Do Nothing */
			     }

  /**************************************************************************PIN MODE********************************************************************************************/
			     if (Port_Pins[Pin].Port_PinMode== GPIO_MODE)
			         {
			    	 /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) ,Port_Pins[Pin].pin_num);
                                   
			           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
                                   
			           /* Clear the PMCx bits for this pin */
			           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
                                   
			           /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
                                  /*Enable analog for analog mode*/
			         else if ((Port_Pins[Pin].Port_PinMode == ADC_MODE) || (Port_Pins[Pin].Port_PinMode == ANALOG_COMPARATOR_MODE)||(Port_Pins[Pin].Port_PinMode == ANALOG_MODE))
			         {
			        	 /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
			           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
                                   
			           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,Port_Pins[Pin].pin_num);
                                   
			           /* Clear the PMCx bits for this pin */
			           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
                                   
			           /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_Pins[Pin].pin_num);
			         }
                                  /*Enable digital for all digital modes */
			         else
			         {
			        	 /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
                                   
			           /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
                                   
			           /* Set the PMCx bits for this pin */
			           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)Port_Pins[Pin].Port_PinMode << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
			           
                                   /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
			         }
		}

	}


}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): - Pin - Port Pin ID number
* 				   - Direction -Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
#if (PORT_PIN_DIRECTION_CHANGEABLE_API == STD_ON)

void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Check if the Driver is initialized before using this function */
		if(Port_Status == PORT_NOT_INITIALIZED)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_UNINIT);
		}
		else
		{	
                  /* Do Nothing */	
                }

		/* check if incorrect Port Pin ID passed */
		if(Pin >= PORT_CONFIGURED_PINS)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN);
		}
		else
		{	/* Do Nothing */	}

		/* check if Port Pin not configured as changeable */
		if(Port_Port_Pins[Pin].Port_PinChangeableDirection == STD_OFF)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
		}
		else
		{	
                  /* Do Nothing */	
                }
	#endif


	/* point to the required Port Registers base address */
    volatile uint32 * PortGpio_Ptr = NULL_PTR;
    
    switch(Port_Pins[Pin].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    if(!((Port_Pins[Pin].port_num == PORT_C_ID) && (Pin <= PIN_3_ID)) ) /* PC0 to PC3 */
    {

      if(Direction == OUTPUT_PIN)
      {
    	 /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
      }
      else if(Direction == INPUT_PIN)
      {
    	/* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
        
      }
      else 
      {
         /* Do Nothing */
      }
    }
    else
    {
        /* Do Nothing */
    }
    
}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in):None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void){
  
  /* point to the required Port Registers base address */
  volatile uint32 *PortGpio_Ptr = NULL_PTR;
  
  /*Variable used as an Index for the Port_Pin structures*/
  volatile uint8 Pin=0;
  
    /*Det Error */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* check if the input configuration pointer is not a NULL_PTR */
  if (Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIR_SID,
                    PORT_E_UNINIT);
  }
  else 
  {
     /* Do Nothing */
  }
  
#endif

  for(Port_PinType index = 0; index < PORT_CONFIGURED_PINS; index++)
  {

    switch(Port_Pins[Pin].port_num )
    {
    	case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
    	break;
    	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
    	break;
    	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
    	break;
    	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
    	break;
    	case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
    	break;
    	case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
    	break;
    }



    if( !((Port_Pins[Pin].port_num == PORT_C_ID) && (Port_Pins[Pin].pin_num <= PIN_3_ID)) ) /* PC0 to PC3 */
    {
       if (Port_Pins[Pin].Port_PinChangeableDirection == NON_CHANGEABLE_DIRECTION)
       {
        if(Port_Pins[Pin].port_pinDirection== OUTPUT_PIN)
        {
          /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
         }
        else if(Port_Pins[Pin].port_pinDirection== INPUT_PIN)
        {
          /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
        }
      else
      {
        /* Do Nothing */
      }
    }
    }
    else
    {
      /* Do Nothing ... JTAG Pins */
    }
   
  }
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description:Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): - Pin-Port Pin ID number
*				   - Mode-New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:Sets the port pin mode.
************************************************************************************/
#if (PORT_PIN_MODE_CHANGEABLE_API == STD_ON)

void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Check if the Driver is initialized before using this function */
		if(Port_Status == PORT_NOT_INITIALIZED)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		}
		else
		{	
                    /* Do Nothing */	
                }

		/* check if incorrect Port Pin ID passed */
		if(Pin >= PORT_CONFIGURED_PINS)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		}
		else
		{	
                    /* Do Nothing */
                }
                
		/* check if the API called when the mode is unchangeable */
		if(Port_Pins[Pin].Port_PinChangeableMode == NON_CHANGEABLE_MODE)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		}
		else
		{	
                    /* Do Nothing */	
                }
                if (!(Mode<=GROUP_12_ID || Mode==GROUP_14_ID))
                {
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
                }
                else 
                {
                  /* Do Nothing */
                }
	#endif
                /* point to the required Port Registers base address */
		 volatile uint32 * PortGpio_Ptr = NULL_PTR; 
                
		 switch(Port_Pins[Pin].port_num)
		 	{
		 		case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 		 break;
		 		case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 		 break;
		 		case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 		 break;
		 		case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 		 break;
		 		case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 		 break;
		 		case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 		 break;
		 	}
                            /*Condition for JTAG pins to protection from changeing their mode */
                  if( !((Port_Pins[Pin].port_num == PORT_C_ID) && (Port_Pins[Pin].pin_num <= PIN_3_ID)) ) /* PC0 to PC3 */
			   {
                             
		       if (Mode== GPIO_MODE)
			    {
                                   
                      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) ,Port_Pins[Pin].pin_num);
			 
                        /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
		      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
			  
                      /* Clear the PMCx bits for this pin */
		       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
		     
                       /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
		      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
                      
			   }
                       
		    else if ((Mode == ADC_MODE) || (Mode==ANALOG_COMPARATOR_MODE) || (Mode==ANALOG_MODE))
                      {
                        
		     /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
		   SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                   /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,Port_Pins[Pin].pin_num);
		
                  /* Clear the PMCx bits for this pin */
                   *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE)); 
		
                  /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_Pins[Pin].pin_num);
                       }
                       
		  else
		       {
                         
		 /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
		  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                  /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
			
                    /* Set the PMCx bits for this pin */
		    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)Port_Pins[Pin].Port_PinMode << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
			
                     /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
		    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                       }

                      }
                 else
              {
	         /* Do Nothing ... No need to unlock the commit register for this pin */
               }
		
}
#endif
