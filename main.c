/**
 * Пример использования UART без прерываний
 * @autor lamazavr
 * @date 21.09.2014
 */
#include "DSP28x_Project.h"

// прототипы
void scia_echoback_init(void);
void scia_fifo_init(void);
void scia_xmit(int a);
void scia_msg(char *msg);
void scia_init_gpio();

// количество циклов чтения
Uint16 LoopCount;

#include "parameters.h"

Uint16 LedsState;
Uint16 TestPrm;

Uint16 UartBuffer[50];

void main(void)
{
	Uint16 ReceivedChar;
	char *msg;

	InitSysCtrl();

	DINT;

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	// настраиваем GPIO для SCI
	scia_init_gpio();

	LoopCount = 0;

	scia_fifo_init();      // настройка SCI FIFO
	scia_echoback_init();  // настройка SCI

	msg = "Hello World!\0";
	scia_msg(msg);

	msg = "\r\nYou will enter a character, and the DSP will echo it back! \n";
	scia_msg(msg);

    for(;;)
    {
       msg = "\r\nEnter a character:";
       scia_msg(msg);

       // ждем пока не появятся данные
       while(SciaRegs.SCIFFRX.bit.RXFFST != 1) { } // ждем XRDY

       // Получаем символ
       ReceivedChar = SciaRegs.SCIRXBUF.all;

       // Отправляем обратно
       msg = "  You sent: ";
       scia_msg(msg);
       scia_xmit(ReceivedChar);

       LoopCount++;
    }

}

void scia_echoback_init()
{
    // Тактирование модуля было включено в
	// InitSysCtrl() --> InitPeripheralClocks()

    SciaRegs.SCICCR.all =0x0007;   // 1 стоп бит,  без loopback
                                   // без проверки четности, 8 бит,
                                   // асинхронная передача

    SciaRegs.SCICTL1.all =0x0003;  // вкл TX, RX, internal SCICLK,
                                   // откл RX ERR, SLEEP, TXWAKE

    SciaRegs.SCICTL2.bit.TXINTENA = 1;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

    // SCI BRR = LSPCLK/(SCI BAUDx8) - 1

    // 9600 бод
    // 194 = 15000000 / (9600*8) - 1

    // 256000 бод
    // 6   = 15000000 / (256000*8) - 1

	SciaRegs.SCIHBAUD    = 0x0000;
	SciaRegs.SCILBAUD    = 0x0006;  // для 256000 бод

    SciaRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset
}

/**
 * передаем по SCI
 */
void scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF = a;
}

void scia_msg(char *msg)
{
    while(*msg)
    {
        scia_xmit(*msg++);
    }
}

void scia_fifo_init()
{
    SciaRegs.SCIFFTX.bit.SCIRST = 1; 		// сброс линий rx/tx
	SciaRegs.SCIFFTX.bit.SCIFFENA = 1;		// разрешаем FIFO
	SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;	// сбрасываем FIFO
	SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;	// очищаем флаг прерывания

	// дублирует то, что выше одной строкой
	//SpiaRegs.SPIFFTX.all=0xE040;
}

void scia_init_gpio()
{
	EALLOW;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // подтяжка на GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;	   // откл подтяжки на GPIO29 (SCITXDA)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // асинхронный вход GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // GPIO28 --> SCIRXDA
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // GPIO29 --> SCITXDA
	EDIS;
}
