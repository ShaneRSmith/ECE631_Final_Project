/*
 * state_machine.c *
 *  Created on: April 30, 2016
 *	This file was created to be the state machine for the Accel_Board.
 *	It will take actions depending on which state it is in.
 *      Author: Shane Smith
 */
 
 // Include Headers
 #include <string.h>
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
	IDLE
}modes;

 uint8_t state_machine(void)
 {  
	switch(modes)
	{
		case STARTUP1:
		{
			break;
		}
		case STARTUP2:
		{
			break;
		}
		case WIFI:
		{
			break;
		}
		case WIFI_RESP:
		{
			break;
		}
		case MQTT:
		{
			break;
		}
		case MQTT_RESP:
		{
			break;
		}
		case MQTT_SUBS:
		{
			break;
		}
		case MQTT_SUBS_RESP:
		{
			break;
		}
		case PUBLISH:
		{
			break;
		}
		case IDLE:
		{
			break;
		}
	}
	 return 0;
 }