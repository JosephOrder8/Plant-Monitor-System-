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
    
    if (current) current->exit();     // Exit current screen
    current = screens[(int)id];       // Set new screen
    if (current) current->enter();    // Enter new screen
}

void ScreenManager::update() // Update the current screen
{
    if (current) current->update();
}

void ScreenManager::onEncoderTurn(EncoderEvent e)
{
    if (current)
        current->onEncoderTurn(e);
}

void ScreenManager::onEncoderPress()
{
    // Serial.println("ScreenManager: Encoder PRESS event");
    if (current)
        current->onEncoderPress();
}

/*
void ScreenManager::onEncoderTurn(int dir) 
{
    if (current) current->onEncoderTurn(dir);
}
*/