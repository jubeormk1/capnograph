#include "display.h"
#if defined(USING_ADAFRUIT_ST7735) || defined(USING_ADAFRUIT_ST7789)
// Only compile this file if we are using this display
#include <Arduino.h>
#include <SPI.h>

#include "sensor.h"


unsigned int samplesPerPixel = 0;
unsigned int samplesReceived = 0;
unsigned int graphOffset = 0;


Adafruit_ST7789 display = 
    Adafruit_ST7789(DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN);


void setupDisplay(void)
{
  display.init(DISPLAY_X_SIZE, DISPLAY_Y_SIZE, SPI_MODE2);// Init ST7789 display
  display.fillScreen(COLOR_BLACK);
  display.enableTearing(false);
  display.setRotation(1);
  display.setCursor(0, 0);
  display.setTextColor(COLOR_MAGENTA);
  display.setTextSize(4);
  display.println("CAPNOGRAPH");
  display.setTextSize(3);
  display.println("     V0.1");
  display.fillScreen(COLOR_BLACK);

}

void setupGraph(void)
{
  Serial.println("setupGraph in... ");
  int totalMsDisplay = 0;
  samplesPerPixel = 0;
  
  int display_y_size = 0;


      display_y_size = DISPLAY_Y_SIZE;

  while (totalMsDisplay<10000)
  {
      totalMsDisplay = sensorSampleTime * ++samplesPerPixel * display_y_size;
  }
  sensorMaxSamples = (display_y_size * samplesPerPixel);

  Serial.print("samplesPerPixel:");
  Serial.println(samplesPerPixel);
  Serial.print("sensorMaxSamples:");
  Serial.println(sensorMaxSamples);
  Serial.print("totalMsDisplay:");
  Serial.println(totalMsDisplay);
  delay(1000);
  Serial.println("Done!");
}


/**
 * @brief  
 * @note   
 * @param  *message: 
 * @retval None
 */
void displayMessage(const char * message)
{

    display.setTextSize(2);
    display.setTextColor(COLOR_YELLOW);
    display.print(message);  

}

/**
 * @brief  Print in the assigned portion of the screen the CO2/1000 ppm
 * @note   
 * @param  CO2: The value of CO2 in ppm
 * @retval None
 */
void printCO2(long CO2)
{
  char formatedMsg[3];
  sprintf(formatedMsg, "%2i", int(CO2/1000)); //XX(2)

    // Compose the string. No longer that 10 characters


    //Clean the needed area
    display.fillRect(0,0,97,40,COLOR_RED);

    display.setCursor(2, 2); // Set the pen in place
    display.setTextSize(2); // Set text size
    display.print("CO"); // Write the message

    display.setCursor(25, 12); // Set the pen in place
    display.setTextSize(1); // Set text size
    display.print("2"); // Write the message

    display.setCursor(40, 2); // Set the pen in place
    display.setTextSize(5); // Set text size
    display.print(formatedMsg); // Write the message  

}

/**
 * @brief  Print in the assigned portion of the screen the Breaths per minute
 * @note   
 * @param  etCO2: The value of etCO2 in percentage (%) 
 * @retval None
 */
void printEtCO2(long etCO2)
{
  // Compose the string. No longer that 10 characters
  char formatedMsg[7];
  sprintf(formatedMsg, "%2i", int(etCO2/1000)); //XX(6)

    //Clean the needed area
    display.fillRect(99, 0, 239, 40, COLOR_ORANGE);

    display.setCursor(101, 2); // Set the pen in place
    display.setTextSize(2); // Set text size
    display.print("etCO"); // Write the message

    display.setCursor(148, 12); // Set the pen in place
    display.setTextSize(1); // Set text size
    display.print("2"); // Write the message

    display.setCursor(180, 2); // Set the pen in place
    display.setTextSize(5); // Set text size
    display.print(formatedMsg); // Write the message

}

/**
 * @brief  Print in the assigned portion of the screen the Breaths per minute
 * @note   
 * @param  bpm: breaths per minutes
 * @retval None
 */
void printBPM(unsigned int bpm)
{
    // Compose the string. No longer that 10 characters
    char formatedMsg[7];
    sprintf(formatedMsg, "%2i", bpm); //BPM XX(6)
    
    //Clean the needed area
    display.fillRect(0, 40, 97, 40, COLOR_BLUE);
    
    
    display.setCursor(2, 42); // Set the pen in place
    display.setTextSize(2); // Set text size
    display.print("BPM"); // Write the message

    display.setCursor(40, 42); // Set the pen in place
    display.setTextSize(5); // Set text size
    display.print(formatedMsg); // Write the message

}

/**
 * @brief  Print in the assigned portion of the screen the state name
 * @note   
 * @param  state: State name as text 
 * @retval None
 */
void printState(const char *state)
{

    //Clean the needed area
    display.fillRect(0, 80, 239, 26, COLOR_MAGENTA);

    display.setCursor(2, 82); // Set the pen in place
    display.setTextSize(3);// Set text size
    display.print(state); // Write the message

}

void printGraph(void)
{
    if(samplesReceived==0)
    {
      //Serial.println(sensorData[dataIndex-1]);
      printCO2(sensorData[dataIndex-1]);
      int plotIndex = 0;

      
      for(int currentLine = (DISPLAY_X_SIZE-1); 
        (currentLine + 1) >= (DISPLAY_X_SIZE-((dataIndex-1)/samplesPerPixel));
        currentLine--)
      {
        long dataToPlot = sensorData[dataIndex-1-plotIndex];
        display.drawLine( currentLine,
                    (DISPLAY_Y_SIZE/2), 
                    currentLine,
                    (DISPLAY_Y_SIZE-1),
                    COLOR_BLACK);
        display.drawLine(currentLine, 
                        map(dataToPlot,
                          0,
                          60000,
                          (DISPLAY_Y_SIZE-1),
                          (DISPLAY_Y_SIZE/2)),
                        currentLine,
                        (DISPLAY_Y_SIZE-1),
                        COLOR_YELLOW);
        plotIndex += samplesPerPixel ;
        /*
        Serial.print(" D D");
        Serial.print(dataIndex-1);
        Serial.print(" L");
        Serial.print(currentLine);
        Serial.print(" P");
        Serial.println(dataIndex-1-(plotIndex-samplesPerPixel));*/
      }
      int invplotIndex = sensorMaxSamples - samplesPerPixel;
      for(int currentInvLine = (DISPLAY_X_SIZE-1)-((dataIndex+samplesPerPixel)/samplesPerPixel); 
        currentInvLine >= 0;
        currentInvLine--)
      {
        long dataInvToPlot = sensorData[invplotIndex];
        display.drawLine( currentInvLine,
                    (DISPLAY_Y_SIZE/2), 
                    currentInvLine,
                    (DISPLAY_Y_SIZE-1),
                    COLOR_BLACK);
        display.drawLine(currentInvLine, 
                        map(dataInvToPlot,
                          0,
                          60000,
                          (DISPLAY_Y_SIZE-1),
                          (DISPLAY_Y_SIZE/2)),
                        currentInvLine,
                        (DISPLAY_Y_SIZE-1),
                        COLOR_YELLOW);
        invplotIndex -= samplesPerPixel;
        /*
        Serial.print("I D");
        Serial.print(dataIndex-1);
        Serial.print(" L");
        Serial.print(currentInvLine);
        Serial.print(" P");
        Serial.println(invplotIndex+samplesPerPixel);*/
      }
      samplesReceived++;
      if(samplesReceived==samplesPerPixel) samplesReceived=0;
    }
    else
    {
      samplesReceived++;
      if(samplesReceived==samplesPerPixel) samplesReceived=0;
    }

}

void displayTest(void)
{
  // define a test
}

#endif // defined USING_ADAFRUIT_ST7735 || defined USING_ADAFRUIT_ST7789