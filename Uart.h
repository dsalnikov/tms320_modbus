/*
 * Uart.h
 *
 *  Created on: 05 окт. 2014 г.
 *      Author: lamazavr
 */

#ifndef UART_H_
#define UART_H_

#include "DSP2802x_Device.h"

extern Uint16 UartBuffer[];
extern Uint16 UartRxLen;

/**
 * Инициализация передатчика
 */
void Uart_init();

/**
 * Инициализация ножек для Uart
 */
void Uart_init_gpio();

/**
 * Посылка байта
 * @param a - Отсылаемый байт
 */
void Uart_send(Uint16 a);

/**
 * Посылка строки
 * @param msg - Указатель на строку
 */
void Uart_send_msg(char *msg);

/**
 * Настройка таймера ожидания посылки
 */
void Uart_timer_init();

/**
 * Прерывания по переполнению таймера
 */
interrupt void cpu_timer0_isr(void);

#endif /* UART_H_ */
