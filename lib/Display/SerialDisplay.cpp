#include "SerialDisplay.h"

void SerialDisplay::printSerialData(float light, int soil, float temp, float humd)
{
    Serial.println("---- Plant Monitor ----");
    
    Serial.print("[LIGHT] " + String(light)+" lux, ");
    Serial.print("[SOIL] " + String(soil)+" %, ");
    Serial.print("[TEMP] " + String(temp)+" F, ");
    Serial.println("[HUM] " + String(humd)+" % ");

    Serial.println("-----------------------");

    delay(3000);
};