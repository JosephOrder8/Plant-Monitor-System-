// IrrigationManager.cpp - Implementation of the IrrigationManager class for managing irrigation based on sensor data and user input
#include "MoistureSensor.h"
#include "PlantData.h"
#include "WaterLevelSensor.h"
#include "IrrigationManager.h"
#include "WaterPump.h"


// Safety check → Moisture logic → Pump control

void IrrigationManager::automaticIrrigation() 
{
    moistureSensor.moistureLevel();

    MoistureLevel moisture = moistureSensor.getLevel();
    WaterLevel waterLevel = waterLevelSensor.getLevel();

    // FIRST: Safety check
    if (waterLevel == WaterLevel::CRITICAL_LOW) 
    {
        waterPump.PumpOFF();
        Serial.println("WARNING: Water Tank EMPTY!");
        return;   // stop everything
    }

    // SECOND: Moisture logic
    if (moisture == MoistureLevel::DRY) 
    {
        waterPump.PumpON();
        Serial.println("Automatic Irrigation: ON");
    } 
    else 
    {
        waterPump.PumpOFF();
        Serial.println("Automatic Irrigation: OFF");
    }
}

void IrrigationManager::manualIrrigation() 
{
    WaterLevel waterLevel = waterLevelSensor.getLevel();

    if (waterLevel == WaterLevel::CRITICAL_LOW) 
    {
        Serial.println("Manual Irrigation BLOCKED - Tank EMPTY!");
        waterPump.PumpOFF();
        return;
    }

    static bool isPumpOn = false;

    if (isPumpOn) 
    {
        waterPump.PumpOFF();
        Serial.println("Manual Irrigation: OFF");
    } 
    else 
    {
        waterPump.PumpON();
        Serial.println("Manual Irrigation: ON");
    }

    isPumpOn = !isPumpOn;
}