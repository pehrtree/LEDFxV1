#include "EffectRainbow.h"
#include "LedFxUtilities.h"

void EffectRainbow::setProperties(uint16_t rainbowWidth, uint8_t saturation, uint8_t value, bool reversed) {
	this->rainbowWidth = rainbowWidth;
	this->saturation = saturation;
	this->value = value;
	this->reversed = reversed;
}

bool EffectRainbow::isReversed() {
	return this->reversed;
}

uint16_t EffectRainbow::getRainbowWidth() {
	return this->rainbowWidth;
}

EffectRainbow::EffectRainbow ()
{
	this->reversed = false;
	this->rainbowWidth = 64;
	this->saturation = 255;
	this->value = 255;
}

pRGB EffectRainbow::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum)
{
	uint8_t h = map((currentFrame + pixelNum) % rainbowWidth,0,rainbowWidth,0,255);
	return LEDFxUtilities::HSVtoRGB(h, saturation, value);
}

void EffectRainbow::copyArgs(char * buffer, va_list args) {
	// rainbowWidth
	ARG_TO(buffer,args,unsigned int);
	//saturation
	ARG_TO(buffer,args,unsigned int);
	// value
	ARG_TO(buffer,args,unsigned int);
	// reversed

	ARG_TO(buffer,args,int);
	
}


void EffectRainbow::setArgs(char* buffer) {
	this->rainbowWidth  = ARG_FROM(buffer, unsigned int);
	this->saturation  = ARG_FROM(buffer, unsigned int);
	this->value  = ARG_FROM(buffer, unsigned int);
	reversed = ARG_FROM(buffer,int);
};

