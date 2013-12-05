// IDrawable.h

#ifndef _IDRAWABLE_h
#define _IDRAWABLE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "RGB.h"
#include "RangeInfoList.h"
#include <stdarg.h>

class IDrawable
{
 public:
	virtual void copyArgs(char * buffer, va_list args) = 0;
	virtual bool update(uint32_t runTime, pRGB* buffer, RangeInfoList* context) = 0;
};


#endif

