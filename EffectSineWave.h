#ifndef INC_SINEWAVEEFFECT_H
#define INC_SINEWAVEEFFECT_H
#include "LEDEffect.h"

// A sine wave lighting effect that carries from dark to white through a particular color
class EffectSineWave : public LEDEffect
{
private:
  uint16_t numLeds;
  pRGB baseColor;
  pRGB destColor;
  float y;
  float cyclePi;
  uint16_t offset;
public:
	void copyArgs(char * buffer, va_list args);
  void setColor(pRGB baseColor, pRGB destColor);
  // Create a sine wave effect. This will not function unless it is cloned to
  EffectSineWave ();
  // Create a sinewave effect for the specified led range, passing through the desired baseColor 
  // cycles number of times accross that range.
  EffectSineWave (pRGB baseColor, pRGB destColor, uint16_t cycles);
  virtual void setFrame (uint16_t frameNumber, RangeInfoList * context);
  virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  virtual void setArgs(char* buffer);
};
#endif
