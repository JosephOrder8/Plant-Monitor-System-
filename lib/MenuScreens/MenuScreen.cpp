#include "MenuScreen.h"
#include <Arduino.h>

MenuScreen::MenuScreen(Menu& m, ScreenManager& sm, Display& d)
    : menu(m), screenManager(sm), display(d) {}

void MenuScreen::enter() 
{
    Serial.println("== MENU ==");
}

void MenuScreen::update() 
{
    Serial.print("> ");
    Serial.println(menu.currentLabel());
    display.showMenu(menu.currentLabel());
}

void MenuScreen::onEncoder(EncoderEvent e) 
{
    if (e == EncoderEvent::CW) {
        menu.next();
    }
    else if (e == EncoderEvent::CCW) {
        menu.prev();
    }
    else if (e == EncoderEvent::CLICK) {
        screenManager.set(menu.selected());
    }
}