/*
 * USART.h
 *
 *  Created on: May 1, 2016
 *      Author: Shane Smith
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"

void InitUSART6(void);
void SendCharArrayUSART6(char arr[], int len);

#endif /* USART_H_ */
