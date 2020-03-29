//speedy and dirty programmed by @TCRobotics
//This code outputs continuosly a simulated data from a SprintIR sensor trough serial
//You can upload this to a arduino board and conect from the serial TX to simulate a sensor
//The raw data has an 0 to 100 ppm random offset per sample, the filtered is always the same.

#include <Arduino.h>

#include "Platform.h"


u32 ppmData[]
{
    29571, 32454, 34636, 36295, 37565, 38545, 39308, 39909, 40389, 40779, 41101, 41372, 41605, 41809,
    41990, 42154, 42306, 42447, 42581, 42707, 42829, 42947, 43061, 43171, 43279, 43385, 43489, 43590,
    43690, 43788, 43884, 43979, 44072, 44163, 44253, 44342, 44429, 44515, 44600, 44683, 44765, 44845,
    44925, 45003, 45080, 45156, 45231, 45304, 45376, 45448, 15947, 13132, 11019, 9426, 8222, 7307,
    6608, 6070, 5651, 5323, 5061, 2549, 2374, 2228, 2103, 1994, 1897, 1810, 1730, 1655, 1585, 1518,
    1454, 1392, 1332, 1274, 1217, 1162, 1108, 1055, 1002, 951, 901, 851, 803, 755, 707, 661, 615, 570,
    526, 483, 440, 397, 356, 315, 275, 235, 196, 157, 29691, 32537, 34682, 36305, 37539, 38484, 39213,
    39780, 40227, 40584, 40873, 41112, 41314, 41486, 41637, 41772, 41893, 42006, 42110, 42209, 42303,
    42393, 42480, 42565, 42647, 42727, 42805, 42881, 42956, 43030, 43103, 43174, 43244, 43313, 43380,
    43447, 43513, 43577, 43641, 43703, 43765, 43826, 43885, 43944, 44002, 44059, 44115, 44170, 44225,
    44278, 14760, 11929, 9798, 8189, 6968, 6037, 5322, 4768, 4335, 3991, 3714, 3487, 3298, 3138, 2999,
    2876, 2766, 2665, 2571, 2484, 2401, 2321, 2245, 2171, 2099, 2029, 1961, 1894, 1829, 1764, 1701,
    1639, 1578, 1518, 1459, 1401, 1344, 1288, 1232, 1178, 1124, 1072, 1020, 968, 918, 868, 820, 771,
    724, 678, 30203, 33041, 35178, 36794, 38021, 38958, 39679, 40239, 40679, 41029, 41312, 41544, 41739,
    41905, 42049, 42177, 42293, 42399, 42498, 42590, 42679, 42763, 42844, 42923, 42999, 43074, 43147,
    43218, 43288, 43357, 43424, 43490, 43555, 43620, 43683, 43745, 43806, 43866, 43925, 43983, 44040,
    44097, 44152, 44207, 44261, 44314, 44366, 44417, 44468, 44518, 14995, 12161, 10026, 8414, 7190, 6255,
    5537, 4980, 4543, 4196, 3915, 3686, 3494, 3330, 3188, 3063, 2949, 2846, 2750, 2659, 2573, 2491, 2412,
    2336, 2261, 2189, 2118, 2049, 1981, 1914, 1849, 1785, 1721, 1659, 1598, 1538, 1479, 1420, 1363, 1306,
    1251, 1196, 1142, 1089, 1037, 986, 935, 885, 836, 788, 30311, 33148, 35283, 36897, 38123, 39058,
    39778, 40336, 40775, 41123, 41404, 41635, 41829, 41993, 42136, 42263, 42377, 42482, 42580, 42671,
    42758, 42841, 42921, 42999, 43074, 43147, 43219, 43289, 43358, 43426, 43492, 43557, 43621, 43684,
    43746, 43807, 43868, 43927, 43985, 44042, 44098, 44154, 44209, 44262, 44315, 44368, 44419, 44469,
    44519, 44568, 15045, 12210, 10075, 8461, 7237, 6302, 5582, 5025, 4587, 4239, 3958, 3728, 3535, 3371,
    3229, 3102, 2988, 2884, 2787, 2696, 2610, 2527, 2448, 2371, 2296, 2223, 2152, 2082, 2013, 1946, 1880,
    1815, 1752, 1689, 1627, 1567, 1507, 1448, 1391, 1334, 1278, 1223, 1168, 1115, 1062, 1010, 959, 909,
    860, 811, 30334, 33170, 35306, 36919, 38144, 39079, 39799, 40357, 40795, 41143, 41424, 41655, 41848,
    42012, 42155, 42281, 42395, 42500, 42597, 42688, 42775, 42858, 42937, 43015, 43090, 43163, 43234,
    43304, 43373, 43440, 43506, 43571, 43635, 43698, 43760, 43821, 43881, 43940, 43998, 44055, 44111,
    44166, 44221, 44274, 44327, 44379, 44430, 44481, 44530, 44579, 15056, 12220, 10085, 8471, 7246, 6311,
    5592, 5034, 4596, 4248, 3967, 3737, 3544, 3380, 3237, 3111, 2997, 2892, 2795, 2704, 2618, 2535, 2455,
    2378, 2303, 2230, 2159, 2089, 2020, 1953, 1887, 1822, 1758, 1695, 1634, 1573, 1513, 1454, 1396, 1339,
    1283, 1228, 1174, 1120, 1067, 1016, 964, 914, 865, 816, 30339
};

void SimulateSprintIR(u32 co2filteredTX, u32 co2rawTX)
{
    static char buffer[18];
    //Simulate the protocol "Z XXXXX z XXXXX\r\n"
    sprintf(buffer,"Z %05i z %05i\r\n", co2filteredTX, co2rawTX);
    Serial.print(buffer);
}

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0)); //make random more random
}

void loop()
{
    for(u32 index = 0; index < 501; ++index)
    {
        const auto& value = ppmData[index];
        SimulateSprintIR(value, value + random(1500));
        delay(50); //50ms delay = aprox 20Hz
    }
}