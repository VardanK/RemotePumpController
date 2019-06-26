#pragma once

#include "../driver/pump_driver.h"
#include "../countdown_timer.h"

class LedController;

class PumpController 
{
private:
	volatile bool pumpOn;
	volatile unsigned long pumpOnTimestamp;
	unsigned long defaultTimeout;

	LedController *ledController;
	CountdownTimer *countdownTimer;
	PumpDriver *pumpDriver;

public:
	PumpController(PumpDriver *pumpDriver, LedController *ledController, unsigned long defaultTimeout = 3000L /*60 seconds*/);

	void startThePump();
	void emergencyStop();
	bool isPumpOn();
	void checkPump();
};
