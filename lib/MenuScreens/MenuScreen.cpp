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

void MenuScreen::onEncoder(EncoderEvent e) 
{
    if (e == EncoderEvent::CW) 
    {
        //menu.next();                        // Move to next menu item
        // Serial.println("Menu next: Clockwise");
    }
    else if (e == EncoderEvent::CCW) 
    {
        //menu.prev();                        // Move to previous menu item
        // Serial.println("Menu previous: Counter-Clockwise");
    }
    else if (e == EncoderEvent::PRESS) 
    {
        //screenManager.set(menu.selected()); // Switch to selected screen
        // screenManager.set(menu.item(menu.selectedIndex()).screen);
        //Serial.println("Menu select");
    }
}

void MenuScreen::onEncoderTurn(EncoderEvent e)
{
    if (e == EncoderEvent::CW)  
    {
        menu.next();
        Serial.println("Menu next: CW");
    }
    if (e == EncoderEvent::CCW) 
    {
        menu.prev();
        Serial.println("Menu previous: CCW");
    }
}

void MenuScreen::onEncoderPress()
{
    screenManager.set(menu.selected());
    Serial.println("Menu select");
}