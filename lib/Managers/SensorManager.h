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
    void displaySensorData(const PlantData& data);
private:
int sensorPin; 
};
#endif // SENSORMANAGER_H