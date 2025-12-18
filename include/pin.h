// pins.h
#pragma once
#include <Arduino.h>
// ---------------------------
// Arduino pins
// ---------------------------
namespace ArduinoPins 
{
    // Sensors
    constexpr int SOIL_MOISTURE_PIN = A1;
    constexpr int LIGHT_SENSOR_PIN  = A5;
    constexpr int TEMP_SENSOR_PIN   = A2;

    // Actuators
    // constexpr int WATER_PUMP    = 3;
    // constexpr int FAN           = 5;

    // Communication
    //constexpr int I2C_SDA       = A4;
    //constexpr int I2C_SCL       = A5;
}