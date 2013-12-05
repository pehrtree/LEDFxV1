// LEDEffect.cpp
//

#include "LEDEffect.h"

LEDEffect::LEDEffect() {
	setFramerate(1000, FRAME_ORDER_SEQUENTIAL);
}

void LEDEffect::setFramerate (float framesPerSecond, frame_order frameOrder) {
	this->waitTime = 1000/framesPerSecond;
	this->frameOrder = frameOrder;
	currentFrame = 0;
}

void LEDEffect::reset ()
{
	currentFrame = 0;
}

void LEDEffect::setFrame (uint16_t currentFrame, RangeInfoList* context)
{
	this->currentFrame = currentFrame;
	this->context = context;
	if(context->hasArgs)
		this->setArgs(context->contextArgs);
}


bool LEDEffect::update(uint32_t runTime, RGB* buffer, RangeInfoList * context)  {
	if((runTime - context->lastRefreshTime) > this->waitTime) {
		if(frameOrder == FRAME_ORDER_SEQUENTIAL) {
			setFrame(context->refreshCount, context);
		}
		else {
			setFrame((runTime - context->startTime) / this->waitTime, context);
		}
		for(int i = 0; i < context->size; i++) {
			RGB val = getPixel(runTime, currentFrame, i);
			buffer[i+context->offset] = val;
		}
		return true;
	}
	return false;

}
