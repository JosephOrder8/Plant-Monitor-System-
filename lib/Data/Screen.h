#pragma once
#include "Encoder.h"

class Screen 
{
public:
    virtual void enter() {}
    virtual void update() = 0;
    virtual void onEncoder(EncoderEvent e) = 0;
    virtual void exit() {}
    virtual ~Screen() = default;
};