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

void SensorManager::initializeSensors() 
{
    lightsensor.begin();
    tempsensor.begin();
    moisturesensor.begin();
}

void SensorManager::readSensors() 
{
    float light = lightsensor.read();       // Light 
    float temp = tempsensor.readtemp();     // Tempterature 
    float hum = tempsensor.readhumidity();  // Humidity 
    float moisture = moisturesensor.read(); // Moisture 

    // Update plant data
    plantData.lightLevel = light;
    plantData.soilMoisture = moisture;
    plantData.temperature = temp;
    plantData.humidity = hum;

    // For demonstration, return soil moisture as an integer percentage
    // return static_cast<int>(moisture);
}

void SensorManager::displaySensorData(const PlantData& data) 
{
    // Display or log the sensor data
}