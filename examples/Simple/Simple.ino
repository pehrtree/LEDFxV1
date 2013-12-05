#include <FastSPI_LED2.h>
#include <LEDFx.h>

#define NUM_LEDS 20
#define DATA_PIN 3
#define CLOCK_PIN 3
pRGB buffer[NUM_LEDS];
LEDFxLib ledFx(NUM_LEDS);
EffectRandomPixels rndm;

void setup()
{
	// Initialize fastSPI
        FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(buffer, NUM_LEDS);
	// Initialize LEDFx
	ledFx.init(buffer);
	// Set the hue and saturation
	rndm.setProperties(255,255);
	// Set the FPS
	rndm.setFramerate(8);
	// Set the current effect
	ledFx.setCurrentEffect(rndm);


}

void loop()
{
	if(ledFx.update())
		FastLED.show();
}