// WaterPump.h - Definition of the WaterPump class for controlling a water pump in the plant monitoring system
#ifndef WATERPUMP_H
#define WATERPUMP_H

#include <Arduino.h>
#pragma once

enum class WaterPumpState 
{
    ON, OFF
}; 

class WaterPump 
{
public:
    void begin(); 
    void PumpON();
    void PumpOFF();
    WaterPumpState getLevel() const;
    
private:
    WaterPumpState currentLevel; 
};
#endif // WATERPUMP_H