#ifndef SERIALDISPLAY_H
#define SERIALDISPLAY_H

#include <Arduino.h>
#pragma once

class SerialDisplay 
{
public:
    void printSerialData(float light, int soil, float temp, float humd);  
private:
int sensorPin; 
};
#endif // SERIALDISPLAY_H