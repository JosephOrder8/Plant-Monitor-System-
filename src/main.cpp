// main.cpp - Main entry point for the Plant Monitoring System, initializing components and managing the main loop for handling user input and updating the display
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
Menu menu;
MenuScreen menuScreen(menu, screenManager, display);
SensorScreen sensorScreen(sensorManager, display, screenManager);

// Setup function: Initialize components and set the initial screen
void setup() 
{
  Serial.begin(9600);
  encoder.begin(); 
  display.begin();
  
  screenManager.registerScreen(ScreenID::MENU, &menuScreen);
  screenManager.set(ScreenID::MENU);

  screenManager.registerScreen(ScreenID::LIVE_STATUS, &sensorScreen);
  
}

// Main loop: Handle encoder input and update the current screen
void loop() 
{  
  EncoderEvent e = encoder.getEvent();  // Get the current encoder event
     
  if (e != EncoderEvent::NONE)  // If there is an encoder event, handle it
  {
    if (e == EncoderEvent::PRESS) // If the event is a button press, call the appropriate handler
    {
      screenManager.onEncoderPress(); // Handle encoder press events
    }
    else
    {
      screenManager.onEncoderTurn(e); // Handle encoder turn events
    }
  }

  screenManager.update(); // Update the current screen
}