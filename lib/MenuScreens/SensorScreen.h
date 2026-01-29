#pragma once
#include "Screen.h"
#include "SensorManager.h"
#include "Display.h"
#include "ScreenManager.h"

class SensorScreen : public Screen 
{
public:
    SensorScreen(SensorManager& mgr, Display& disp, ScreenManager& sm);        // Constructor with SensorManager reference

    void enter() override;                                                     // Called when entering the sensor screen
    void update() override;                                                    // Called periodically to update the sensor screen                                                  // Render sensor data on the display
    void onEncoderTurn(EncoderEvent e) override;                               // Handle encoder turn events
    void onEncoderPress() override;                                           // Handle encoder press events
    void exit() override;                                                     // Called when exiting the sensor screen      

private:
    SensorManager& sensorManager;            // Reference to SensorManager
    Display& display;                        // Reference to Display
    ScreenManager& screenManager;            // Reference to ScreenManager

    void onEncoderTurn(int dir);          // Handle encoder turn events
    static const int ROW_COUNT = 5;
    int cursor = 0;
    int offset = 0;
};