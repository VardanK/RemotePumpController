#include <Arduino.h>
#include "countdown_timer.h"

CountdownTimer::CountdownTimer(int periodSeconds) {
	this->periodSeconds = periodSeconds;
	lastReportedPeriod = -1;
	endTimestamp = 0L;
	running = false;
}

int CountdownTimer::timeLeft() {
	if(endTimestamp != 0) {
		unsigned long timeLeftMillis = endTimestamp - millis();
		if(timeLeftMillis > 0) {
			return timeLeftMillis / 1000;
		} else {
			stop();
		}
	}

	return 0;
}

bool CountdownTimer::shouldUpdateUI() {
	int left = timeLeft();
	if(running && left != lastReportedPeriod) {
		lastReportedPeriod = left;
		return true;
	}

	return false;
}

bool CountdownTimer::isRunning() {
	return running;
}

void CountdownTimer::start() {
	running = true;
	reset();

	endTimestamp = millis() + periodSeconds * 1000L;
}

void CountdownTimer::stop() {
	running = false;
}

void CountdownTimer::reset() {
	lastReportedPeriod = -1;
	endTimestamp = 0L;
}

void CountdownTimer::printDetails() {
	Serial.print("CDT: periodSeconds ");
	Serial.print(periodSeconds);
	Serial.print(" lastReportedPeriod ");
	Serial.println(lastReportedPeriod);
	Serial.print("CDT: now ");
	Serial.print(millis());
	Serial.print(" endTimestamp ");
	Serial.print(endTimestamp);
	Serial.print(" running");
	Serial.println(running);
}