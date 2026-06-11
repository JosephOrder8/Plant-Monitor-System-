#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <Arduino.h>
#include "PlantData.h"

#pragma once

class SensorManager 
{
public:
    void initializeSensors(); 
    void readLiveSensors();
    void recordSensorData();
    void storeSensorData();
    
    float lightIntensity() const;  
    float temperature()    const; 
    float humidty()        const; 
    float soilMoisture()   const;
    String TankLevel()     const;

private:

    // Sensor values
    float light = 0.0f;       // Light 
    float temp = 0.0f;        // Tempterature 
    float hum = 0.0f;         // Humidity 
    float moisture = 0.0f;    // Moisture 
    float waterLevel = 0.0f;  // Water Level
    String TankStatus = "";   // TankLevel Status

     // Sensor objects


    // unsigned long lastUpdate = 0;
    unsigned long updateInterval = 500; // ms

    // Timers for each sensor
    unsigned long tempTimer = 0;
    unsigned long lightTimer = 0;
    unsigned long moistureTimer = 0;
    unsigned long waterTimer = 0;
};
#endif // SENSORMANAGER_H