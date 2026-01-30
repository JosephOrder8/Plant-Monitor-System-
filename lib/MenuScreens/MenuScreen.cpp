#include "MenuScreen.h"
#include <Arduino.h>
#include "ScreenManager.h"
#include "Menu.h"
#include "Encoder.h"

MenuScreen::MenuScreen(Menu& m, ScreenManager& sm, Display& d)
    : menu(m), screenManager(sm), display(d) {}

void MenuScreen::enter() 
{
    display.clear();
    topIndex = 0;
    Serial.println("Enter Menu Screen");
}

void MenuScreen::update() 
{
    int selected = menu.selectedIndex();

    // Scroll window if needed
    if (selected < topIndex) 
    {
        topIndex = selected;
    }
    else if (selected >= topIndex + ROWS) 
    {
        topIndex = selected - ROWS + 1;
    }

    // Draw visible rows
    for (int row = 0; row < ROWS; row++) 
    {
        int itemIndex = topIndex + row;

        if (itemIndex < menu.size()) 
        {
            display.drawMenuRow(row,itemIndex == selected,menu.item(itemIndex).label);
        }
    }
}

void MenuScreen::exit() 
{
     Serial.println("Exit MenuScreen");// No special exit actions needed for MenuScreen
     display.clear();
}

void MenuScreen::onEncoderTurn(EncoderEvent e)
{
    if (e == EncoderEvent::CW)  
    {
        menu.next();
    }
    else if (e == EncoderEvent::CCW) 
    {
        menu.prev();
    }
}

void MenuScreen::onEncoderPress()
{
    screenManager.set(menu.selected());
    Serial.println("Menu select");
}