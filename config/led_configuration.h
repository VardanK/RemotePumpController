#pragma once

#include "../color.h"

class LedConfiguration {
public:
	int showDelay = 1000;
	int blinkDelay = 500;

	unsigned long lastChanged = 0;

	bool blink = false;
	bool blinkShowFirstColor = false;

	bool solid = false;

	Color color1 = Color(0, 0, 0);
	Color color2 = Color(0, 0, 0);
};
