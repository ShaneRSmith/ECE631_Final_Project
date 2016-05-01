/*
 * circ_buff.h
 *
 *  Created on: May 1, 2016
 *      Author: Shane Smith
 */

#ifndef CIRC_BUFF_H_
#define CIRC_BUFF_H_

#define MAXCOMMBUFFER 2048
typedef struct _commBuffer_t {
	uint32_t head;
	uint32_t tail;
	char buffer[MAXCOMMBUFFER + 1];
	uint32_t size;
	uint8_t str_len;
} commBuffer_t;

//Initializes the struct commBuffer_t to zero
void InitBuffer(commBuffer_t*);

//Test if a complete string is in buffer
uint8_t haveStr(commBuffer_t*);

//Put character in buffer and update head
void putChar(commBuffer_t*, char);

//Get character from buffer and update tail;
char getChar(commBuffer_t*);

//put C string into buffer (used mainly with transmit buffer)
void putTxStr(commBuffer_t*, char*, uint8_t);

//get C string from buffer (used mainly with receive buffer)
void getRxStr(commBuffer_t*, char*);

// Updates current size of buffer
void update_size(commBuffer_t*);

#endif /* CIRC_BUFF_H_ */
