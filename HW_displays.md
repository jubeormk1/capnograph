# Displays
A display is needed for showing the CO2 graph and measures as breaths per minute (bpm) and end tidal CO2 (etCO2).

## Supported displays  
Right now this project supports two displays:  
* [Ywrobot TFT LCD screen](https://www.amazon.co.uk/gp/product/B07N6FQ5XW/)  
  * 128x160 resolution  
  * 262K colors  
  * 1.8 inch  
  * SPI control  
  * ST7735 driver  
* [FeiYang TFT LCD IPS GMT130-V1.0](https://www.aliexpress.com/item/32947890530.html?spm=a2g0s.9042311.0.0.274263c0QKCxM4)  
  * 240x240 resolution  
  * 65K colors  
  * 1.3 inch  
  * SPI control  
  * ST7789 driver  

### Pinout
| ST7735 pin | Function         | ESP32 pin |
|:----------:|:----------------:|:---------:|
| VCC        | Power            | 3V3       |
| GND        | Power            | GND       |
| SCK        | SPI clock        | 18        |
| SDA        | SPI data         | 23        |
| DC         | SPI Data Command | 2         |
| CS         | Chip select      | 5         |
| RST        | Reset            | 4         |
| BLK        | Back light       | 3V3/NC    |

| ST7789 pin | Function         | ESP32 pin |
|:----------:|:----------------:|:---------:|
| VCC        | Power            | 3V3       |
| GND        | Power            | GND       |
| SCK        | SPI clock        | 18        |
| SDA        | SPI data         | 23        |
| DC         | SPI Data Command | 2         |
| RES        | Reset            | 4         |
| BLK        | Back light       | 3V3       |

| ILI9225 pin | Function        | ESP32 pin |
|:-----------:|:---------------:|:----------|
| VCC (1)     | Power           | 3V3       |
| GND (2,3)   | Power           | GND       |
| LED (6)     | Back light      | 3V3       |
| CLK (7)     | SPI clock       | IO14      |
| SDI (8)     | SPI mosi        | IO23      |
| CS (5)      | SPI ss          | IO5       |
| RS (21)     | Reg Select      | IO21      |
| RST (4)     | Reset           | IO4       |



## More displays!
We are using the [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library) and [Adafruit_ST77XX](https://github.com/adafruit/Adafruit-ST7735-Library) library, so you can easily adapt the code for other ST77XX displays. 

Lately we have added the display family ILI9225 using the driver [UTFT by Tony Ivanov based on Henning Karlsen's library](https://github.com/johncblacker/utft). It is claimed to be the "Universal TFT Display" library for Arduino and can be used with many microcontroller platforms.

We are looking for supporting more displays! Waiting your pull request! 
