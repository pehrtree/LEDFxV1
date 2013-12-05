
#ifndef EffectRandomPixels_h
#define EffectRandomPixels_h

#include "ledeffect.h"
#include "LedFxUtilities.h"
class EffectRandomPixels :
  public LEDEffect
{
private:
  bool useSatAndVal;
  uint8_t val;
  uint8_t sat;
public:
	void copyArgs(char * buffer, va_list args);
  EffectRandomPixels();
  virtual void setFrame (uint16_t frameNumber, RangeInfoList * context);
  // specify a particular saturation and luminosity value that should be used
  // when selecting random pixels.
  void setProperties(uint8_t saturation, uint8_t value);
  virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  virtual void setArgs(char* buffer);
};

#endif