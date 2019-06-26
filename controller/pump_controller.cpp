#include <Arduino.h>
#include "pump_controller.h"
#include "led_controller.h"

PumpController::PumpController(PumpDriver *pumpDriver, LedController *ledController, unsigned long defaultTimeout) {
	this->defaultTimeout = defaultTimeout;
	this->pumpDriver = pumpDriver;
	this->countdownTimer = new CountdownTimer(defaultTimeout / 1000);
	this->ledController = ledController;

	pumpOnTimestamp = 0;
	pumpOn = false;
}

void PumpController::startThePump()
{
	if(!pumpOn){
		pumpOnTimestamp = 0;
		pumpOn = true;

		pumpDriver->start();
		countdownTimer->start();
		ledController->setProcessing();
	}
}

bool PumpController::isPumpOn()
{
	return pumpOn;
}

void PumpController::checkPump()
{
	if(pumpOn) {
		if(pumpOnTimestamp <= 0) {
			pumpOnTimestamp = millis();
		}

		// check the timeout
		if(pumpOnTimestamp + defaultTimeout < millis()) {
			pumpDriver->stop();
			countdownTimer->stop();
			ledController->setIdle();

			pumpOn = false;
			pumpOnTimestamp = 0;
		} else if(countdownTimer->shouldUpdateUI()) {
			Serial.print("PCNT: Time left: ");
			Serial.println(countdownTimer->timeLeft());
		}
	}	
}

void PumpController::emergencyStop() {
	if(pumpOn) {
		pumpDriver->stop();
		countdownTimer->stop();
		ledController->setFailure();

		pumpOn = false;
		pumpOnTimestamp = 0;
	}
}
