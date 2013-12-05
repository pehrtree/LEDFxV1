#ifndef INC_EFFECTRAINBOW_H
#define INC_EFFECTRAINBOW_H

#include "ledeffect.h"
class EffectRainbow :
	public LEDEffect
{
public:
private:
	bool reversed;
	uint16_t rainbowWidth;
	uint8_t saturation;
	uint8_t value;
public:
	void copyArgs(char * buffer, va_list args);
	EffectRainbow();
	void setProperties(uint16_t rainbowWidth, uint8_t saturation, uint8_t value, bool reverse);
	bool isReversed();
	uint16_t getRainbowWidth();
	virtual pRGB getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum);
	virtual void setArgs(char* buffer);

};
#endif

