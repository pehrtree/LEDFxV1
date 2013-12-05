#include "EffectRandomPixels.h"

EffectRandomPixels::EffectRandomPixels() {
  useSatAndVal = false;
}
void EffectRandomPixels::setProperties(uint8_t sat, uint8_t val) {
  useSatAndVal = true;
  this->sat = sat;
  this->val = val;
}

void EffectRandomPixels::setFrame (uint16_t frameNumber, RangeInfoList * context) {

}


pRGB EffectRandomPixels::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)  {
  if(useSatAndVal)
    return LEDFxUtilities::randomColor(sat,val);
  else
    return LEDFxUtilities::randomColor();
}


void EffectRandomPixels::copyArgs(char * buffer, va_list args) {
	// sat
	ARG_TO(buffer,args,unsigned int);
	// val
	ARG_TO(buffer,args,unsigned int);
}

void EffectRandomPixels::setArgs(char* buffer) {
  useSatAndVal = true;
  this->sat = ARG_FROM(buffer,unsigned int);	
  this->val = ARG_FROM(buffer,unsigned int);

  if(sat != 0 || val != 0)
	  useSatAndVal = true;
  else
	  useSatAndVal = false;
}

