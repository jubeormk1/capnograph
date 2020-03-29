EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Base scheme to assembly the capnography monitor"
Date "2020-03-29"
Rev "V0.1"
Comp "CoronaVirusMakers"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push SW?
U 1 1 5E80970C
P 8750 5800
F 0 "SW?" H 8750 6085 50  0000 C CNN
F 1 "SW_Push" H 8750 5994 50  0000 C CNN
F 2 "" H 8750 6000 50  0001 C CNN
F 3 "~" H 8750 6000 50  0001 C CNN
	1    8750 5800
	0    -1   -1   0   
$EndComp
$Comp
L simpleSymbols:SprinIR-R U?
U 1 1 5E80C5CA
P 1750 4550
F 0 "U?" H 1700 4900 50  0000 L CNN
F 1 "SprinIR-R" H 1550 4750 50  0000 L CNN
F 2 "" H 1750 4800 50  0001 C CNN
F 3 "https://www.gassensing.co.uk/product/sprintir-r/" H 1750 4800 50  0001 C CNN
	1    1750 4550
	1    0    0    -1  
$EndComp
$Comp
L simpleSymbols:ESP32_DevKitC U?
U 1 1 5E80D356
P 5600 3200
F 0 "U?" H 5600 3415 50  0000 C CNN
F 1 "ESP32_DevKitC" H 5600 3324 50  0000 C CNN
F 2 "" H 5600 3200 50  0001 C CNN
F 3 "" H 5600 3200 50  0001 C CNN
	1    5600 3200
	1    0    0    -1  
$EndComp
$Comp
L simpleSymbols:SPI_TFT_DISPLAY U?
U 1 1 5E80E707
P 10050 950
F 0 "U?" H 10000 1050 50  0000 L CNN
F 1 "SPI_TFT_DISPLAY" H 9750 950 50  0000 L CNN
F 2 "" H 10050 950 50  0001 C CNN
F 3 "" H 10050 950 50  0001 C CNN
	1    10050 950 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Jack-DC J?
U 1 1 5E80EDE3
P 1050 1350
F 0 "J?" H 1107 1675 50  0000 C CNN
F 1 "12V 5A" H 1107 1584 50  0000 C CNN
F 2 "" H 1100 1310 50  0001 C CNN
F 3 "~" H 1100 1310 50  0001 C CNN
	1    1050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E80F9EA
P 1500 1650
F 0 "#PWR?" H 1500 1400 50  0001 C CNN
F 1 "GND" H 1505 1477 50  0000 C CNN
F 2 "" H 1500 1650 50  0001 C CNN
F 3 "" H 1500 1650 50  0001 C CNN
	1    1500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1450 1500 1450
Wire Wire Line
	1500 1450 1500 1600
Wire Wire Line
	1350 1250 1500 1250
$Comp
L power:+12V #PWR?
U 1 1 5E8105E8
P 2450 950
F 0 "#PWR?" H 2450 800 50  0001 C CNN
F 1 "+12V" H 2465 1123 50  0000 C CNN
F 2 "" H 2450 950 50  0001 C CNN
F 3 "" H 2450 950 50  0001 C CNN
	1    2450 950 
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U?
U 1 1 5E81277D
P 1500 2350
F 0 "U?" H 1500 2592 50  0000 C CNN
F 1 "L7805" H 1500 2501 50  0000 C CNN
F 2 "" H 1525 2200 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 1500 2300 50  0001 C CNN
	1    1500 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2750 900  2800
Wire Wire Line
	900  2800 1500 2800
Wire Wire Line
	1500 2800 1500 2650
Wire Wire Line
	2050 2750 2050 2800
Wire Wire Line
	2050 2800 1500 2800
Connection ~ 1500 2800
Wire Wire Line
	900  2450 900  2350
Wire Wire Line
	900  2350 1200 2350
Wire Wire Line
	1800 2350 2050 2350
Wire Wire Line
	2050 2350 2050 2450
Wire Wire Line
	2050 2350 2350 2350
Wire Wire Line
	2350 2350 2350 2150
Connection ~ 2050 2350
$Comp
L power:+5V #PWR?
U 1 1 5E816D89
P 2350 2150
F 0 "#PWR?" H 2350 2000 50  0001 C CNN
F 1 "+5V" H 2365 2323 50  0000 C CNN
F 2 "" H 2350 2150 50  0001 C CNN
F 3 "" H 2350 2150 50  0001 C CNN
	1    2350 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8196FA
P 1500 2800
F 0 "#PWR?" H 1500 2550 50  0001 C CNN
F 1 "GND" H 1505 2627 50  0000 C CNN
F 2 "" H 1500 2800 50  0001 C CNN
F 3 "" H 1500 2800 50  0001 C CNN
	1    1500 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5E819AB2
P 750 2200
F 0 "#PWR?" H 750 2050 50  0001 C CNN
F 1 "+12V" H 765 2373 50  0000 C CNN
F 2 "" H 750 2200 50  0001 C CNN
F 3 "" H 750 2200 50  0001 C CNN
	1    750  2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  2200 750  2350
Wire Wire Line
	750  2350 900  2350
Connection ~ 900  2350
$Comp
L Motor:Motor_DC M?
U 1 1 5E81F9BF
P 1750 6000
F 0 "M?" H 1908 5996 50  0000 L CNN
F 1 "VACUUM_PUMP" H 1908 5905 50  0000 L CNN
F 2 "" H 1750 5910 50  0001 C CNN
F 3 "https://www.sparkfun.com/products/10398" H 1750 5910 50  0001 C CNN
	1    1750 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_SDG Q?
U 1 1 5E820FFE
P 1650 6800
F 0 "Q?" H 1855 6846 50  0000 L CNN
F 1 "RFP30N06LE" H 1855 6755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 1850 6900 50  0001 C CNN
F 3 "https://www.sparkfun.com/datasheets/Components/General/RFP30N06LE.pdf" H 1650 6800 50  0001 C CNN
	1    1650 6800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST_LED SW?
U 1 1 5E80A8C3
P 2000 1150
F 0 "SW?" H 2000 1485 50  0000 C CNN
F 1 "SW_SPST_LED" H 2000 1394 50  0000 C CNN
F 2 "" H 2000 1450 50  0001 C CNN
F 3 "~" H 2000 1450 50  0001 C CNN
	1    2000 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1050 1500 1050
Wire Wire Line
	1500 1050 1500 1250
Wire Wire Line
	2200 1050 2450 1050
Wire Wire Line
	2450 1050 2450 950 
Wire Wire Line
	2450 1050 2450 1150
Wire Wire Line
	2450 1150 2200 1150
Connection ~ 2450 1050
$Comp
L Device:R R?
U 1 1 5E828F85
P 1250 7050
F 0 "R?" H 1320 7096 50  0000 L CNN
F 1 "10k" H 1320 7005 50  0000 L CNN
F 2 "" V 1180 7050 50  0001 C CNN
F 3 "~" H 1250 7050 50  0001 C CNN
	1    1250 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1150 1650 1150
Wire Wire Line
	1650 1150 1650 1250
Wire Wire Line
	1650 1550 1650 1600
Wire Wire Line
	1650 1600 1500 1600
Connection ~ 1500 1600
Wire Wire Line
	1500 1600 1500 1650
$Comp
L Device:LED D?
U 1 1 5E82A399
P 2600 2650
F 0 "D?" V 2639 2533 50  0000 R CNN
F 1 "LED" V 2548 2533 50  0000 R CNN
F 2 "" H 2600 2650 50  0001 C CNN
F 3 "~" H 2600 2650 50  0001 C CNN
	1    2600 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 2350 2600 2350
Connection ~ 2350 2350
$Comp
L Device:R R?
U 1 1 5E82DB43
P 1650 1400
F 0 "R?" H 1720 1446 50  0000 L CNN
F 1 "R" H 1720 1355 50  0000 L CNN
F 2 "" V 1580 1400 50  0001 C CNN
F 3 "~" H 1650 1400 50  0001 C CNN
	1    1650 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E82E18E
P 2600 3300
F 0 "#PWR?" H 2600 3050 50  0001 C CNN
F 1 "GND" H 2605 3127 50  0000 C CNN
F 2 "" H 2600 3300 50  0001 C CNN
F 3 "" H 2600 3300 50  0001 C CNN
	1    2600 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3300 2600 3200
Wire Wire Line
	2600 2900 2600 2800
Wire Wire Line
	2600 2350 2600 2500
Wire Wire Line
	1450 6800 1250 6800
Wire Wire Line
	1250 6800 1250 6900
Wire Wire Line
	1250 7200 1250 7250
Wire Wire Line
	1250 7250 1750 7250
Wire Wire Line
	1750 7250 1750 7000
$Comp
L Device:R R?
U 1 1 5E830EE3
P 2600 3050
F 0 "R?" H 2670 3096 50  0000 L CNN
F 1 "R" H 2670 3005 50  0000 L CNN
F 2 "" V 2530 3050 50  0001 C CNN
F 3 "~" H 2600 3050 50  0001 C CNN
	1    2600 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 6300 1750 6400
Wire Wire Line
	1250 6800 900  6800
Connection ~ 1250 6800
Text Label 900  6800 0    50   ~ 0
PUMP_PWM
$Comp
L power:+12V #PWR?
U 1 1 5E83AC26
P 1750 5700
F 0 "#PWR?" H 1750 5550 50  0001 C CNN
F 1 "+12V" H 1765 5873 50  0000 C CNN
F 2 "" H 1750 5700 50  0001 C CNN
F 3 "" H 1750 5700 50  0001 C CNN
	1    1750 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5700 1750 5750
$Comp
L Device:Buzzer BZ?
U 1 1 5E83D9A5
P 10700 5100
F 0 "BZ?" H 10852 5129 50  0000 L CNN
F 1 "Buzzer" H 10852 5038 50  0000 L CNN
F 2 "" V 10675 5200 50  0001 C CNN
F 3 "~" V 10675 5200 50  0001 C CNN
	1    10700 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E83EAD6
P 1750 7300
F 0 "#PWR?" H 1750 7050 50  0001 C CNN
F 1 "GND" H 1755 7127 50  0000 C CNN
F 2 "" H 1750 7300 50  0001 C CNN
F 3 "" H 1750 7300 50  0001 C CNN
	1    1750 7300
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 5E83FF47
P 1350 6050
F 0 "D?" V 1304 6129 50  0000 L CNN
F 1 "D" V 1395 6129 50  0000 L CNN
F 2 "" H 1350 6050 50  0001 C CNN
F 3 "~" H 1350 6050 50  0001 C CNN
	1    1350 6050
	0    1    1    0   
$EndComp
Wire Wire Line
	1750 5750 1350 5750
Wire Wire Line
	1350 5750 1350 5900
Connection ~ 1750 5750
Wire Wire Line
	1750 5750 1750 5800
Wire Wire Line
	1350 6200 1350 6400
Wire Wire Line
	1350 6400 1750 6400
Connection ~ 1750 6400
Wire Wire Line
	1750 6400 1750 6600
Wire Wire Line
	1750 7300 1750 7250
Connection ~ 1750 7250
$Comp
L Device:Q_NMOS_SDG Q?
U 1 1 5E84D3AE
P 10350 5600
F 0 "Q?" H 10555 5646 50  0000 L CNN
F 1 " 2N7000" H 10555 5555 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10550 5700 50  0001 C CNN
F 3 "https://www.sparkfun.com/datasheets/Components/General/RFP30N06LE.pdf" H 10350 5600 50  0001 C CNN
	1    10350 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E84D3B4
P 9950 5850
F 0 "R?" H 10020 5896 50  0000 L CNN
F 1 "10k" H 10020 5805 50  0000 L CNN
F 2 "" V 9880 5850 50  0001 C CNN
F 3 "~" H 9950 5850 50  0001 C CNN
	1    9950 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 5600 9950 5600
Wire Wire Line
	9950 5600 9950 5700
Wire Wire Line
	9950 6000 9950 6050
Wire Wire Line
	9950 6050 10450 6050
Wire Wire Line
	10450 6050 10450 5800
Wire Wire Line
	9950 5600 9600 5600
Connection ~ 9950 5600
Text Label 9600 5600 0    50   ~ 0
BUZZER_ON
$Comp
L power:GND #PWR?
U 1 1 5E84D3C2
P 10450 6100
F 0 "#PWR?" H 10450 5850 50  0001 C CNN
F 1 "GND" H 10455 5927 50  0000 C CNN
F 2 "" H 10450 6100 50  0001 C CNN
F 3 "" H 10450 6100 50  0001 C CNN
	1    10450 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 6100 10450 6050
Connection ~ 10450 6050
Wire Wire Line
	10600 5200 10450 5200
Wire Wire Line
	10450 5200 10450 5400
Wire Wire Line
	10600 5000 10450 5000
$Comp
L power:+5V #PWR?
U 1 1 5E855C93
P 10450 4750
F 0 "#PWR?" H 10450 4600 50  0001 C CNN
F 1 "+5V" H 10465 4923 50  0000 C CNN
F 2 "" H 10450 4750 50  0001 C CNN
F 3 "" H 10450 4750 50  0001 C CNN
	1    10450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 4750 10450 5000
Wire Wire Line
	5050 5200 5150 5200
Text Label 1350 1450 0    50   ~ 0
GND
Text Label 5050 4700 2    50   ~ 0
GND
Wire Wire Line
	5050 4700 5150 4700
Text Label 2400 2350 0    50   ~ 0
+5V
Text Label 5050 5200 2    50   ~ 0
+5V
Text Label 6150 4000 0    50   ~ 0
GND
Text Label 6150 3400 0    50   ~ 0
GND
Wire Wire Line
	6050 3400 6150 3400
Wire Wire Line
	6050 4000 6150 4000
$Comp
L Device:R 4k7
U 1 1 5E876C4C
P 8750 5350
F 0 "4k7" H 8820 5396 50  0000 L CNN
F 1 "R" H 8820 5305 50  0000 L CNN
F 2 "" V 8680 5350 50  0001 C CNN
F 3 "~" H 8750 5350 50  0001 C CNN
	1    8750 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E877AF0
P 9050 5800
F 0 "C?" H 9165 5846 50  0000 L CNN
F 1 "100nF" H 9165 5755 50  0000 L CNN
F 2 "" H 9088 5650 50  0001 C CNN
F 3 "~" H 9050 5800 50  0001 C CNN
	1    9050 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5950 9050 6100
Wire Wire Line
	9050 6100 8750 6100
Wire Wire Line
	8750 6100 8750 6000
Wire Wire Line
	8750 5600 8750 5550
Wire Wire Line
	8750 5200 8750 5100
$Comp
L power:+3.3V #PWR?
U 1 1 5E87C27C
P 5000 3300
F 0 "#PWR?" H 5000 3150 50  0001 C CNN
F 1 "+3.3V" H 5015 3473 50  0000 C CNN
F 2 "" H 5000 3300 50  0001 C CNN
F 3 "" H 5000 3300 50  0001 C CNN
	1    5000 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3300 5000 3400
Wire Wire Line
	5000 3400 5150 3400
$Comp
L power:+3.3V #PWR?
U 1 1 5E87DDAD
P 8750 5100
F 0 "#PWR?" H 8750 4950 50  0001 C CNN
F 1 "+3.3V" H 8765 5273 50  0000 C CNN
F 2 "" H 8750 5100 50  0001 C CNN
F 3 "" H 8750 5100 50  0001 C CNN
	1    8750 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5650 9050 5550
Wire Wire Line
	9050 5550 8750 5550
Connection ~ 8750 5550
Wire Wire Line
	8750 5550 8750 5500
$Comp
L power:GND #PWR?
U 1 1 5E880060
P 8750 6200
F 0 "#PWR?" H 8750 5950 50  0001 C CNN
F 1 "GND" H 8755 6027 50  0000 C CNN
F 2 "" H 8750 6200 50  0001 C CNN
F 3 "" H 8750 6200 50  0001 C CNN
	1    8750 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 6100 8750 6200
Connection ~ 8750 6100
$Comp
L power:GND #PWR?
U 1 1 5E8819DF
P 1700 5000
F 0 "#PWR?" H 1700 4750 50  0001 C CNN
F 1 "GND" H 1705 4827 50  0000 C CNN
F 2 "" H 1700 5000 50  0001 C CNN
F 3 "" H 1700 5000 50  0001 C CNN
	1    1700 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4900 1700 5000
Text Label 1500 4950 3    50   ~ 0
+5V
Wire Wire Line
	1500 4900 1500 5000
Text Label 9900 2300 3    50   ~ 0
DISPLAY_SCK
Wire Wire Line
	9900 2200 9900 2300
Text Label 10000 2300 3    50   ~ 0
DISPLAY_SDA
Wire Wire Line
	10000 2200 10000 2300
Text Label 10100 2300 3    50   ~ 0
DISPLAY_CS
Wire Wire Line
	10100 2200 10100 2300
Text Label 10200 2300 3    50   ~ 0
DISPLAY_DC
Wire Wire Line
	10200 2200 10200 2300
Text Label 10300 2300 3    50   ~ 0
DISPLAY_RST
Wire Wire Line
	10300 2200 10300 2300
Text Label 9700 2300 3    50   ~ 0
+5V
Wire Wire Line
	9700 2200 9700 2300
Text Label 9800 2300 3    50   ~ 0
GND
Wire Wire Line
	9800 2200 9800 2300
Text Label 6150 4200 0    50   ~ 0
DISPLAY_SCK
Text Label 6150 3500 0    50   ~ 0
DISPLAY_SDA
Text Label 6150 4300 0    50   ~ 0
DISPLAY_CS
Text Label 6150 4600 0    50   ~ 0
DISPLAY_RST
Wire Wire Line
	6150 4200 6050 4200
Wire Wire Line
	6150 4300 6050 4300
Wire Wire Line
	6150 4600 6050 4600
Text Label 6150 4800 0    50   ~ 0
DISPLAY_DC
Wire Wire Line
	6150 4800 6050 4800
Wire Wire Line
	6150 3500 6050 3500
Wire Wire Line
	8750 5550 8250 5550
$Comp
L Device:C C?
U 1 1 5E8B0724
P 2050 2600
F 0 "C?" H 2165 2646 50  0000 L CNN
F 1 "0.1uF" H 2165 2555 50  0000 L CNN
F 2 "" H 2088 2450 50  0001 C CNN
F 3 "~" H 2050 2600 50  0001 C CNN
	1    2050 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E8B0F32
P 900 2600
F 0 "C?" H 1015 2646 50  0000 L CNN
F 1 "0.33uF" H 1015 2555 50  0000 L CNN
F 2 "" H 938 2450 50  0001 C CNN
F 3 "~" H 900 2600 50  0001 C CNN
	1    900  2600
	1    0    0    -1  
$EndComp
Text Label 8350 5550 2    50   ~ 0
BTN_USER1
Wire Wire Line
	2000 4900 2000 5000
Wire Wire Line
	1900 4900 1900 5100
Wire Wire Line
	1900 5100 2150 5100
Wire Wire Line
	2000 5000 2150 5000
Text Label 2150 5000 0    50   ~ 0
CO2_RX
Text Label 2150 5100 0    50   ~ 0
CO2_TX
$EndSCHEMATC