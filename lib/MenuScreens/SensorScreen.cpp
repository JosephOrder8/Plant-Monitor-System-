// SensorScreen.cpp - Implementation of the SensorScreen class for displaying sensor data on a menu screen
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
    sensorManager.readSensors();  // Update sensor readings

    for (int row = 0; row < 2; row++)  // Display 2 rows at a time
    {
        int dataIndex = offset + row;
        if (dataIndex >= ROW_COUNT) 
        {
            break;
        }

        bool selected = (dataIndex == cursor);  // Highlight the selected row

        display.showSensorRow(row,selected,dataIndex,sensorManager); // Render sensor data on the display
    }

}

void SensorScreen::exit() 
{
    Serial.println("Exit SensorScreen");
    cursor = 0;
    display.clear();
}

void SensorScreen::onEncoderPress() 
{
    if (cursor == ROW_COUNT-1) 
    {
        screenManager.set(ScreenID::MENU); // Go back to menu if last row (Back) is selected
    }
    else 
    {
        Serial.print("Pressed: wrong index");
    }
}

void SensorScreen::onEncoderTurn(EncoderEvent e)
{
    int dir = 0;

    if (e == EncoderEvent::CW)  
    {
        //onEncoderTurn(1); // Scroll down
        dir = 1;
    }
    else if (e == EncoderEvent::CCW) 
    {
        //onEncoderTurn(-1); // Scroll up
        dir = -1;
    }

    int newCursor = cursor + dir;

    if (newCursor < 0)
    {
        newCursor = 0; // Clamp to min
    }
    else if (newCursor >= ROW_COUNT)
    {
        newCursor = ROW_COUNT - 1; // Clamp to max
    }

    cursor = newCursor;

    if (cursor < offset)
    {
        offset = cursor; // Scroll up
    }
    else if (cursor >= offset + VISIBLE_ROWS)
    {
        offset = cursor - (VISIBLE_ROWS - 1); // Scroll down
    }

    Serial.print(F("Cursor New Code: "));
    Serial.println(cursor);
}

