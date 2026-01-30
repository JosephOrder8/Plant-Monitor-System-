#include "LightSensor.h"
#include "TempSensor.h"
#include "MoistureSensor.h"
#include "PlantData.h"
#include "SensorManager.h"

// Create instances of the sensor classes
LightSensor lightsensor;
TempSensor tempsensor;
MoistureSensor moisturesensor;
PlantData plantData;

static unsigned long lastUpdate = 0;
const unsigned long updateInterval = 500; // ms

void SensorManager::initializeSensors() 
{
    lightsensor.begin();
    tempsensor.begin();
    moisturesensor.begin();
}

void SensorManager::readSensors() 
{
    unsigned long now = millis();
    if (now - lastUpdate < updateInterval)
    return; // too soon → skip update
    lastUpdate = now;

    light = lightsensor.read();       // Light 
    temp = tempsensor.readtemp();     // Tempterature 
    hum = tempsensor.readhumidity();  // Humidity 
    moisture = moisturesensor.read(); // Moisture 
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

void SensorManager::storeSensorData() 
{
    plantData.lightLevel = light;
    plantData.soilMoisture = moisture;
    plantData.temperature = temp;
    plantData.humidity = hum;
}