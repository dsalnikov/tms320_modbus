/*
 * Uart.c
 *
 *  Created on: 05 окт. 2014 г.
 *      Author: lamazavr
 */

#include "Uart.h"

// буфер для modbus
Uint16 UartBuffer[50];

void Uart_init()
{
	Uart_init_gpio();

    // Тактирование модуля было включено в
	// InitSysCtrl() --> InitPeripheralClocks()

    SciaRegs.SCICCR.all =0x0007;   // 1 стоп бит,  без loopback
                                   // без проверки четности, 8 бит,
                                   // асинхронная передача

    SciaRegs.SCICTL1.all =0x0043;  // вкл TX, RX, internal SCICLK,
                                   // откл RX ERR, SLEEP, TXWAKE
    							   // RX interrupt

    SciaRegs.SCICTL2.bit.TXINTENA = 1;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

    SciaRegs.SCIFFTX.all=0xC022;
    SciaRegs.SCIFFRX.all=0x0022;
    SciaRegs.SCIFFCT.all=0x00;

    // SCI BRR = LSPCLK/(SCI BAUDx8) - 1

    // 9600 бод
    // 194 = 15000000 / (9600*8) - 1

    // 256000 бод
    // 6   = 15000000 / (256000*8) - 1

	SciaRegs.SCIHBAUD    = 0x0000;
	SciaRegs.SCILBAUD    = 0x0006;  // для 256000 бод

    SciaRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset
    SciaRegs.SCIFFTX.bit.TXFIFOXRESET=1;
    SciaRegs.SCIFFRX.bit.RXFIFORESET=1;

    // разрешаем прерывание по приему данных по uart
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
	PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
}

void Uart_init_gpio()
{
	EALLOW;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // подтяжка на GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;	   // откл подтяжки на GPIO29 (SCITXDA)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // асинхронный вход GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // GPIO28 --> SCIRXDA
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // GPIO29 --> SCITXDA
	EDIS;
}

void Uart_send(Uint16 a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF = a;
}

void Uart_send_msg(char *msg)
{
    while(*msg)
    {
    	Uart_send(*msg++);
    }
}
