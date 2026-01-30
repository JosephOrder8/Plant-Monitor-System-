#pragma once
#include "Encoder.h"

class Screen 
{
public:
    virtual void enter() {}
    virtual void update() = 0;
    virtual void exit() {}

    virtual void onEncoderTurn(int dir) {};
    virtual void onEncoderPress() {};
    virtual void onEncoderTurn(EncoderEvent e) {};
    
    virtual ~Screen() = default;
};