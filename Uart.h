/*
 * Uart.h
 *
 *  Created on: 05 окт. 2014 г.
 *      Author: lamazavr
 */

#ifndef UART_H_
#define UART_H_

#include "DSP2802x_Device.h"

void Uart_init();

void Uart_init_gpio();

void Uart_send(Uint16 a);

void Uart_send_msg(char *msg);



#endif /* UART_H_ */
