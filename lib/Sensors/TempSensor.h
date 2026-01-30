#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <Arduino.h>
#pragma once

class TempSensor 
{
    public:
    void begin(); 
    float readhumidity();
    float readtemp();
    void status(float humd, float temp);
private:
int sensorPin; 
};
#endif // TEMPSENSOR_H