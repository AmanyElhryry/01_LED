/*
 * SW_program.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */



#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"
#include "STD_TYPE.h"
#include "error_status.h"

ES_t LED_enuInit(LED_t *Copy_ledConfig){
	ES_t Local_enuErorrState=ES_NOK;
	if(Copy_ledConfig!=NULL){
	u8 Local_itrator =0;
for(Local_itrator=0 ; Local_itrator < LED_NUM ; Local_itrator++){
	Local_enuErorrState= DIO_enuSetPinDirection(Copy_ledConfig[Local_itrator].LED_PortID ,Copy_ledConfig[Local_itrator].LED_PinID, OUTPUT);
	if(Copy_ledConfig[Local_itrator].LED_Connection==LED_SINK){
		if(Copy_ledConfig[Local_itrator].LED_InitState==LED_On){
			Local_enuErorrState=DIO_enuSetPinValue(Copy_ledConfig[Local_itrator].LED_PortID ,Copy_ledConfig[Local_itrator].LED_PinID,LOW);
		}
		else if(Copy_ledConfig[Local_itrator].LED_InitState==LED_Off){
			DIO_enuSetPinValue(Copy_ledConfig[Local_itrator].LED_PortID ,Copy_ledConfig[Local_itrator].LED_PinID,HIGH);
				}
		else
			{
			return ES_OUTOFRANGE;
			}
	}

	else if(Copy_ledConfig[Local_itrator].LED_Connection==LED_SOURCE){
			if(Copy_ledConfig[Local_itrator].LED_InitState==LED_On){
				Local_enuErorrState=DIO_enuSetPinValue(Copy_ledConfig[Local_itrator].LED_PortID ,Copy_ledConfig[Local_itrator].LED_PinID,HIGH);
			}
			else if(Copy_ledConfig[Local_itrator].LED_InitState==LED_Off){
				Local_enuErorrState=DIO_enuSetPinValue(Copy_ledConfig[Local_itrator].LED_PortID ,Copy_ledConfig[Local_itrator].LED_PinID,LOW);
					}
			else
				{
				return ES_OUTOFRANGE;
				}
		}

	else
					{
					return ES_OUTOFRANGE;
					}

    }
	}
	else {
		Local_enuErorrState=ES_NULL_POINTER;
	}
	return Local_enuErorrState;
}
ES_t LED_enuTurnOn(LED_t *Copy_ledId){
	ES_t Local_enuErorrState=ES_NOK;
			if(Copy_ledId!=NULL  ){
	if(Copy_ledId->LED_Connection==LED_SINK){
		Local_enuErorrState=DIO_enuSetPinValue(Copy_ledId->LED_PortID,Copy_ledId->LED_PinID,LOW);
	}
	else if(Copy_ledId->LED_Connection==LED_SOURCE)
	{
		Local_enuErorrState=DIO_enuSetPinValue(Copy_ledId->LED_PortID,Copy_ledId->LED_PinID,HIGH);
	}
	else
	{
		Local_enuErorrState=ES_OUTOFRANGE;
	}
		    }

		 	else {
				Local_enuErorrState=ES_NULL_POINTER;
			}
			return Local_enuErorrState;
}

ES_t LED_enuTurnOff(LED_t *Copy_ledId){
	ES_t Local_enuErorrState=ES_NOK;
		if(Copy_ledId!=NULL  ){
			if(Copy_ledId->LED_Connection==LED_SINK){
					Local_enuErorrState=DIO_enuSetPinValue(Copy_ledId->LED_PortID,Copy_ledId->LED_PinID,HIGH);
				}
				else if(Copy_ledId->LED_Connection==LED_SOURCE)
				{
					Local_enuErorrState=DIO_enuSetPinValue(Copy_ledId->LED_PortID,Copy_ledId->LED_PinID,LOW);
				}
else {
	Local_enuErorrState=ES_OUTOFRANGE;
}
	    }

	 	else {
			Local_enuErorrState=ES_NULL_POINTER;
		}
		return Local_enuErorrState;
}
