#include "pin_config.h"
#include "Encoder.h"

void Encoder::begin() 
{
    pinMode(ArduinoPins::ENC_CLK_PIN, INPUT_PULLUP); // Encoder clock pin
    pinMode(ArduinoPins::ENC_DT_PIN, INPUT_PULLUP);  // Encoder data pin
    pinMode(ArduinoPins::ENC_SW_PIN, INPUT_PULLUP);  // Encoder switch pin

    lastState = digitalRead(ArduinoPins::ENC_CLK_PIN); // Initial state

    Serial.println("Encoder initialized: " + String(lastState));
}

void Encoder::update() 
{
    readEncoder();
    readButton();
}

void Encoder::readEncoder() 
{
    int currentState = digitalRead(ArduinoPins::ENC_CLK_PIN);

    if (lastState == HIGH && currentState == LOW) 
    {
        if(millis() - lastMoveTime > 4)
        {
            if (digitalRead(ArduinoPins::ENC_DT_PIN) == HIGH ) 
            {
                event = EncoderEvent::CCW; 
                Serial.println("Encoder CCW");
            } 
            else 
            {
                event = EncoderEvent::CW;
                Serial.println("Encoder CW");
            }
            lastMoveTime = millis();
        } 
    
    }
    lastState = currentState;
}

void Encoder::readButton() 
{
    int btnState = digitalRead(ArduinoPins::ENC_SW_PIN);

    if (btnState == LOW) 
    {
        if (millis() - lastButtonPress > 50) 
        {
            event = EncoderEvent::CLICK;             // Click
            Serial.println("Button Clicked");
        }
        lastButtonPress = millis(); // Update press time
    } 
}

EncoderEvent Encoder::getEvent() 
{
    EncoderEvent e = event;
    event = EncoderEvent::NONE;
    return e;
}

/*
void Encoder::readEncoder() 
{
    int currentState = digitalRead(ArduinoPins::ENC_CLK_PIN);

    if (currentState != lastState && currentState == 1) 
    {
        if (digitalRead(ArduinoPins::ENC_DT_PIN) != currentState ) 
        {
            event = EncoderEvent::CW; 
        } 
        else 
        {
            event = EncoderEvent::CCW;
        }
    }
    lastState = currentState;
}
*/

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
