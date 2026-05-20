// Encoder.cpp - Implementation of the Encoder class for handling rotary encoder input
#include "pin_config.h"
#include "Encoder.h"

void Encoder::begin() 
{
    pinMode(ArduinoPins::ENC_CLK_PIN, INPUT_PULLUP);        // Encoder clock pin
    pinMode(ArduinoPins::ENC_DT_PIN, INPUT_PULLUP);         // Encoder data pin
    pinMode(ArduinoPins::ENC_SW_PIN, INPUT_PULLUP);         // Encoder switch pin

    lastStateCLK = digitalRead(ArduinoPins::ENC_CLK_PIN);   // Initial state of CLK
}

void Encoder::update() 
{
    // This function can be used to perform any necessary updates, but in this implementation, getEvent() handles everything.
}

EncoderEvent Encoder::getEvent() 
{   
    static bool initialized = false;
    static bool lastBtn;
    static unsigned long lastBtnTime = 0;

// Rotation detection
    int currentstateclk = digitalRead(ArduinoPins::ENC_CLK_PIN);
    
    // If last and current state of CLK are different, then pulse occurred. React to only 1 state change to avoid double count
    if (currentstateclk != lastStateCLK && currentstateclk == HIGH) 
    {
      // If the DT state is different than the CLK state then the encoder is rotating CCW so decrement
      if (digitalRead(ArduinoPins::ENC_DT_PIN) != currentstateclk) 
      {
        Serial.println("Encoder.cpp Trigger: CCW");
        lastStateCLK = currentstateclk;
        return EncoderEvent::CCW;
      } 
      else 
      {
        Serial.println("Encoder.cpp Trigger: CW");
        lastStateCLK = currentstateclk;
        return EncoderEvent::CW;
      }
    }
    lastStateCLK = currentstateclk;

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

    delay(1); // Small delay to debounce
    return EncoderEvent::NONE;
}