#ifndef WATERSENSOR_H
#define WATERSENSOR_H

#include <Arduino.h>
#pragma once

enum class WaterLevel 
{
    FULL, MEDIUM, CRITICAL_LOW,EMPTY
};

class WaterLevelSensor 
{
public:
    void begin(); 
    int read();
    int waterLevel();
    void waterLevelStatus();
    WaterLevel getLevel() const;

private:
    float distance,duration; 
    WaterLevel currentLevel;
};
#endif // WATERSENSOR_H