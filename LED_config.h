/*
  * SW_config.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
#include "STD_TYPE.h"
#define LED_NUM  3
typedef struct {
	u8 LED_PortID;
	u8 LED_PinID;
	u8 LED_Connection;
	u8 LED_InitState;
}LED_t;


#endif

