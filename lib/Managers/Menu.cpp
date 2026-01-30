#include "Menu.h"
#include "MenuScreen.h"

const MenuItem Menu::items[] = 
{
    {"LiveData", ScreenID::LIVE_DATA},
    {"Irrigation", ScreenID::IRRIGATION},
    {"Power", ScreenID::POWER},
    {"Settings", ScreenID::SETTINGS}
};

const int Menu::count = 4;  // Total number of menu items

void Menu::next()    // Move to the next menu item
{
    if (index < count - 1)    // Prevent overflow
    {
        index++;
    }
    Serial.println("Menu next: "+ String(index));
}

void Menu::prev()    // Move to the previous menu item
{
    if (index > 0)  // Prevent underflow
    {
        index--;
    }
    Serial.println("Menu previous: "+ String(index));
}

ScreenID Menu::selected() const
{
    return items[index].screen;   // Return the ScreenID of the currently selected menu item
}

const char* Menu::currentLabel() const 
{
    return items[index].label;   // Return the label of the currently selected menu item
}

int Menu::selectedIndex() const
{
    return index;                // Return the current index
}

const MenuItem& Menu::item(int i) const
{
    return items[i];            // Return the MenuItem at index i
}

int Menu::size() const 
{
    return count;              // Return the total number of menu items
}