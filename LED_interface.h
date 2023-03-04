/*
 *
SW_interface.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "LED_private.h"
#include "LED_config.h"

ES_t LED_enuInit(LED_t *Copy_ledConfig);
ES_t LED_enuTurnOn(LED_t *Copy_ledId);
ES_t LED_enuTurnOff(LED_t *Copy_ledId);

#endif
