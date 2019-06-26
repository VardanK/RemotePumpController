#include <Arduino.h>

#include "led_controller.h"
#include "../driver/led_driver.h"

LedController::LedController(LedDriver *driver) {
	this->ledDriver = driver;
}

void LedController::setIdle() {
	setSolidColor( Colors::GRAY );
}

void LedController::setProcessing() {
	setBlinkColors(Colors::LIGHT_GREEN, Colors::LIGHT_BLUE);
}

void LedController::setSuccess(){
	setTimeoutColors(Colors::LIGHT_GREEN);
}

void LedController::setFailure(){
	setTimeoutColors(Colors::LIGHT_RED);
}

void LedController::update(){
	updateLed();
}

void LedController::setSolidColor(Color c) {
	ledConfig.solid = true;
	ledConfig.blink = false;

	ledConfig.color1 = c;
	ledConfig.color2 = c;

	ledConfig.lastChanged = millis();
}

void LedController::setBlinkColors(Color c1, Color c2) {
	ledConfig.solid = false;
	ledConfig.blink = true;
	ledConfig.blinkShowFirstColor = true;

	ledConfig.color1 = c1;
	ledConfig.color2 = c2;

	ledConfig.lastChanged = millis();
}

void LedController::setTimeoutColors(Color c) {
	ledConfig.solid = false;
	ledConfig.blink = false;

	ledConfig.color1 = Colors::IDLE;
	ledConfig.color2 = c;

	ledConfig.lastChanged = millis();
}


void LedController::updateLed(){
	if(ledConfig.solid) {
		ledDriver->setColor(ledConfig.color1);
	} else if(ledConfig.blink) {

		if (millis() - ledConfig.lastChanged > ledConfig.blinkDelay) {
			ledConfig.blinkShowFirstColor = !ledConfig.blinkShowFirstColor;
			ledConfig.lastChanged = millis();
		}

		if(ledConfig.blinkShowFirstColor) {
			ledDriver->setColor(ledConfig.color1);
		} else {
			ledDriver->setColor(ledConfig.color2);
		}

	} else {
		if(millis() - ledConfig.lastChanged > ledConfig.showDelay) {
			setSolidColor(ledConfig.color1);
		} else {
			ledDriver->setColor(ledConfig.color2);
		}
	}
}