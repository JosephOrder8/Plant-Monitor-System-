#pragma once
#include <Arduino.h>

enum class MenuState 
{
    HOME,
    LIVE_DATA,
    WATER_STATUS,
    SETTINGS
};

class Menu 
{
public:
    void begin();
    void update();
    MenuState getState() const;

private:
    MenuState currentState = MenuState::HOME;
    int cursor = 0;
    int lastClkState;

    void readEncoder();
    void readButton();
    void drawMenu();
};