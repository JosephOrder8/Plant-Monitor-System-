// pin.h
#pragma once
#include <Arduino.h>
// ---------------------------
// Arduino pins
// ---------------------------
namespace ArduinoPins 
{
    // Sensors
    constexpr int SOIL_MOISTURE_PIN = A0;
    constexpr int LIGHT_SENSOR_PIN  = A1;
    constexpr int TEMP_SENSOR_PIN   = 8;

    // Irrigation System
    // constexpr int WATER_PUMP_PIN    = 3;
    // constexpr int TANK_LEVEL_PIN    = 5;

    // Menu Display
    constexpr int I2C_SDA_PIN       = A4;
    constexpr int I2C_SCL_PIN       = A5;
    constexpr uint8_t ENC_CLK_PIN   = 2;
    constexpr uint8_t ENC_DT_PIN    = 3;
    constexpr uint8_t ENC_SW_PIN    = 4;
}