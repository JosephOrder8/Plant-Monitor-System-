#include "SensorScreen.h"
#include <Arduino.h>
#include "ScreenManager.h"

SensorScreen::SensorScreen(SensorManager& mgr, Display& disp, ScreenManager& sm) 
             : sensorManager(mgr), 
               display(disp), 
               screenManager(sm) {}  // Constructor with SensorManager reference

void SensorScreen::enter() // Called when entering the sensor screen
{
    display.clear();
    Serial.println("Enter SensorScreen");
}

void SensorScreen::update() // Called periodically to update the sensor screen
{
    sensorManager.readSensors();

    for (int row = 0; row < 2; row++) 
    {
        int dataIndex = offset + row;
        if (dataIndex >= ROW_COUNT) break;

        bool selected = (dataIndex == cursor);

        display.showSensorRow(
            row,
            selected,
            dataIndex,
            sensorManager
        );
    }

}

void SensorScreen::exit() 
{
    Serial.println("Exit SensorScreen");
    cursor = 0;
    display.clear();
}

void SensorScreen::onEncoderTurn(int dir) // Handle encoder turn events
{
    cursor += dir;
    
    // Clamp to min and max
    if (cursor < 0)                       
    {
        cursor = 0;   // Clamp to min
    }

    if (cursor >= ROW_COUNT)              
    {
        cursor = ROW_COUNT - 1;  // Clamp to max
    }
    // Scroll window: Scroll up or down as needed
    if (cursor < offset)            
    {
        offset = cursor;  //Scroll up
    }

    if (cursor >= offset + 2) 
    {
        offset = cursor - 1;   // Scroll down
    }    
    
    Serial.println("Cursor: "+ String(cursor));
}

void SensorScreen::onEncoderPress() 
{
    if (cursor == ROW_COUNT-1) 
    {
        screenManager.set(ScreenID::MENU);
    }
    else 
    {
        Serial.print("Pressed: wrong index");
    }
}

void SensorScreen::onEncoderTurn(EncoderEvent e)
{
    if (e == EncoderEvent::CW)  
    {
        onEncoderTurn(1);
    }
    else if (e == EncoderEvent::CCW) 
    {
        onEncoderTurn(-1);
    }
}

