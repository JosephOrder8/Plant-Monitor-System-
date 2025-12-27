#include "SerialDisplay.h"
#include "PlantData.h"

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

void SerialDisplay::showHeader() const {
    Serial.println();
    Serial.println("=== Plant Monitor ===");
    Serial.println("Soil(%)  Temp(C)  Hum(%)  Light");
    Serial.println("-------------------------------------");
}

void SerialDisplay::showSerialData(const PlantData& data)
{
    Serial.print(data.soilMoisture, 1); Serial.print("     ");
    Serial.print(data.temperature, 1);  Serial.print("     ");
    Serial.print(data.humidity, 1);     Serial.print("     ");
    Serial.println(data.lightLevel,1);  
    delay(2000);
}