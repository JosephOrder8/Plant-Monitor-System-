#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <Arduino.h>
#include "PlantData.h"
#pragma once

class SensorManager 
{
public:
    void initializeSensors(); 
    void readSensors();
    void storeSensorData();
    float lightIntensity() const;  
    float temperature() const; 
    float humidty() const; 
    float soilMoisture() const;
private:

    float light;       // Light 
    float temp;        // Tempterature 
    float hum;         // Humidity 
    float moisture;    // Moisture 
};
#endif // SENSORMANAGER_H