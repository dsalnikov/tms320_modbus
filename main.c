/**
 * Пример простейшей реализации Modbus RTU
 * @autor lamazavr
 * @url how2.org.ua
 * @date 04.10.2014
 */
#include "DSP28x_Project.h"

// прототипы
void scia_init(void);
void scia_xmit(int a);
void scia_msg(char *msg);
void scia_init_gpio();

// количество циклов чтения
Uint16 LoopCount;

#include "parameters.h"
#include "Uart.h"

// две переменные для теста
Uint16 LedsState;
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

	IER |= M_INT9; // Разрешаем прерывание ядра по линии 9
	EINT;          // Разрешаем прерывания глобально

	char *msg = "\r\nEnter a character:";
    Uart_send_msg(msg);

	for(;;)
    {
       DELAY_US(100);
    }

}






