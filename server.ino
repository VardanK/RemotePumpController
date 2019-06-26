#include "controller/pump_controller.h"
#include "driver/pump_driver.h"

#include "controller/led_controller.h"
#include "driver/led_driver.h"

const uint8_t btnStart = 2;
const uint8_t btnStop = 3;
const unsigned long pumpTimeout = 5000;

LedDriver ledDriver(11, 10, 9);
LedController ledController(&ledDriver);

PumpDriver pumpDriver(10);
PumpController pumpController(&pumpDriver, &ledController, pumpTimeout);

void setup() {
  Serial.begin(9600);

  ledDriver.init();
  
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btnStart), onButtonStartClicked, FALLING);
  attachInterrupt(digitalPinToInterrupt(btnStop), onButtonStopClicked, FALLING);
  
  pumpDriver.init();
  pumpDriver.stop();

  ledController.setIdle();

  Serial.println("Controller setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  pumpController.checkPump();
  ledController.update();
}

void onButtonStartClicked() {
  pumpController.startThePump();
}

void onButtonStopClicked() {
  pumpController.emergencyStop();
}
