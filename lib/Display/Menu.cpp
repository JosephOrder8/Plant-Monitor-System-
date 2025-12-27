#include "Menu.h"
#include <LiquidCrystal_I2C.h>
#include "pin_config.h"

static LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lastButtonPress = 0;

void Menu::begin() 
{
    pinMode(ArduinoPins::ENC_CLK_PIN, INPUT_PULLUP);
    pinMode(ArduinoPins::ENC_DT_PIN, INPUT_PULLUP);
    pinMode(ArduinoPins::ENC_SW_PIN, INPUT_PULLUP);
    
    lcd.init();
    lcd.backlight();
    
    lastClkState = digitalRead(ArduinoPins::ENC_CLK_PIN);
    drawMenu();
}

void Menu::update() 
{
    readEncoder();
    readButton();
}

MenuState Menu::getState() const 
{
    return currentState;
}

void Menu::readEncoder() 
{
int clkState = digitalRead(ArduinoPins::ENC_CLK_PIN);

     if (clkState != lastClkState) 
     {
        if (digitalRead(ArduinoPins::ENC_DT_PIN) != clkState) 
        {
            cursor++;
        } else {
            cursor--;
        }
        cursor = constrain(cursor, 0, 2);
        drawMenu();
    }

    lastClkState = clkState;
}

void Menu::readButton() 
{
    if (!digitalRead(ArduinoPins::ENC_SW_PIN)) 
    {
        if (millis() - lastButtonPress > 300) {
            currentState = static_cast<MenuState>(cursor + 1);
            lastButtonPress = millis();
        }
    }
}

void Menu::drawMenu() 
{
   lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(cursor == 0 ? "> Live Data" : "  Live Data");

    lcd.setCursor(0, 1);
    lcd.print(cursor == 1 ? "> Water" : "  Water");
}