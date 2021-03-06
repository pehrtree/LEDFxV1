#ifndef INC_EFFECTPROGRESSBAR_H
#define INC_EFFECTPROGRESSBAR_H
#include "LedFxUtilities.h"
#include "LEDEffect.h"

// A simple effect that displays values in a range of 0-255 as a progress bar from one color to another
class EffectProgressBar : public LEDEffect
{
private:
  pRGB lowColor;
  pRGB highColor;
  uint8_t value;
  int numLit;
  float scale;
public:
	void copyArgs(char * buffer, va_list args);
  // create an empty progress bar. Colors will go from green to red
  EffectProgressBar ();
  EffectProgressBar (pRGB lowColor, pRGB highColor);
  // Create a solid color effect for the specified color
  void setProperties(pRGB lowColor, pRGB highColor,uint8_t value);
  void setValue(uint8_t value);
  void setFrame (uint16_t currentFrame, RangeInfoList * context);
  virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  virtual void setArgs(char* buffer);
};

#endif
