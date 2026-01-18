#pragma once
#include "Screen.h"
#include "Menu.h"
#include "ScreenManager.h"
#include "Display.h"
#include "Encoder.h"

class MenuScreen : public Screen 
{
public:
    MenuScreen(Menu& m, ScreenManager& sm, Display& d);

    void enter() override;
    void update() override;
    void onEncoder(EncoderEvent e) override;
    void exit() override;

private:
    Menu& menu;
    ScreenManager& screenManager;
    Display& display;
    
    int topIndex = 0;                // first visible item
    static constexpr int ROWS = 2;   // number of visible rows
};