#include <Arduino.h>
#include "led_driver.h"

LedDriver::LedDriver(int pinRed, int pinGreen, int pinBlue){
	this->pinRed = pinRed;
	this->pinGreen = pinGreen;
	this->pinBlue = pinBlue;
}

void LedDriver::init() {
	pinMode(pinRed, OUTPUT);
	pinMode(pinGreen, OUTPUT);
	pinMode(pinBlue, OUTPUT);
}

void LedDriver::setColor(int r, int g, int b) {
	analogWrite(pinRed, r);
	analogWrite(pinGreen, g);
	analogWrite(pinBlue, b);
}

void LedDriver::setColor(Color color) {
	setColor(color.red, color.green, color.blue);
}