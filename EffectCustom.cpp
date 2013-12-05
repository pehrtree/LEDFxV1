#include "EffectCustom.h"

// Creates an empty custom effect. This will do nothing unless cloned to.
EffectCustom::EffectCustom() {
	getPixelFunc = NULL;
}
// create an empty solid color effect. All LEDs dark
EffectCustom::EffectCustom(RGB (*getPixelFunc)(uint32_t,uint16_t, uint16_t)) {
	this->getPixelFunc = getPixelFunc;
}

RGB EffectCustom::getPixel(uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum) {
	if(getPixelFunc != NULL)
		return getPixelFunc(runTime,currentFrame,pixelNum);
	else
		return EMPTY_COLOR;
}

void EffectCustom::copyArgs(char * buffer, va_list args) {
}

void EffectCustom::setArgs(char* buffer) {
};
