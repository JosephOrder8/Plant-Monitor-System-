#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include <Arduino.h>
#pragma once

enum class MoistureLevel 
{
    VERY_WET, WET, DRY, ERROR
};

class MoistureSensor 
{
public:
    void begin(); 
    int read();
    void moistureLevel();
    MoistureLevel getLevel() const;
private:
    int sensorPin;
    MoistureLevel currentLevel; 
};
#endif // MOISTURESENSOR_H