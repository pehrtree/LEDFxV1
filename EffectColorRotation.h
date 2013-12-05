#ifndef INC_EFFECTCOLORROTATION_H
#define INC_EFFECTCOLORROTATION_H
#include "LEDEffect.h"

// A simple effect that rotates through randomly chosen colors
class EffectColorRotation : public LEDEffect
{
private:
  pRGB currentColor;
  pRGB nextColor;
  uint16_t frameDuration;
  uint16_t fadeDuration;
  uint32_t lastChange;
  pRGB randomColor();
  bool useSatAndVal;
  uint8_t val;
  uint8_t sat;
  pRGB getNextColor();
public:
  void copyArgs(char * buffer, va_list args);
  // create an empty color gradient effect. All LEDs dark
  EffectColorRotation ();
  // Create a solid color effect for the specified color that lasts the specified number of frames.
  // FadeDuration controls how many frames are used to transition from 1 color to the next
  EffectColorRotation (uint16_t colorDuration,uint16_t fadeDuration);
  // called once per frame. Useful for cashing frame-level values.
  virtual void setFrame (uint16_t currentFrame, RangeInfoList * context);
  // specify a particular saturation and luminosity value that should be used
  // when selecting random pixels.
  void setSaturationAndValue(uint8_t saturation, uint8_t value);
  virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
  void reset();
  virtual void setArgs(char* buffer);
};

#endif