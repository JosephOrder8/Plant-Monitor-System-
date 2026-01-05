#pragma once
#include "Screen.h"
#include "SensorManager.h"

class SensorScreen : public Screen 
{
public:
    SensorScreen(SensorManager& mgr);        // Constructor with SensorManager reference
    void enter() override;                   // Called when entering the sensor screen
    void update() override;                  // Called periodically to update the sensor screen
    void onEncoder(EncoderEvent e) override; // Handle encoder events

private:
    SensorManager& sensorManager;            // Reference to SensorManager
};