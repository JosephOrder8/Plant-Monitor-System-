#pragma once
#include "Screen.h"

enum class ScreenID 
{
    MENU,
    SENSORS
};

class ScreenManager 
{
public:
    void set(ScreenID id);              // Switch to a specific screen                          
    void update();                      // Update the current screen
    void handleEncoder(EncoderEvent e); // Handle encoder events

    void registerScreen(ScreenID id, Screen* screen);  // Register a screen with an ID

private:
    Screen* current = nullptr;      // Pointer to the current screen
    Screen* screens[2] = {nullptr}; // Array to hold registered screens
};