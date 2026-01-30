#pragma once
#include <Arduino.h>
#include "SensorManager.h"

class Display 
{
public:
    void begin();
    void clear();

    void showMenu(const char* label);
    void showSensors(int moisture);
    void showMessage(const char* msg);

    void drawMenuRow(uint8_t row, bool selected, const char* label);
    void showSensorRow(int lcdRow, bool selected, int index, SensorManager& sensors);

private:
    void setLine(uint8_t row, const char* text);
    static constexpr uint8_t COLS = 16;
};