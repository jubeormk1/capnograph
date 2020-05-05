#ifndef DISPLAY_H
#define DISPLAY_H

#define USING_TFT_22_ILI9225
//#define USING_ADAFRUIT_ST7735
//#define USING_ADAFRUIT_ST7789

#ifdef  USING_TFT_22_ILI9225
//Julio's test
    #include "TFT_22_ILI9225.h"
    // Fixed size: 176x220
    // COLORS: Colours are defined in the library

    #define TFT_LED 0  // 3V3 (0 for the library)
    #define TFT_CLK 18 // IO18: VSPI-SCK
    #define TFT_SDI 23 // IO23: VSPI-MOSI
    #define TFT_CS  5  // IO5:  VSPI-SS
    #define TFT_RS  21 // IO21: GPIO
    #define TFT_RST 4  // IO4:  GPIO
    #define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)
    #define SPI_IN_USE VSPI

#elif defined USING_ADAFRUIT_ST7735 || defined USING_ADAFRUIT_ST7789

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>


// Display config
#define DISPLAY_CS_PIN  5  // define chip select pin
#define DISPLAY_DC_PIN  2  // define data/command pin
#define DISPLAY_RST_PIN 4  // define reset pin
#define DISPLAY_X_SIZE 240
#define DISPLAY_Y_SIZE 240


// Some ready-made 16-bit ('565') color settings
// TODO: Move to a FColor struct
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x07E0
#define COLOR_BLUE    0x001F
#define COLOR_CYAN    0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_YELLOW  0xFFE0
#define COLOR_ORANGE  0xFC00

extern unsigned int samplesPerPixel;
//extern Adafruit_ST7789 display; // hidding the display object to improve modularity
#else
#error "Please select a LCD to use"
#endif

/**
 * @brief  setup the display 
 * @note   This functions needs to be called before any other methods of this API
 * @retval None
 */
void setupDisplay(void);

void printGraph(void);

/**
 * @brief  This function sets sensor parameters to optimize the display settings
 * @note   FixMe. There is no clear interface between sensor and this function
 * @retval None
 */
void setupGraph(void);

void displayMessage(const char * message);

void printBPM(unsigned int bpm); // belongs to display actually
void printEtCO2(long bpm); // belongs to display actually
void printState(const char *state); // belongs to display actually

void displayTest(void);

#endif