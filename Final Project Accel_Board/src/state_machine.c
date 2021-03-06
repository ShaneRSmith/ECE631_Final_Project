/*
 * state_machine.c
 *
 *	This file defines the state_machine function which updates the modes and
 *	performs the tasks associated with them.
 *
 *  Created on: May 1, 2016
 *      Author: Shane Smith
 */

// Include Headers
#include "state_machine.h"

 uint8_t state_machine(modes mode, commBuffer_t* receive_buff, commBuffer_t* send_buff)
 {	// The main state machine function that performs the tasks needed for the accel_board
	// to accomplish what this project requires. 

	static uint8_t go_for_launch = 0;	// Flag to show if Multi_Board is ready for commands.
	char* msg;		// Message to Publish
	char* topic;	// Topic to Publish

	switch(mode)	// TODO: Switch all analysis of messages to allow them out of order?
	{
		case STARTUP1:
		{	// We want to stay in this mode unless we succesfully startup, then we can start
			// setting up the other stuff.
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len+sizeof(char));
				getRxStr(&receive_buff,temp);
					if (startup_success_(temp)==1)
					{	// We passed the startup test #1
						mode=STARTUP2;
					}
					free(temp);
			}
			break;
		}
		
		case STARTUP2:
		{	// Check for second startup message (huzzah is setup to send 2 startup messages)
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len+sizeof(char));
				getRxStr(&receive_buff,temp);
				if (startup_success_(temp)==1)
				{	// We passed the startup test #2
					mode=WIFI;
				}
				free(temp);
			}
			break;
		}
		
		case WIFI:
		{	// Send Setup Message for WIFI
			char* temp = (char*)malloc(sizeof(char)*98); // TODO: Size this more dynamically
			temp = setup_wifi_();
			putTxStr(&send_buff, temp, strlen(temp));
			free(temp);
			mode=WIFI_RESP;
			break;
		}
		
		case WIFI_RESP:
		{	// Check for message indicating Wifi setup success
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len);
				getRxStr(&receive_buff,temp);
				// Let's check it to make sure we haven't reset the Huzzah
				if (startup_success_(temp)==1)
				{	// If we have we need to start our setup process again.
					mode=STARTUP2;
				}
				else
				{
					if (wifi_success_(temp)==1)
					{	// We have successfully setup wifi, now setup mqtt.
						mode=MQTT;
					}
				}
				free(temp);
			}
			else
			{
				if (time_out(5000)==1)	// Wait for 5 seconds, then try resending wifi_setup
					mode = WIFI;
			}
			break;
		}
		
		case MQTT:
		{	// Send MQTT setup message
			char* temp = (char*)malloc(sizeof(char)*64); // TODO: Size this more dynamically
			temp=setup_MQTT_();
			putTxStr(&send_buff, temp, strlen(temp));
			free(temp);
			mode = MQTT_RESP;
			break;
		}
		
		case MQTT_RESP:
		{	// Check for message indicating MQTT setup success
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len);
				getRxStr(&receive_buff,temp);
				// Let's check it to make sure we haven't reset the Huzzah
				if (startup_success_(temp)==1)
				{	// If we have we need to start our setup process again.
					mode=STARTUP2;
				}
				else
				{
					if (MQTT_success_(temp)==1)
					{	// We have successfully setup mqtt, now setup mqtt-subs
						mode=MQTT_SUBS;
					}
				}
				free(temp);
			}
			else
			{
				if (time_out(5000)==1)	// Wait for 5 seconds, then try resending MQTT_setup
					mode = MQTT;
			}
			break;
		}
		
		case MQTT_SUBS:
		{	// Send message to setup MQTT subscriptions
			char* temp = (char*)malloc(sizeof(char)*64); // TODO: Size this more dynamically
			temp=setup_MQTT_Subs_();
			putTxStr(&send_buff, temp, strlen(temp));
			free(temp);
			mode = MQTT_SUBS_RESP;
			break;
		}
		
		case MQTT_SUBS_RESP:
		{
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len);
				getRxStr(&receive_buff,temp);
				// Let's check it to make sure we haven't reset the Huzzah
				if (startup_success_(temp)==1)
				{	// If we have we need to start our setup process again.
					mode=STARTUP2;
				}
				else
				{
					if (SUBS_success_(temp)==1)
					{	// We have successfully setup mqtt-subs, now go to idle.
						mode=IDLE;
					}
				}
				free(temp);
			}
			else
			{
				if (time_out(5000)==1)	// Wait for 5 seconds, then try resending MQTT subscriptions setup
					mode = MQTT_SUBS;
			}
			break;
		}
		
		case PUBLISH:
		{	// This case is used to publish messages defined in the IDLE case
			char* temp = (char*)malloc(sizeof(char)*64);	// TODO: Allocate this size more dynamically.
			temp=publish(msg,topic);	// This takes the message and wraps it up in a JSON object
			free(temp);
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len);
				getRxStr(&receive_buff,temp);
				// Let's check it to make sure we haven't reset the Huzzah
				if (startup_success_(temp)==1)
				{	// If we have we need to start our setup process again.
					mode=STARTUP2;
				}
				else
				{
					if (publish_success_(temp)==1)
					{	// We successfully published our message, go back to idle.
						mode=IDLE;
					}
				}
				free(temp);
			}
			break;
		}
		
		case IDLE:	// TODO: Finish this section
		{	// Sit here waiting for the Multi_Board to be ready to receive commands.
			if (haveStr(&receive_buff)==1)
			{
				char* temp = (char*)malloc(sizeof(char)*receive_buff->str_len);
				getRxStr(&receive_buff,temp);
				// Let's check it to make sure we haven't reset the Huzzah
				if (startup_success_(temp)==1)
				{	// If we have we need to start our setup process again.
					mode=STARTUP2;
				}
				else
				{
					// check for board saying it is ready
				}
			}
			break;
		}
		
		case SEND_CMDS:	// TODO: Finish this section
		{
			break;
		}
	}
	 return mode;
 }
 
 uint8_t time_out(uint32_t delay_time)
{	// This function functions as a time delay. It assumes it is being called at 1000 Hz.
	// The delay_time value is in ms, and is the size of the delay.
	static uint32_t count = 0;
	if (count >= delay_time)
	{
		count = 0;
		return (1);
	}
	else
	{
		count++;
		return (0);
	}
}
