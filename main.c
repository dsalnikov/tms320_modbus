/**
 * ѕример простейшей реализации Modbus RTU
 * @autor lamazavr
 * @url how2.org.ua
 * @date 04.10.2014
 */
#include "DSP28x_Project.h"

#include "parameters.h"
#include "Uart.h"
#include "modbus_slave.h"

// две переменные дл€ теста
Uint16 LedsState = 0;
Uint16 TestPrm;


void main(void)
{
	InitSysCtrl();

	DINT;

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	// настраиваем SCI
	Uart_init();

	EINT;          // –азрешаем прерывани€ глобально

	char *msg = "\r\nEnter a character:";
    Uart_send_msg(msg);

    EALLOW; // разрешаем доступ к защищенным регистрам
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;

    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;
    EDIS; // запрещаем доступ к регистрам

    GpioDataRegs.GPACLEAR.all = 0xFFFFFFFF;
    GpioDataRegs.GPASET.all = 0xFFFFFFFF;

	for(;;)
    {
		if (LedsState & 0x01)
			GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
		else
			GpioDataRegs.GPASET.bit.GPIO0 = 1;

		if (LedsState & 0x02)
			GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
		else
			GpioDataRegs.GPASET.bit.GPIO1 = 1;

		if (LedsState & 0x04)
			GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
		else
			GpioDataRegs.GPASET.bit.GPIO2 = 1;

		if (LedsState & 0x08)
			GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
		else
			GpioDataRegs.GPASET.bit.GPIO3 = 1;

		DELAY_US(100);
    }

}






