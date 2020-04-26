#include <Arduino.h>

#include <SPI.h>

#include "display.h"
#include "sensor.h"
#include "main.h"

unsigned int samplesPerPixel = 0;
unsigned int samplesReceived = 0;
unsigned int graphOffset = 0;


#ifdef  USING_TFT_22_ILI9225
//Julio's test
    SPIClass spi_in_use(SPI_IN_USE);

    TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST,
                                    TFT_RS,
                                    TFT_CS, 
                                    TFT_LED, 
                                    TFT_BRIGHTNESS);

#else
Adafruit_ST7789 display = 
    Adafruit_ST7789(DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN);

#endif

void setupDisplay(void)
{
  #ifdef  USING_TFT_22_ILI9225
  spi_in_use.begin();
  tft.begin(spi_in_use);
  tft.setDisplay(true);
  tft.clear();
  Serial.println("setupDisplay Done");
  #else
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
  #endif
}

void setupGraph(void)
{
  Serial.println("setupGraph in... ");
  int totalMsDisplay = 0;
  samplesPerPixel = 0;
  
  int display_y_size = 0;

  #ifdef  USING_TFT_22_ILI9225
      display_y_size = tft.maxY();
      sensorSampleTime = 100; // ugly fix for testing
  #else
      display_y_size = DISPLAY_Y_SIZE;
  #endif
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
  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, message, COLOR_YELLOW);
  #else
    display.setTextSize(2);
    display.setTextColor(COLOR_YELLOW);
    display.print(message);  
  #endif

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

  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, "define me", COLOR_YELLOW);
  #else
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
  #endif

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

  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, "define me", COLOR_YELLOW);
  #else 
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
  #endif
}

/**
 * @brief  Print in the assigned portion of the screen the Breaths per minute
 * @note   
 * @param  bpm: breaths per minutes
 * @retval None
 */
void printBPM(unsigned int bpm)
{
  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, "define printBPM", COLOR_YELLOW);
  #else
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
  #endif
}

/**
 * @brief  Print in the assigned portion of the screen the state name
 * @note   
 * @param  state: State name as text 
 * @retval None
 */
void printState(const char *state)
{
  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, "define printState", COLOR_YELLOW);
  #else
    //Clean the needed area
    display.fillRect(0, 80, 239, 26, COLOR_MAGENTA);

    display.setCursor(2, 82); // Set the pen in place
    display.setTextSize(3);// Set text size
    display.print(state); // Write the message
  #endif
}

void printGraph(void)
{
  #ifdef  USING_TFT_22_ILI9225
    tft.setFont(Terminal6x8);
    tft.drawText(10, 70, "define printGraph", COLOR_YELLOW);
  #else

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
  #endif

}

void displayTest(void)
{
  #ifdef  USING_TFT_22_ILI9225
      delay(1000);
    tft.setDisplay(true);
    //tft.setBacklight(false); It does not work with out the pin
    tft.clear();

    Serial.print("\n\nloop ");

    tft.drawRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_WHITE);
    delay(1000);
    tft.drawRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_BLACK);
  
    tft.setFont(Terminal6x8);
    tft.drawText(10, 10, "hello!");
      Serial.println("hello!");
    
    tft.clear();
    tft.drawText(10, 20, "clear");
    delay(1000);

    tft.drawText(10, 30, "text small");
    tft.setBackgroundColor(COLOR_YELLOW);
    Serial.println("text small");
    
    tft.setFont(Terminal12x16);
    tft.drawText(90, 30, "BIG", COLOR_RED);
      Serial.println("text big");
    tft.setBackgroundColor(COLOR_BLACK);
    tft.setFont(Terminal6x8);
    delay(1000);

    Serial.println("Set backlight off");
    tft.drawText(10, 40, "setBacklight off");
    delay(500);
    tft.setBacklight(LOW);
    delay(500);
    Serial.println("Set backlight on");
    tft.setBacklight(HIGH);
    tft.drawText(10, 50, "setBacklight on");
    delay(1000);

    Serial.println("rectangle");
    tft.drawRectangle(10, 10, 110, 110, COLOR_BLUE);
    tft.drawText(10, 60, "rectangle");
    delay(1000);

    Serial.println("solid rectangle");
    tft.fillRectangle(20, 20, 120, 120, COLOR_RED);
    tft.drawText(10, 70, "solidRectangle");
    delay(1000);

    Serial.println("circle");
    tft.drawCircle(80, 80, 50, COLOR_YELLOW);
    tft.drawText(10, 80, "circle");
    delay(1000);

    Serial.println("Solid circle");
    tft.fillCircle(90, 90, 30, COLOR_GREEN);
    tft.drawText(10, 90, "solidCircle");
    delay(1000);

    Serial.println("line");
    tft.drawLine(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_CYAN);
    tft.drawText(10, 100, "line");
    delay(1000);

    Serial.println("random points");
    for (uint8_t i = 0; i < 127; i++)
      tft.drawPixel(random(tft.maxX()), random(tft.maxY()), random(0xffff));
    tft.drawText(10, 110, "point");
    delay(1000);

    Serial.println("set orientation");
    for (uint8_t i = 0; i < 4; i++) {
      tft.clear();
      tft.setOrientation(i);
      tft.drawRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_WHITE);
      tft.drawText(10, 10, "setOrientation (" + String("0123").substring(i, i + 1) + ")");
      tft.drawRectangle(10, 20, 50, 60, COLOR_GREEN);
      tft.drawCircle(70, 80, 10, COLOR_BLUE);
      tft.drawLine(30, 40, 70, 80, COLOR_YELLOW);
      delay(1000);
    }


    Serial.println("Bye!!");
    tft.setOrientation(0);
    tft.clear();
    tft.setFont(Terminal12x16);
    tft.setBackgroundColor(COLOR_YELLOW);
    tft.drawText(10, 40, "bye!", COLOR_RED);
    tft.setBackgroundColor(COLOR_BLACK);
    tft.setFont(Terminal6x8);
    delay(1000);
    
    Serial.println("End of test");
    //while(true);
  #else

  #endif
}

