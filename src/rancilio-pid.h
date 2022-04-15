#ifndef _RANCILIO_PID_H_
#define _RANCILIO_PID_H_

#include <stdint.h>


// Functions
int factoryReset(void);
int readSysParamsFromStorage(void);
int writeSysParamsToStorage(void);

#endif
