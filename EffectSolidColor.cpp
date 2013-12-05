// SolidColorEffect.cpp
//

#include "EffectSolidColor.h"


void EffectSolidColor::setColor(RGB c) {
	this->baseColor = c;
}

RGB EffectSolidColor::getColor() {
	return this->baseColor;
}

EffectSolidColor::EffectSolidColor ()
{
	this->baseColor = EMPTY_COLOR;
}
EffectSolidColor::EffectSolidColor (RGB baseColor)
{
	this->baseColor = baseColor;
}
RGB EffectSolidColor::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)
{
	return baseColor;
}

void EffectSolidColor::copyArgs(char * buffer, va_list args) {
	// baseColor
	ARG_TO(buffer,args,RGB);
}


void EffectSolidColor::setArgs(char* buffer) {
	baseColor = ARG_FROM(buffer,RGB);
};

