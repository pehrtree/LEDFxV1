#ifndef INC_CUSTOMEFFECT_H
#define INC_CUSTOMEFFECT_H
#include "LEDEffect.h"

// An effect with a callback to a custom user display function
class EffectCustom : public LEDEffect {
private:
	pRGB (*getPixelFunc)(uint32_t,uint16_t, uint16_t);
public:
	void copyArgs(char * buffer, va_list args);
	// Creates an empty custom effect. This will do nothing unless cloned to.
	EffectCustom();
	// create an empty solid color effect. All LEDs dark
	EffectCustom(pRGB (*getPixelFunc)(uint32_t,uint16_t, uint16_t));

  pRGB getPixel(uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  virtual void setArgs(char* buffer);
};

#endif