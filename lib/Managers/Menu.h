#pragma once
#include <Arduino.h>
#include "ScreenID.h"

struct MenuItem {
    const char* label;
    ScreenID screen;
};

class Menu 
{
public:
    void next();
    void prev();
    ScreenID selected() const;
    const char* currentLabel() const;

private:
    int index = 0;
    static constexpr MenuItem items[] = {
        {"Sensors", ScreenID::SENSORS},
        {"Irrigation", ScreenID::IRRIGATION},
        {"Settings", ScreenID::SETTINGS}
    };
    static constexpr int count = 3;
};