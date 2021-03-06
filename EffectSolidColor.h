#ifndef INC_SOLIDCOLOREFFECT_H
#define INC_SOLIDCOLOREFFECT_H
#include "LEDEffect.h"

// A simple effect that displays a static color over the range
class EffectSolidColor : public LEDEffect
{
private:
  pRGB baseColor;
public:
	void copyArgs(char * buffer, va_list args);
  void setColor(pRGB c);
  pRGB getColor();
  // create an empty solid color effect. All LEDs dark
  EffectSolidColor ();
  // Create a solid color effect for the specified color
  EffectSolidColor (pRGB baseColor);
  virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  virtual void setArgs(char* buffer);
};

#endif
