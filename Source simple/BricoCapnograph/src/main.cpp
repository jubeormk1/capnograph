#include <Arduino.h>
#include "main.h"
#include "sensor.h"
#include "display.h"
#include "analysis.h"

void setup()
{
  Serial.begin(115200);
  setupDisplay();
  //setupSprintIR();
  setupGraph();
  memset(sensorData, 0, sizeof(sensorData));
  dataIndex=0;
}

void loop()
{
  displayTest();
  //parseSprintIR();
  //analyzeData();
  //printGraph();
}