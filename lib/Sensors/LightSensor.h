#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>
#pragma once

class LightSensor 
{
public:
    void begin(); 
    int read();
    void status(int value); 
private:
int sensorPin; 
};
#endif // LIGHTSENSOR_H