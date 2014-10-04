/*
 * modbus_slave.c
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */

Uint16 modbus_func(Uint16 *Buffer, Uint16 len, Uint16 ModbusAddress)
{
	Uint16 tmp;

	if (*Buffer != ModbusAddress)
		return 0;

	// test CRC hear

	switch (Buffer[1])
	{
		case 0x03:
			tmp = modbus_0x03_func(Buffer, len);
		break;

		case: 0x05:
			tmp = modbus_0x05_func(Buffer, len);
		break;
	}

	return tmp;
}


