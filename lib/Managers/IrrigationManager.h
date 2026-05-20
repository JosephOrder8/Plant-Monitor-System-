#include "MoistureSensor.h"
#include "PlantData.h"
#include "WaterLevelSensor.h"
#include "WaterPump.h"

class IrrigationManager 
{       
public:
    void manageIrrigation();
    void automaticIrrigation();
    void manualIrrigation();

private:
    MoistureSensor moistureSensor;
    WaterLevelSensor waterLevelSensor;
    WaterPump waterPump;
};