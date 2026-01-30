#include "pin_config.h"
#include "Encoder.h"

void Encoder::begin() 
{
    pinMode(ArduinoPins::ENC_CLK_PIN, INPUT);        // Encoder clock pin
    pinMode(ArduinoPins::ENC_DT_PIN, INPUT);         // Encoder data pin
    pinMode(ArduinoPins::ENC_SW_PIN, INPUT_PULLUP);  // Encoder switch pin

    lastState = digitalRead(ArduinoPins::ENC_CLK_PIN); // Initial state

}

void Encoder::update() 
{
    // readEncoder();
    // readButton();
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
            event = EncoderEvent::PRESS;             // Click
            Serial.println("Button Clicked");
        }
        lastButtonPress = millis(); // Update press time
    } 
}

EncoderEvent Encoder::getEvent() 
{   
    static bool initialized = false;
    static bool clkInitialized = false;

    static int lastCLK;
    static bool lastBtn;
    static unsigned long lastBtnTime = 0;

// Rotation detection
    int clk = digitalRead(ArduinoPins::ENC_CLK_PIN);
    
    if (!clkInitialized) 
    {
        lastCLK = clk;
        clkInitialized = true;
    }

    if (clk != lastCLK)  // A change occurred
    { 
        delay(2); // Debounce delay
        if (clk == LOW)  // Falling edge detected
        {
             // Check DT pin for direction
            if (digitalRead(ArduinoPins::ENC_DT_PIN) == clk)  
            {
                Serial.println("Encoder: CW");
                return EncoderEvent::CW;
            }
            else
            {
                Serial.println("Encoder: CCW");
                return EncoderEvent::CCW;
            }
        }
    }
    lastCLK = clk;

// Button detection

    bool btn = digitalRead(ArduinoPins::ENC_SW_PIN);

    if (!initialized)
    {
        lastBtn = btn;
        lastBtnTime = millis();
        initialized = true;
        return EncoderEvent::NONE;
    }

    if (btn != lastBtn)
    {
        lastBtnTime = millis();
    }

    if (lastBtn == HIGH && btn == LOW)
    {
        lastBtn = btn;
        Serial.println("Encoder: Btn PRESS");
        return EncoderEvent::PRESS;
    }

    lastBtn = btn;
    return EncoderEvent::NONE;
}