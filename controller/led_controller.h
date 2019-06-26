#pragma once

#include "../config/led_configuration.h"

class LedDriver;

class LedController {
private:
	LedDriver *ledDriver;
	LedConfiguration ledConfig;

public:
	LedController(LedDriver *driver);

	// solid colors
	void setIdle();

	// blink methods
	void setProcessing();

	// toast methods
	void setSuccess();
	void setFailure();

	void update();

private:
	void setSolidColor(Color color);
	void setBlinkColors(Color color1, Color color2);
	void setTimeoutColors(Color color1);

	void updateLed();
};