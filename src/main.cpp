#include <Arduino.h>  // Default Arduino library
#include "Encoder.h"
#include "ScreenManager.h"
#include "SensorManager.h"
#include "SensorScreen.h"
#include "Menu.h"
#include "MenuScreen.h"
#include "Display.h"

// Global objects
Encoder encoder;
ScreenManager screenManager;
SensorManager sensorManager;
Display display;

// Screens
SensorScreen sensorScreen(sensorManager);
Menu menu;
MenuScreen menuScreen(menu, screenManager, display);

void setup() 
{
  Serial.begin(9600);
  encoder.begin();
  display.begin();
  
  screenManager.registerScreen(ScreenID::MENU, &menuScreen);
  screenManager.set(ScreenID::MENU);

  // screenManager.registerScreen(ScreenID::LIVE_DATA, &sensorScreen);
  // screenManager.set(ScreenID::LIVE_DATA);
  
}

void loop() 
{
  // 1. Update encoder
    encoder.update();
  
  // 2. Get encoder event
  EncoderEvent e = encoder.getEvent();
  if (e != EncoderEvent::NONE) 
  {
    screenManager.handleEncoder(e);
  }

  // 3. Update active screen
  screenManager.update();
}
