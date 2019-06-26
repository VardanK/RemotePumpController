#include <Arduino.h>
#include "pump_driver.h"

PumpDriver::PumpDriver(int pin)
{
	this->pin = pin;
	initialized = false;
}

void PumpDriver::init()
{
	// setup the hardware
	initialized = true;
}

void PumpDriver::start() {
	if(initialized) {
		Serial.println("PDRV: Strting the pump!");
	} else {
		Serial.println("PDRV: The pump is not initialized yet");
	}
}


void PumpDriver::stop() {
	if(initialized) {
		Serial.println("PDRV: The pump is shut down!");
	} else {
		Serial.println("PDRV: The pump is not initialized yet");
	}
}
