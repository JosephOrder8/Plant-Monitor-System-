#include "ScreenManager.h"

void ScreenManager::registerScreen(ScreenID id, Screen* screen) // Register a screen with an ID
{
    screens[(int)id] = screen;
}

void ScreenManager::set(ScreenID id) // Switch to a specific screen
{
    if (current) current->exit();     // Exit current screen
    current = screens[(int)id];       // Set new screen
    if (current) current->enter();    // Enter new screen
}

void ScreenManager::update() // Update the current screen
{
    if (current) current->update();
}

void ScreenManager::handleEncoder(EncoderEvent e) // Handle encoder events
{
    if (current) current->onEncoder(e);
}