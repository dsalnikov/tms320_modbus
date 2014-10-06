/*
 * ParametersTable.h
 *
 *  Created on: 04 окт. 2014 г.
 *      Author: salnikov
 */

#ifndef PARAMETERSTABLE_H_
#define PARAMETERSTABLE_H_

#include "parameters.h"

// тестовая таблица параметров
Parameter_type ParametersTable[] =
{
	{&LedsState,	0,	0xFF,	READ_PARAMETER_FLAG | WRITE_PARAMETER_FLAG	},
	{&TestPrm, 		0, 	0xFFFF, READ_PARAMETER_FLAG | WRITE_PARAMETER_FLAG	},
};

// количество параметров
#define	ParametersCount (sizeof(ParametersTable)/sizeof(Parameter_type))

#endif /* PARAMETERSTABLE_H_ */
