/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PeripheralNames.h"
#include "PinNames.h"
#include "ThisThread.h"
#include "mbed.h"
#include <cstdio>


AnalogIn ain(A0);
PwmOut led(LED1);
int main()
{
    int hex;
    float brightness;
    float voltage;
    while (true) {
        hex = ain.read_u16();
        voltage = ain.read()*3.3;
        brightness = ain.read();
        printf("Hex: %x  Voltage: %f V Brightness: %f % \n",hex,voltage,brightness*10);
        led.write(brightness);
        ThisThread::sleep_for(500);
    }
}
hex = ain.read_u16()