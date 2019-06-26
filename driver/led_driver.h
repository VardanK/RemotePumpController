#pragma once

#include "../color.h"

class LedDriver {
private:
	int pinRed, pinGreen, pinBlue;
public:
	LedDriver(int pinRed, int pinGreen, int pinBlue);
	void init();

	void setColor(int r, int g, int b);
	void setColor(Color color);
};