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

void renderSensorData() // Render sensor data on the display
{
    
}

void SensorScreen::onEncoderTurn(int dir) // Handle encoder turn events
{
    cursor += dir;

    if (cursor < 0) cursor = 0;                      // Clamp to min
    if (cursor >= ROW_COUNT) cursor = ROW_COUNT - 1; // Clamp to max

    // Scroll window
    if (cursor < offset) offset = cursor;            // Scroll up
    if (cursor >= offset + 2) offset = cursor - 1;   // Scroll down
    Serial.print("Cursor: ");
    Serial.print(cursor);
}

void SensorScreen::onEncoder(EncoderEvent e) // Handle encoder events
{
    if (e == EncoderEvent::CW) 
    {
        // menu.next();                        // Move to next menu item
        // Serial.println("Menu next: Clockwise");
    }
    else if (e == EncoderEvent::CCW) 
    {
        // menu.prev();                        // Move to previous menu item
        // Serial.println("Menu previous: Counter-Clockwise");
    }
    else if (e == EncoderEvent::PRESS) 
    {
        // screenManager.set(menu.selected()); // Switch to selected screen
        // screenManager.set(menu.item(menu.selectedIndex()).screen);
        // Serial.println("Menu select");
    }
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
    
    if (e == EncoderEvent::CCW) 
    {
        onEncoderTurn(-1);
    }
}

void SensorScreen::exit() 
{
    Serial.println("Exit SensorScreen");
    cursor = 0;
    display.clear();
}
