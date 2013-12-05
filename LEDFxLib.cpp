#include "LEDFxLib.h"
#ifdef __AVR_ATmega328P__
#include "new.h"
#endif

RGB EMPTY_COLOR = {0,0,0};

LEDFxLib::LEDFxLib(uint16_t ledNum) : 
	ledNum(ledNum),
	currentList(-1,0,ledNum)
{
}
LEDFxLib::~LEDFxLib() {
	clear();
}

// removes all of the associated effects.
void LEDFxLib::clear() {
	currentList.clear();
}

// Initializes the library. You _must_ have initialized fastSPI before this call!
void LEDFxLib::init(RGB* leds)
{
	this->leds = leds; 
	currentList.clear();
}

// defines a range with the specified range identifier in the specified strip location
// use this identifier elsewhere to reference this range
void LEDFxLib::addRange(int rangeId, uint16_t offset, uint16_t size) {
	if(!currentList.containsRange(rangeId)) {
		currentList.add(rangeId, offset, size);
	}
}

// Adds an effect. If a range is not specified, this spans the entire LED strip, if a range is specified. Only that section will be used
//void LEDFxLib::setEffectSequence(LEDEffectSequence &sequence, int rangeId) {
//	currentList.setEffect(rangeId, sequence);
//}

// Sets 1 effect to display. This will overwrite anything added by the 'addEffect' call.
void LEDFxLib::clearCurrentEffect(int rangeId) {
	currentList.clearEffect(rangeId);
}

// Sets 1 effect to display. This will overwrite anything added by the 'addEffect' call.
void LEDFxLib::setCurrentEffect(LEDEffect &effect, int rangeId) {
	if(rangeId == -1)
		currentList.clearAll();
	currentList.setEffect(rangeId, effect);
}

// Sets 1 effect to display. This will overwrite anything added by the 'addEffect' call.
void LEDFxLib::setCurrentEffectWithArgs(LEDEffect & effect, int rangeId,...) {
	va_list va;
	va_start(va, rangeId);
	currentList.setEffectWithArgs(rangeId, effect, va);
	va_end(va);
}


// Sets 1 effect to display. This will overwrite anything added by the 'addEffect' call.
IDrawable* LEDFxLib::getCurrentEffect(int rangeId) {
	return currentList.getEffect(rangeId);
}




// iterates the effects over time
bool LEDFxLib::update() {
	RangeInfoList *cur = &currentList;
	uint32_t runTime = millis() - cur->startTime;
	bool anyUpdate = false;
	do {
		if (cur->listItem != NULL && cur->listItem->update(runTime, leds, cur)) {
			anyUpdate = true;
			cur->refreshCount++;
			cur->lastRefreshTime = runTime;
		}
		cur = cur->next;
	}
	while(cur != NULL);
	return anyUpdate;
}
