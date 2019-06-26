#pragma once

class CountdownTimer {
private:
	int periodSeconds;
	int lastReportedPeriod;
	unsigned long endTimestamp;
	bool running;
public:
	CountdownTimer(int periodSeconds);
	bool shouldUpdateUI();
	int timeLeft();

	bool isRunning();
	void start();
	void stop();
	void reset();

	void printDetails();
};
