#include "EffectColorRotation.h"
#include "LEDFxUtilities.h"


// create an empty color gradient effect. All LEDs dark
EffectColorRotation::EffectColorRotation () {
	this->currentColor = getNextColor();
	this->nextColor = cRGB(0,0,0);
	this->frameDuration = 0;
	this->lastChange = 0;
	this->fadeDuration = 0;
	useSatAndVal = false;
}
EffectColorRotation::EffectColorRotation (uint16_t colorDuration, uint16_t fadeDuration) {
	this->currentColor = getNextColor();
	this->nextColor = EMPTY_COLOR;
	this->lastChange = 0;
	this->frameDuration = colorDuration;
	this->fadeDuration = fadeDuration;
	useSatAndVal = false;

}

void EffectColorRotation::setSaturationAndValue(uint8_t sat, uint8_t val) {
	useSatAndVal = true;
	this->sat = sat;
	this->val = val;
	this->currentColor = getNextColor();
}

void EffectColorRotation::reset() {
	lastChange = 0;
}

void EffectColorRotation::setFrame (uint16_t currentFrame, RangeInfoList * context) {
	LEDEffect::setFrame(currentFrame, context);
	if(currentFrame >=  lastChange + frameDuration) {
		// if completely done
		if(currentFrame >= lastChange + frameDuration + fadeDuration) {
			lastChange = currentFrame;
			// if we haven't picked the next color, do so
			if(this->nextColor.r == 0 && nextColor.g == 0 && nextColor.b == 0) 
				this->nextColor = getNextColor();
			this->currentColor = nextColor;
			this->nextColor = cRGB(0,0,0);
		}
		else {
			// if we haven't picked the next color, do so
			if(this->nextColor.r == 0 && nextColor.g == 0 && nextColor.b == 0)
				this->nextColor = getNextColor();
			// now interpolate (only add 1 frame, since we're resetting the source each time
			this->currentColor = LEDFxUtilities::interpolate(currentColor, nextColor, 
				1.0/(float)(fadeDuration-(currentFrame - (lastChange + frameDuration))));
		}

	}
}
RGB EffectColorRotation::getNextColor() {
	if(useSatAndVal)
		return LEDFxUtilities::randomColor(sat,val);
	else
		return LEDFxUtilities::randomColor();
}

RGB EffectColorRotation::getPixel (uint32_t runTime, uint16_t currentFrame, uint16_t pixelNum) {
	return currentColor;
}

void EffectColorRotation::copyArgs(char* buffer, va_list args) {
	// frameduration
	ARG_TO(buffer,args,unsigned int);
	// fade duration
	ARG_TO(buffer,args,unsigned int);
	// saturation
	ARG_TO(buffer,args,unsigned int);
	// value
	ARG_TO(buffer,args,unsigned int);
}

void EffectColorRotation::setArgs(char* buffer) {
	this->frameDuration = ARG_FROM(buffer,unsigned int);	
	this->fadeDuration = ARG_FROM(buffer,unsigned int);
	this->sat = (uint8_t)ARG_FROM(buffer, unsigned int);
	this->val = (uint8_t)ARG_FROM(buffer, unsigned int);
	if(this->sat > 0 || this->val > 0)
		this->useSatAndVal = true;
	else
		this->useSatAndVal = false;
};
