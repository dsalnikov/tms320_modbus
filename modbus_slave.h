/*
 * modbus_slave.h
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */

#ifndef MODBUS_SLAVE_H_
#define MODBUS_SLAVE_H_

#include "DSP2802x_Device.h"

Uint16 modbus_func(Uint16 *Buffer, Uint16 len, Uint16 ModbusAddress);

Uint16 modbus_0x03_func(Uint16 *Buffer, Uint16 len);

Uint16 modbus_0x06_func(Uint16 *Buffer, Uint16 len);

#endif /* MODBUS_SLAVE_H_ */
