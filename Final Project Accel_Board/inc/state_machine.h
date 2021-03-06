/*
 * state_machine.h
 *	
 *	This file declares the state_machine function and defines the resources
 *	need for it to function appropriately.
 *
 *  Created on: May 1, 2016
 *      Author: Shane Smith
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

// Include Headers
#include <string.h>
#include "stm32f4xx.h"
#include "stdlib.h"
#include "json_coms.h"
#include "circ_buff.h"

// Mode Enumeration
typedef enum
{
	STARTUP1,
	STARTUP2,
	WIFI,
	WIFI_RESP,
	MQTT,
	MQTT_RESP,
	MQTT_SUBS,
	MQTT_SUBS_RESP,
	PUBLISH,
	IDLE,
	SEND_CMDS
}modes;

uint8_t state_machine(modes, commBuffer_t*, commBuffer_t*);	// Function to update modes and perform tasks attached to them

uint8_t time_out(uint32_t);	// Timeout function

#endif /* STATE_MACHINE_H_ */
