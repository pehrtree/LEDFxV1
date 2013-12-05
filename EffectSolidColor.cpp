// SolidColorEffect.cpp
//

#include "EffectSolidColor.h"


void EffectSolidColor::setColor(pRGB c) {
	this->baseColor = c;
}

pRGB EffectSolidColor::getColor() {
	return this->baseColor;
}

EffectSolidColor::EffectSolidColor ()
{
	this->baseColor = EMPTY_COLOR;
}
EffectSolidColor::EffectSolidColor (pRGB baseColor)
{
	this->baseColor = baseColor;
}
pRGB EffectSolidColor::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)
{
	return baseColor;
}

void EffectSolidColor::copyArgs(char * buffer, va_list args) {
	// baseColor
	ARG_TO(buffer,args,pRGB);
}


void EffectSolidColor::setArgs(char* buffer) {
	baseColor = ARG_FROM(buffer,pRGB);
};

