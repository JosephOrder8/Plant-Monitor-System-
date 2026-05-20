// SensorManager.cpp - Implementation of the SensorManager class for managing sensor readings and storing data
#include "LightSensor.h"
#include "TempSensor.h"
#include "MoistureSensor.h"
#include "PlantData.h"
#include "SensorManager.h"
#include "WaterLevelSensor.h"

// Create instances of the sensor classes
LightSensor lightsensor;
TempSensor tempsensor;
MoistureSensor moisturesensor;
WaterLevelSensor waterLevelSensor;
PlantData plantData;

// unsigned long lastUpdate = 0;
unsigned long updateInterval = 500; // ms

unsigned long tempTimer = 0;
unsigned long lightTimer = 0;
unsigned long moistureTimer = 0;
unsigned long waterTimer = 0;

void SensorManager::initializeSensors() 
{
    lightsensor.begin();
    tempsensor.begin();
    moisturesensor.begin();
    waterLevelSensor.begin();
}

void SensorManager::readSensors() 
{
    unsigned long now = millis();

    if (now - tempTimer > 30000)   // 30 seconds
    {
        temp = tempsensor.readtemp();               // Tempterature
        hum = tempsensor.readhumidity();            // Humidity 
        Serial.print("Temp: ");Serial.print(temp);
        Serial.print(" °C, Humidity: ");Serial.print(hum);Serial.println(" %");
        tempTimer = now;
    }

    if (now - lightTimer > 30000)  // 30 seconds
    {
        light = lightsensor.read();                 // Light
        Serial.print("Light Intensity: ");Serial.print(light);Serial.println(" lux");
        lightTimer = now;
    }

    if (now - moistureTimer > 30000)  // 30 seconds
    {
        moisture = moisturesensor.read();           // Moisture
        Serial.print("Soil Moisture: ");Serial.print(moisture);Serial.println(" %");
        moistureTimer = now;
    }

    if (now - waterTimer > 69000)   // 1 minutes
    {
        waterLevel = waterLevelSensor.read();       // Water Level
        Serial.print("Water Level: ");Serial.print(waterLevel);Serial.println(" cm");
        waterTimer = now;
    }
}

float SensorManager::lightIntensity() const 
{
    return light;
}

float SensorManager::temperature() const 
{
    return temp;
}

float SensorManager::humidty() const 
{
    return hum;
}

float SensorManager::soilMoisture() const 
{
    return moisture;
}

float SensorManager::TankLevel() const 
{
    return waterLevel;
}

void SensorManager::storeSensorData() 
{
    plantData.lightLevel = light;
    plantData.soilMoisture = moisture;
    plantData.temperature = temp;
    plantData.humidity = hum;
    plantData.waterLevel = waterLevel;
}