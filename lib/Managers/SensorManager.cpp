// SensorManager.cpp - Implementation of the SensorManager class for managing sensor readings and storing data
#include <Arduino.h>
#include "SensorManager.h"
#include "LightSensor.h"
#include "TempSensor.h"
#include "MoistureSensor.h"
#include "PlantData.h"
#include "WaterLevelSensor.h"

// Sensor instances
LightSensor lightsensor;
TempSensor tempsensor;
MoistureSensor moisturesensor;
WaterLevelSensor waterLvlSensor;
PlantData plantData;

void SensorManager::initializeSensors() 
{
    lightsensor.begin();
    tempsensor.begin();
    moisturesensor.begin();
    waterLvlSensor.begin();
}

void SensorManager::readLiveSensors() 
{
    temp = tempsensor.readtemp();                           // Tempterature
    hum = tempsensor.readhumidity();                        // Humidity 
    light = lightsensor.read();                             // Light
    moisture = moisturesensor.read();                       // Moisture
    TankStatus= waterLvlSensor.waterLevelStatus();        // Water Level
    // delay(500);
    //Serial.print("Temp: ");Serial.print(temp);
    //Serial.print(" °C, Humidity: ");Serial.print(hum);Serial.println(" %");
    //Serial.print("Light Intensity: ");Serial.print(light);Serial.println(" lux");
    //Serial.print("Soil Moisture: ");Serial.print(moisture);Serial.println(" %");
    //Serial.print("Water Level: ");Serial.print(TankStatus);Serial.println(" cm");
}

void SensorManager::recordSensorData() 
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
        waterLevel = waterLvlSensor.read();       // Water Level
        Serial.print("Water Level: ");Serial.print(waterLevel);Serial.println(" cm");
        waterTimer = now;
    }
}

float SensorManager::lightIntensity() const  { return light; }

float SensorManager::temperature() const {  return temp; }

float SensorManager::humidty() const { return hum; }

float SensorManager::soilMoisture() const  { return moisture; }

String SensorManager::TankLevel() const { return TankStatus; }

void SensorManager::storeSensorData() 
{
    plantData.lightLevel = light;
    plantData.soilMoisture = moisture;
    plantData.temperature = temp;
    plantData.humidity = hum;
    plantData.waterLevel = waterLevel;
}