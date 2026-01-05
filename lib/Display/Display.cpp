#include "Display.h"
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(0x27, 16, 2);

void Display::begin() 
{
    lcd.begin(16, 2);
    lcd.clear();
    //lcd.init();
    //lcd.backlight();
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
/*
#include "SerialDisplay.h"
#include "PlantData.h"

void SerialDisplay::printSerialData(float light, int soil, float temp, float humd)
{
    Serial.println("---- Plant Monitor ----");
    
    Serial.print("[LIGHT] " + String(light)+" lux, ");
    Serial.print("[SOIL] " + String(soil)+" %, ");
    Serial.print("[TEMP] " + String(temp)+" F, ");
    Serial.println("[HUM] " + String(humd)+" % ");

    Serial.println("-----------------------");

    delay(3000);
};

void SerialDisplay::showHeader() const {
    Serial.println();
    Serial.println("=== Plant Monitor ===");
    Serial.println("Soil(%)  Temp(C)  Hum(%)  Light");
    Serial.println("-------------------------------------");
}

void SerialDisplay::showSerialData(const PlantData& data)
{
    Serial.print(data.soilMoisture, 1); Serial.print("     ");
    Serial.print(data.temperature, 1);  Serial.print("     ");
    Serial.print(data.humidity, 1);     Serial.print("     ");
    Serial.println(data.lightLevel,1);  
    delay(2000);
}

*/