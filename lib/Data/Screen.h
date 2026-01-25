#pragma once
#include "Encoder.h"

class Screen 
{
public:
    virtual void enter() {}
    virtual void update() = 0;
    virtual void onEncoder(EncoderEvent e);
    
    virtual void onEncoderTurn(int dir) {};
    virtual void onEncoderPress() {};
    virtual void onEncoderTurn(EncoderEvent e) {};
    
    virtual void exit() {}
    virtual ~Screen() = default;
};