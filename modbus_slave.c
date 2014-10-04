/*
 * modbus_slave.c
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */
#include "modbus_slave.h"
#include "crc16.h"
#include "parameters.h"

Uint16 modbus_func(Uint16 *Buffer, Uint16 len, Uint16 ModbusAddress)
{
	Uint16 tmp;

	// отвечаем только если нас спрашивают
	if (*Buffer != ModbusAddress)
		return 0;

	// проверяем целосность посылки
	if (Crc16(Buffer,len) != 0)
		return 0;

	// определяем функцию
	switch (Buffer[1])
	{
		// чтение
		case 0x03:
			len = modbus_0x03_func(Buffer, len);
		break;

		// запись
		case 0x06:
			len = modbus_0x06_func(Buffer, len);
		break;
	}
	// добавляем к посылке CRC
	tmp = Crc16(Buffer,len);
	Buffer[len] = tmp & 0xFF;
	Buffer[len+1] = tmp >> 8;

	return len+2;
}

Uint16 modbus_0x03_func(Uint16 *Buffer, Uint16 len)
{
	Uint16 Addr, size, tmp, s_tmp;

	// проверка доступности адреса


	// проверка читаемости регистра
	if (parameter->Flags.bit.r != 1)
		return modbus_error(Buffer, MODBUS_DATA_VALUE_ERROR);

	Addr = (Buffer[2] << 8) | Buffer[3];
	size = (Buffer[4] << 8) | Buffer[5];

	// кладем в буфер Uart количество переменных
	Buffer[2] = size;
	s_tmp = size;
	Buffer += 3;
	for (; size>0; size--, Buffer+=2, Addr++)
	{
		tmp = *ParametersTable[Addr].Addr;
		*Buffer = tmp >> 8;
		Buffer[1] = tmp & 0xFF;
	}
	// возвращаем длину посылки
	// адрес + функция + количество данных + данные
	return (3+s_tmp);
}

Uint16 modbus_0x06_func(Uint16 *Buffer, Uint16 len)
{
	Uint16 Addr, Value;
	const Parameter_type *parameter;

	Addr = (Buffer[2] << 8) | Buffer[3];
	Value = (Buffer[4] << 8) | Buffer[5];

	// проверка доступности адреса

	parameter = &ParametersTable[Addr];

	// проверка доступности регистра для записи
	if (parameter->Flags.bit.w == 1)
	{
		// проверяем пределы
		if (Value > parameter->LowerLimit && Value < parameter->UpperLimit)
		{
			// записываем
			*(parameter->Addr) = Value;
		}
		else return modbus_error(Buffer, MODBUS_DATA_VALUE_ERROR);
	}
	else return modbus_error(Buffer, MODBUS_DATA_VALUE_ERROR);

	// ответ - копия запроса
	return 6;
}

