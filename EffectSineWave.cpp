// SineWaveEffect.cpp
//

#include "EffectSineWave.h"
#include "LedFxUtilities.h"

EffectSineWave::EffectSineWave ()
{
	setColor(cRGB(0,0,0), cRGB(255,255,255));
	this->cyclePi = PI * 4.0;
	this->offset = 0;
}
EffectSineWave::EffectSineWave (RGB baseColor, RGB destColor, uint16_t cycles)
{
	this->cyclePi = 2* PI * (float)cycles;
	this->offset = offset;
	setColor(baseColor,destColor);
}

void EffectSineWave::setColor(RGB baseColor, RGB  destColor) {
	this->baseColor = baseColor;
	this->destColor = destColor;
}

void EffectSineWave::setFrame(uint16_t frameNumber, RangeInfoList * context) 
{
	LEDEffect::setFrame(frameNumber,context);
	this->numLeds = context->size;
	this->offset = context->offset;
}

RGB EffectSineWave::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)
{
	RGB retVal;
	currentFrame %= (uint16_t)numLeds;

	y = sin(cyclePi * (float)((currentFrame +offset)+ pixelNum) / (float)numLeds);
	return LEDFxUtilities::interpolate(baseColor, destColor, (y + 1.0)/2.0);
	/*		if(y >= 0.0) {
	y  = 1.0 - y;
	retVal.r = 255 - (char)((float)(255 - baseColor.r) * y);
	retVal.g = 255 - (char)((float)(255 - baseColor.g) * y);
	retVal.b = 255 - (char)((float)(255 - baseColor.b) * y);
	} else {
	y += 1.0;
	retVal.r = (char)((float)baseColor.r * y);
	retVal.g = (char)((float)baseColor.g * y);
	retVal.b = (char)((float)baseColor.b * y);
	}
	return retVal;*/
}

void EffectSineWave::copyArgs(char * buffer, va_list args) {
	// baseColor
	ARG_TO(buffer,args,RGB);
	// destColor
	ARG_TO(buffer,args,RGB);
	// cyclePi
	ARG_TO(buffer,args,unsigned int);
}

void EffectSineWave::setArgs(char* buffer) {
	baseColor = ARG_FROM(buffer,RGB);
	destColor = ARG_FROM(buffer,RGB);
	cyclePi = ARG_FROM(buffer,unsigned int);
};

