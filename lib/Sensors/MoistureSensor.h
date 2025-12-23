#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include <Arduino.h>
#pragma once

class MoistureSensor 
{
public:
    void begin(); 
    int read();
    void status(int value); 
private:
int sensorPin; 
};
#endif // MOISTURESENSOR_H