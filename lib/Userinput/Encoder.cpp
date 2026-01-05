#include "pin_config.h"
#include "Encoder.h"

void Encoder::begin() 
{
    pinMode(ArduinoPins::ENC_CLK_PIN, INPUT_PULLUP); // Encoder clock pin
    pinMode(ArduinoPins::ENC_DT_PIN, INPUT_PULLUP);  // Encoder data pin
    pinMode(ArduinoPins::ENC_SW_PIN, INPUT_PULLUP);  // Encoder switch pin

    lastState = digitalRead(ArduinoPins::ENC_CLK_PIN); // Initial state
}

void Encoder::update() 
{
    readEncoder();
    readButton();
}

void Encoder::readEncoder() 
{
    int currentState = digitalRead(ArduinoPins::ENC_CLK_PIN);
    if (currentState != lastState) 
    {
        if (digitalRead(ArduinoPins::ENC_DT_PIN) != currentState) 
        {
            event = EncoderEvent::CW; // Clockwise
        } else {
            event = EncoderEvent::CCW; // Counter-clockwise
        }
    }
     lastState = currentState;
}

void Encoder::readButton() 
{
    if (!digitalRead(ArduinoPins::ENC_SW_PIN)) 
    {
        static unsigned long buttonPressTime = 0;
        if (buttonPressTime == 0) 
        {
            buttonPressTime = millis();
        } 
        else if (millis() - buttonPressTime > 1000) 
        {
            event = EncoderEvent::LONG_CLICK; // Long click
            buttonPressTime = 0; // Reset
        }
    } 
    else 
    {
        static unsigned long buttonPressTime = 0;
        if (buttonPressTime != 0 && millis() - buttonPressTime < 1000) 
        {
            event = EncoderEvent::CLICK; // Short click
        }
        buttonPressTime = 0; // Reset
    }
}

EncoderEvent Encoder::getEvent() 
{
    EncoderEvent e = event;
    event = EncoderEvent::NONE;
    return e;
}

/*
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
        cursor = constrain(cursor, 0, 6); // Assuming 7 menu items (0-6)
        Serial.println("Rotate: "+ String(cursor));
        updateMenu();
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

*/
