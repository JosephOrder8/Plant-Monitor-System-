#include "Menu.h"
// #include <LiquidCrystal_I2C.h>

// static LiquidCrystal_I2C lcd(0x27, 16, 2);

void Menu::next() 
{
    index = (index + 1) % count;
}

void Menu::prev() 
{
    index = (index - 1 + count) % count;
}

ScreenID Menu::selected() const 
{
    return items[index].screen;
}

const char* Menu::currentLabel() const 
{
    return items[index].label;
}