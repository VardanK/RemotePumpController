#pragma once

class PumpDriver
{
private:
	int pin;
	volatile bool initialized;
public:
	PumpDriver(int pin);
	void init();

	void start();
	void stop();
};
