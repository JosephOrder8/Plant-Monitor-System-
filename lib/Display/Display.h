#pragma once
#include <Arduino.h>

class Display 
{
public:
    void begin();
    void clear();

    void showMenu(const char* label);
    void showSensors(int moisture);
    void showMessage(const char* msg);

private:
    void setLine(uint8_t row, const char* text);
};