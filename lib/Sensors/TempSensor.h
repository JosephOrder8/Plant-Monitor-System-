#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <Arduino.h>
#pragma once

class TempSensor 
{
public:
    void begin(int pin); 
    int read(); 
private:
int sensorPin; 
};
#endif // TEMPSENSOR_H