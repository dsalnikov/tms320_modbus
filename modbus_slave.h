/*
 * modbus_slave.h
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */

#ifndef MODBUS_SLAVE_H_
#define MODBUS_SLAVE_H_

#include "DSP2802x_Device.h"

enum {
	MODBUS_FUNCTION_ERROR = 1,
	MODBUS_ADDRESS_ERROR,
	MODBUS_DATA_VALUE_ERROR
};

/**
 * Обработчик Modbus запроса
 * @return len - длина ответа
 *         0 - посылка не наша или CRC не совпал
 */
Uint16 modbus_func(Uint16 *Buffer, Uint16 len, Uint16 ModbusAddress);

/**
 * Обработка запроса на чтение
 * @return len - длина ответа
 */
Uint16 modbus_0x03_func(Uint16 *Buffer, Uint16 len);

/**
 * Обработка запроса на запись
 * @return len - длина ответа
 */
Uint16 modbus_0x06_func(Uint16 *Buffer, Uint16 len);

/**
 * Обработка ошибки в запросе
 * формирует ответ с отчетом об ошибке
 * @return 3 - длина посылки ответа об ошибке
 */
Uint16 modbus_error(Uint16 *Buffer, Uint16 err);
#endif /* MODBUS_SLAVE_H_ */
