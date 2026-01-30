#pragma once
#include <Arduino.h>
#include "ScreenID.h"

struct MenuItem 
{
    const char* label;
    ScreenID screen;
};

class Menu 
{
public:
    void next();
    void prev();
    ScreenID selected() const;
    const char* currentLabel() const;
    
    int selectedIndex() const;
    const MenuItem& item(int index) const;
    int size() const;

private:
    int index = 0;
    static const MenuItem items[];
    static const int count;
};