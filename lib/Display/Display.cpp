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

void Display::showMenu(const char* label) 
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> ");
    lcd.print(label);
}

void Display::showSensors(int moisture) 
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moisture:");
    lcd.setCursor(0, 1);
    lcd.print(moisture);
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

    lcd.print(selected ? ">" : " ");

    switch (index) 
    {
        case 0:
            lcd.print("Soil:");
            lcd.print(sensors.soilMoisture());
            lcd.print(" %");
            break;

        case 1:
            lcd.print("Temp:");
            lcd.print(sensors.temperature());
            lcd.print(" C");
            break;

        case 2:
            lcd.print("Hum:");
            lcd.print(sensors.humidty());
            lcd.print(" %");
            break;

        case 3:
            lcd.print("Light:");
            lcd.print(sensors.lightIntensity());
            lcd.print(" lx");
            break;

        case 4:
            lcd.print("Return to Menu");
            break;
    }
}