/* 
 * Test code for water level sensor
 * This code is used to test the functionality of the water level sensor and ensure it is working correctly.
 * It will read the water level every 30 seconds and print the value to the serial monitor.
 * Make sure to connect the sensor correctly to the specified pins in pin_config.h.
#include <Arduino.h>
#include <pin_config.h>

#ifdef TEST_MODE

unsigned long waterTimer = 0;
float waterLevel = 0;
float readWaterLevelSensor();

void setup()
{
    Serial.begin(9600);

    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, OUTPUT);
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
}

void loop()
{
    unsigned long now = millis();
    
    if (now - waterTimer > 30000)   // 1 minutes
    {
        waterLevel = readWaterLevelSensor();       // Water Level
        Serial.print("Water Level: ");Serial.print(waterLevel);Serial.println(" cm");
        waterTimer = now;
    }
}

float readWaterLevelSensor() 
{
    // Send a 10 microsecond pulse to trigger the sensor
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, OUTPUT);
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, LOW);
    delayMicroseconds(2);
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
    
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(ArduinoPins::WATER_LEVEL_SENSOR_TRI_PIN, LOW);

    // Read the echo time
    pinMode(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, INPUT);
    float duration = pulseIn(ArduinoPins::WATER_LEVEL_SENSOR_ECHO_PIN, HIGH); // Timeout after 100 ms to prevent blocking

    // Calculate distance in centimeters
    float distance = duration * 0.0343 / 2.0;
    Serial.print("Current Water Level: "+ String(distance) +" cm, Duration: "+ String(duration) + "\n");
    return distance;
}

#endif

*/

/*
#include <Arduino.h>
#include <pin_config.h>

// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;

int offset = 0;
const int ROW_COUNT = 4; // Total number of rows in the menu
int VISIBLE_ROWS = 2; // Number of rows visible at a time

String currentDir = "";
unsigned long lastButtonPress = 0;

void setup() 
{
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  Serial.begin(9600);    // Setup Serial Monitor
  lastStateCLK = digitalRead(CLK);// Read the initial state of CLK
}

void loop() 
{
  currentStateCLK = digitalRead(CLK);  // Read the current state of CLK

  int cursor =0; 
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) 
  {
    // If the DT state is different than the CLK state then the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) 
    {
      counter--;
      //counter = -1;
      currentDir = "CCW";
    } 
    else 
    {
      // Encoder is rotating CW so increment
      counter++;
      //counter = 1;
      currentDir = "CW";
    }

    int newCursor = cursor + counter;

    if (newCursor < 0)
    {
        newCursor = 0; // Clamp to min
        counter = 0; // Reset counter to prevent further negative increments
    }
    else if (newCursor >= ROW_COUNT)
    {
        newCursor = ROW_COUNT - 1; // Clamp to max
        counter = newCursor; // Set counter to max to prevent further increments
    }

    cursor = newCursor;

    if (cursor < offset)
    {
        offset = cursor; // Scroll up
    }
    else if (cursor >= offset + VISIBLE_ROWS)
    {
        offset = cursor - (VISIBLE_ROWS - 1); // Scroll down
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.print(counter);
    Serial.print(" | Cursor: ");
    Serial.print(cursor);
    Serial.print(" | newCursor: ");
    Serial.print(newCursor);
    Serial.print(" | offset: ");
    Serial.println(offset);
  }

  lastStateCLK = currentStateCLK; // Remember last CLK state

  int btnState = digitalRead(SW);  // Read the button state

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) 
  {
    //if 50ms have passed since last LOW pulse, it means that the button has been pressed, released and pressed again
    if (millis() - lastButtonPress > 50) 
    {
      Serial.println("Button pressed!");
    }

    lastButtonPress = millis();  // Remember last button press event
  }

  delay(1);  // Put in a slight delay to help debounce the reading
}

*/