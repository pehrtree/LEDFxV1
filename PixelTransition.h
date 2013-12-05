#ifndef INC_PIXELTRANSITION_H
#define INC_PIXELTRANSITION_H
#include "LEDEffect.h"
// A pixel-by-pixel transition from the previous effect to the current one
// Assumes that the previous effect has executed at least once.
class PixelTransition : public LEDEffect
{
private:
  float scale;
protected:
  virtual void childClone (LEDEffect * effect);
public:
  virtual size_t getSize();
  // Create a pixeltransition object
  PixelTransition ();
  virtual void setFrame (uint32_t frameNumber, RangeInfoList * context);
  virtual RGB getPixel (uint64_t runTime, uint16_t frameCount, uint16_t pixelNum);
};
#endif
