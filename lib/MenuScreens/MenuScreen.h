#pragma once
#include "Screen.h"
#include "Menu.h"
#include "ScreenManager.h"
#include "Display.h"

class MenuScreen : public Screen 
{
public:
    MenuScreen(Menu& m, ScreenManager& sm, Display& d);

    void enter() override;
    void update() override;
    void onEncoder(EncoderEvent e) override;

private:
    Menu& menu;
    ScreenManager& screenManager;
    Display& display;
};