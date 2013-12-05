#ifndef INC_RGB_H
#define INC_RGB_H

// depend on FastSPI CRGB struct
// It is more complicated than the previous one used here
// but supports .r, .g. .b accessors
#include "pixeltypes.h"
typedef struct CRGB pRGB;


inline pRGB cRGB(unsigned char r, unsigned char g, unsigned char b) {
	pRGB v;
	v.r = r; v.g = g; v.b = b;
	return v;
}
extern pRGB EMPTY_COLOR;


#endif