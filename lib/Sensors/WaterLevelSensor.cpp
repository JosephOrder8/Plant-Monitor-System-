// WaterLevelSensor.cpp - Implementation of the WaterLevelSensor class for reading water level data from an ultrasonic sensor
#include "WaterLevelSensor.h"
#include <pin_config.h>
#include <Arduino.h>

void WaterLevelSensor::begin() 
{
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, OUTPUT);
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
}

int WaterLevelSensor::read() 
{
    // Send a 10 microsecond pulse to trigger the sensor
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, OUTPUT);
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, LOW);
    delayMicroseconds(2);
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
    
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, LOW);

    // Read the echo time
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
    duration = pulseIn(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, HIGH); // Timeout after 100 ms to prevent blocking

    // Calculate distance in centimeters
    distance = duration * 0.0343 / 2.0;

    // Serial.print("Current Water Level: "+ String(distance) +" cm, Duration: "+ String(duration) + "\n");

    return (int)distance;
}

int WaterLevelSensor::waterLevel() 
{
    float tankHeight = 14; // Total container height is 14 cm 
    float offset = 1.68;   // Offset measurement 1.68 cm
    
    float waterLevel = tankHeight - read() - offset; 
    
    if (waterLevel < 0) 
    {
        waterLevel = 0;  // Prevent negative water level values
    }
    return waterLevel;
    Serial.print("Current Water Level: "+ String(waterLevel) + " cm\n");
}

String getWaterLevelString(WaterLevel level) 
{
    switch (level) 
    {
        case WaterLevel::FULL:         return "Full";
        case WaterLevel::MEDIUM:       return "Medium";
        case WaterLevel::CRITICAL_LOW: return "Critical Low";
        case WaterLevel::EMPTY:        return "Empty";
        default:                       return "Unknown";
    }
}


String WaterLevelSensor::waterLevelStatus() 
{
    int level = waterLevel();

    if (level >= 10) 
    {
        currentLevel = WaterLevel::FULL;

    } 
    else if (level >= 5) 
    {
        currentLevel = WaterLevel::MEDIUM;
    } 
    else if (level > 0) 
    {
        currentLevel = WaterLevel::CRITICAL_LOW;
    } 
    else 
    {
        currentLevel = WaterLevel::EMPTY;
    }

     // Convert the enum to a string
    levelString = getWaterLevelString(currentLevel);

    // Print the string to the serial monitor
    Serial.println("Water Level Status: " + levelString + " (" + String(level) + " cm)");
    return levelString;
}

WaterLevel WaterLevelSensor::getLevel() const
{
    return currentLevel;
}