// ScreenManager.cpp - Implementation of the ScreenManager class for managing different screens in the plant monitoring system
#include "ScreenManager.h"
#include <Arduino.h>

void ScreenManager::registerScreen(ScreenID id, Screen* screen) // Register a screen with an ID
{
    screens[(int)id] = screen;
}

void ScreenManager::set(ScreenID id) // Switch to a specific screen
{
    Serial.print("Screen change requested: ");
    Serial.println((int)id);
    
    if (current) 
    {
        current->exit();     // Exit current screen
    }
    
    current = screens[(int)id];       // Set new screen
    
    if (current) 
    {
        current->enter();    // Enter new screen
    }
}

void ScreenManager::update() // Update the current screen
{
    if (current) 
    {
        current->update();
    }
}

void ScreenManager::onEncoderTurn(EncoderEvent e)
{
    if (current)
    {
        Serial.println("ScreenManager: Encoder turn event: " + String((int)e));
        current->onEncoderTurn(e);
    }
}

void ScreenManager::onEncoderPress()
{
    // Serial.println("ScreenManager: Encoder PRESS event");
    if (current)
    {
        current->onEncoderPress();
    }
}