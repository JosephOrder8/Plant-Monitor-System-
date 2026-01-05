#pragma once
#include <stdint.h>

enum class EncoderEvent 
{
    NONE,
    CW,
    CCW,
    CLICK,
    LONG_CLICK
};

class Encoder 
{
public:
    void begin();                 // initialize pins
    void update();                // called every loop
    void readEncoder();           // read encoder rotation
    void readButton();            // read button press
    EncoderEvent getEvent();      // returns one-shot event

private:
    int lastState;                // last state of CLK pin
    EncoderEvent event = EncoderEvent::NONE;  // current event
};