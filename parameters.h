/*
 * parameters.h
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "DSP2802x_Device.h"

extern Uint16 LedsState;
extern Uint16 TestPrm;

#define READ_PARAMETER_FLAG		1
#define WRITE_PARAMETER_FLAG	2

// описатель флагов
typedef struct {
	Uint16 r:1;		// разрешено чтение
	Uint16 w:1;		// разрешена запись
}Flags_type;

union FlagsUnion {
	Uint16 all;
	Flags_type bit;
};

// описатель параметра
typedef struct {
	Uint16 *Addr;			// указатель на параметр
	Uint16 LowerLimit;		// нижний предел
	Uint16 UpperLimit;		// верхний предел
	union FlagsUnion Flags;	// флаги
}Parameter_type;


extern Parameter_type ParametersTable[];



#endif /* PARAMETERS_H_ */
