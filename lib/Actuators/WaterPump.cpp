// WaterPump.cpp - Implementation of the WaterPump class for controlling a water pump in the plant monitoring system
#include "WaterPump.h"
#include <pin_config.h>

void WaterPump::begin() 
{
    pinMode(ArduinoPins::WATER_PUMP_PIN, OUTPUT);
}

void WaterPump::PumpON() 
{
    digitalWrite(ArduinoPins::WATER_PUMP_PIN, HIGH); // Turn pump ON
    Serial.println("Water Pump: ON");
}

void WaterPump::PumpOFF() 
{
    digitalWrite(ArduinoPins::WATER_PUMP_PIN, LOW); // Turn pump OFF
    Serial.println("Water Pump: OFF");
}

WaterPumpState WaterPump::getLevel() const
{
    return currentLevel;
}