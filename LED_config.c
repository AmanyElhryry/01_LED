/*
 * SW_config.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"
LED_t LED_Config[LED_NUM]={
		{DIO_PORTB,DIO_PIN4,LED_SOURCE,LED_On},
		{DIO_PORTB,DIO_PIN1,LED_SOURCE,LED_On},
		{DIO_PORTB,DIO_PIN2,LED_SINK,LED_Off}
};
