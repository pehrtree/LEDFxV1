// EffectProgressBar.cpp
//

#include "EffectProgressBar.h"


void EffectProgressBar::setProperties(pRGB lowColor, pRGB highColor, uint8_t value) {
	this->lowColor = lowColor;
	this->highColor = highColor;
	this->value = value;
}

void EffectProgressBar::setValue(uint8_t value) {
	this->value = value;
}


EffectProgressBar::EffectProgressBar ()
{
	setProperties(cRGB(0,255,0), cRGB(255,0,0),0);
}
EffectProgressBar::EffectProgressBar (pRGB lowColor, pRGB highColor)
{
	setProperties(lowColor, highColor, 0);
}

void EffectProgressBar::setFrame (uint16_t currentFrame, RangeInfoList * context) {
	numLit = map(value,0,255,0,context->size);
	scale = 1.0/((float)context->size);		
}
pRGB EffectProgressBar::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)
{
	if(pixelNum < numLit) {
		pRGB retVal = LEDFxUtilities::interpolate(lowColor,highColor, (float)pixelNum*scale);
		return retVal;
	}
	else
		return EMPTY_COLOR;
}

void EffectProgressBar::copyArgs(char * buffer, va_list args) {
	// lowColor
	ARG_TO(buffer,args,pRGB);
	// highColor
	ARG_TO(buffer,args,pRGB);
	// value
	ARG_TO(buffer,args,int);
}


void EffectProgressBar::setArgs(char* buffer) {
	lowColor = ARG_FROM(buffer,pRGB);
	highColor = ARG_FROM(buffer,pRGB);
	value = ARG_FROM(buffer,int);
};

