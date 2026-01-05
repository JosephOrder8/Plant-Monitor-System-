#include "SensorScreen.h"
#include <Arduino.h>
// #include "Encoder.h"

SensorScreen::SensorScreen(SensorManager& mgr): sensorManager(mgr) {}  // Constructor with SensorManager reference

void SensorScreen::onEncoder(EncoderEvent e) // Handle encoder events
{
    if (e == EncoderEvent::CLICK) 
    {
        Serial.println("Encoder clicked on Sensor Screen");
    }
}

void SensorScreen::enter() // Called when entering the sensor screen
{
    Serial.println("Sensor Screen");
}

void SensorScreen::update() // Called periodically to update the sensor screen
{
    // sensorManager.readSensors();
    // sensorManager.displaySensorData();
}
