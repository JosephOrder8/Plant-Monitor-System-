#ifndef SERIALDISPLAY_H
#define SERIALDISPLAY_H

#pragma once
#include <Arduino.h>
#include "PlantData.h"

class SerialDisplay 
{
public:
    void printSerialData(float light, int soil, float temp, float humd);
    void showSerialData(const PlantData& data);
    void showHeader() const;
private:
int sensorPin; 
};
#endif // SERIALDISPLAY_H