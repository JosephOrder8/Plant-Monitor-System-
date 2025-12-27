#include <Arduino.h>  // Default Arduino library
#include "LightSensor.h"
#include "TempSensor.h"
#include "MoistureSensor.h"
#include "SerialDisplay.h"
#include "PlantData.h"
#include "Menu.h"

// Create instances of the sensor classes
LightSensor lightsensor;
TempSensor tempsensor;
MoistureSensor moisturesensor;
SerialDisplay display;
PlantData plantData;
Menu menu;

void setup() 
{
  Serial.begin(9600);
  
  lightsensor.begin();
  tempsensor.begin();
  moisturesensor.begin();

  display.showHeader();
  menu.begin();
}

void loop() 
{
  // Read sensors
  float light = lightsensor.read();       // Light 
  float temp = tempsensor.readtemp();     // Tempterature 
  float hum = tempsensor.readhumidity();  // Humidity 
  float moisture = moisturesensor.read(); // Moisture 
  
  // Update plant data
  plantData.lightLevel = light;
  plantData.soilMoisture = moisture;
  plantData.temperature = temp;
  plantData.humidity = hum;

  // Show data on serial display
  display.showSerialData(plantData);
  menu.update();
}

void LCDmenu()
{
  menu.update();

    switch (menu.getState()) 
    {
        case MenuState::LIVE_DATA:
            // display sensors
            break;

        case MenuState::WATER_STATUS:
            // pump / valve info
            break;

        case MenuState::SETTINGS:
            // configuration menu
            break;

        default:
            break;
    }

}