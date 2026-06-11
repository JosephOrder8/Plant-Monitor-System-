// Display.cpp - Implementation of the Display class for managing the LCD display and showing sensor data and menu options
#include "Display.h"
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(0x27, 16, 2);

void Display::begin() 
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Plant Monitor");
    lcd.setCursor(0, 1);
    lcd.print("System V1.0");
    Serial.println("Plant Monitor System V1.0");
    delay(3000); // Show welcome message for 3 seconds
}

void Display::clear() 
{
    lcd.clear();
}

void Display::clearRow(int lcdRow) 
{
    lcd.setCursor(0, lcdRow);
    // Print 16 spaces to completely wipe the row
    lcd.print("                "); 
}

void Display::showMenu(const char* label) 
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> ");
    lcd.print(label);
}

void Display::drawMenuRow(uint8_t row, bool selected, const char* label) 
{
    lcd.setCursor(0, row);
    lcd.print(selected ? '>' : ' ');
    lcd.print(label);

    // Clear remaining characters
    int len = strlen(label);
    for (int i = len + 1; i < COLS; i++) 
    {
        lcd.print(' ');
    }
}

void Display::showSensorRow(int lcdRow, bool selected, int index, SensorManager& sensors) 
{
    lcd.setCursor(0, lcdRow);

    if (selected)
    {
        lcd.print(">");
    }
    else
    {
        lcd.print(" ");
    }

    int charsPrinted = 1; // Count the ">" or " "

    switch (index) 
    {
        case 0:
            charsPrinted += lcd.print("Light:");
            charsPrinted += lcd.print(sensors.lightIntensity());
            charsPrinted += lcd.print("lx");
            break;

        case 1:
            charsPrinted += lcd.print("Soil:");
            charsPrinted += lcd.print(sensors.soilMoisture());
            charsPrinted += lcd.print("%");
            break;

        case 2:
            charsPrinted += lcd.print("Temp:");
            charsPrinted += lcd.print(sensors.temperature());
            charsPrinted += lcd.print("C");
            break;

        case 3:
            charsPrinted += lcd.print("Hum:");
            charsPrinted += lcd.print(sensors.humidty());
            charsPrinted += lcd.print("%");
            break;

        case 4:
            {
                // FIX: Save the text to a String first so we can measure its exact length
                String tankStatus = sensors.TankLevel(); 
                charsPrinted += lcd.print("Water:");
                charsPrinted += lcd.print(tankStatus);
                charsPrinted += tankStatus.length(); 
            }
            break;

        case 5:
            charsPrinted += lcd.print("Return to Menu");
            break;
    }

    // Erase any old characters left over on a 16-column display
    int totalColumns = 16; 
    for (int i = charsPrinted; i < totalColumns; i++) 
    {
        lcd.print(" ");
    }
}

/*
void Display::showSensorRow(int lcdRow, bool selected, int index, SensorManager& sensors) 
{
    lcd.setCursor(0, lcdRow);

    // lcd.print(selected ? ">" : " ");

    if (selected)
    {
        lcd.print(">");
    }
    else
    {
        lcd.print(" ");
    }

    switch (index) 
    {
        case 0:
            lcd.print("Light:");
            lcd.print(sensors.lightIntensity());
            lcd.print("lx");
            break;

        case 1:
            lcd.print("Soil:");
            lcd.print(sensors.soilMoisture());
            lcd.print("%");
            break;

        case 2:
            lcd.print("Temp:");
            lcd.print(sensors.temperature());
            lcd.print("C");
            break;

        case 3:
            lcd.print("Hum:");
            lcd.print(sensors.humidty());
            lcd.print("%");
            break;
        case 4:
            lcd.print("Water:");
            lcd.print(sensors.TankLevel());
            lcd.print("");
            break;
        case 5:
            lcd.print("Return to Menu");
            break;
    }
}
*/