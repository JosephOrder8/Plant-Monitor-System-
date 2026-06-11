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
    sensorManager.readLiveSensors();  // Update sensor readings

    for (int row = 0; row < 2; row++)  // Display 2 rows at a time
    {
        int dataIndex = offset + row;
        
        if (dataIndex < ROW_COUNT) 
        {
            bool selected;

            if (dataIndex == cursor)
            {
                selected = true;
            }
            else
            {
                selected = false;
            }

            // Render sensor data on the display
            display.showSensorRow(row, selected, dataIndex, sensorManager); 
        }
        else 
        {
            // NEW: If there is no sensor data for this row, clear it out completely
            display.clearRow(row); 
        }
    }
}

/*
void SensorScreen::update() // Called periodically to update the sensor screen
{
    sensorManager.readLiveSensors();  // Update sensor readings

    for (int row = 0; row < 2; row++)  // Display 2 rows at a time
    {
        int dataIndex = offset + row;
        if (dataIndex >= ROW_COUNT) 
        {
            break;
        }

        // bool selected = (dataIndex == cursor);  // Highlight the selected row

        bool selected;

        if (dataIndex == cursor)
        {
            selected = true;
        }
        else
        {
            selected = false;
        }

        display.showSensorRow(row,selected,dataIndex,sensorManager); // Render sensor data on the display
    }

}
*/


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
    int counter = 0;

    if (e == EncoderEvent::CW)  
    {
        //onEncoderTurn(1); // Scroll down
        counter++;
    }
    else if (e == EncoderEvent::CCW) 
    {
        //onEncoderTurn(-1); // Scroll up
        counter--;
    }

    int newCursor = cursor + counter;

    if (newCursor < 0)
    {
        newCursor = 0; // Clamp to min
        counter = 0;
    }
    else if (newCursor >= ROW_COUNT)
    {
        newCursor = ROW_COUNT - 1; // Clamp to max
        counter = newCursor; // Set counter to max to prevent further increments
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

