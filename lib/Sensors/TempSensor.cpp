#include "TempSensor.h"
#include <pin_config.h>
#include <DHT.h>

DHT dht11(ArduinoPins::TEMP_SENSOR_PIN, DHT11); // Initialize globalDHT11 sensor on pin 

void TempSensor::begin() 
{
    dht11.begin(); 
}

float TempSensor::readhumidity() 
{
    float humidity = dht11.readHumidity(); 
    return humidity;
}

float TempSensor::readtemp() 
{
    float temp = dht11.readTemperature(); 
    return temp;
}

void TempSensor::status(float humd, float temp)
{
    if ( isnan(humd) || isnan(temp))    // check whether the reading is successful or not
    {
        Serial.println("Failed to read from DHT11 sensor!");
    } 
    else 
    {
        Serial.println("Humidity: " + String(humd) + "%  |  Temperature: " + String(temp) + "°C");
    }
  
    delay(2000);
}