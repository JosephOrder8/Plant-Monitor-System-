#pragma once
#include <stdint.h>

enum class EncoderEvent 
{
    NONE,
    CW,
    CCW,
    PRESS
};

class Encoder 
{
public:
    void begin();                 // initialize pins
    void update();                // called every loop
    EncoderEvent getEvent();      // returns one-shot event

private:
    int lastStateCLK;                            // last state of CLK pin
    EncoderEvent event = EncoderEvent::NONE;  // current event
    unsigned long lastButtonPress = 0;        // time when button was pressed
    unsigned long lastMoveTime = 0;           // time of last encoder move
};