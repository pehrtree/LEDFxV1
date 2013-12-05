// PixelTransition.cpp
//

#include "PixelTransition.h"
#include "LEDFxUtilities.h"
size_t PixelTransition::getSize() {
	return sizeof((*this));
}

void PixelTransition::childClone (LEDEffect * effect)
{
	PixelTransition *clone = (PixelTransition*)effect;
	clone->scale = scale;
}
PixelTransition::PixelTransition ()
{
}
void PixelTransition::setFrame (uint32_t frameNumber, RangeInfoList * context)
{
	LEDEffect::setFrame(frameNumber, context);
//	scale = (float)frameNumber/(float)duration;
}
RGB PixelTransition::getPixel (uint64_t runTime, uint16_t frameCount, uint16_t pixelNum) {
//	RGB prevPix = previousEffect->getPixel(runTime, previousEffect->currentFrame, pixelNum);
//	RGB nextPix = expectedNextEffect->getPixel(runTime, 0, pixelNum);
//	return LEDFxUtilities::interpolate(prevPix, nextPix, scale);
	return cRGB(0,0,0);
}
