#ifndef jlinker_h
#define jlinker_h
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <U8glib.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#define Joy1X A0
#define Joy1Y A1
#define Joy2X A2
#define Joy2Y A3
#define Pot_1 A6
#define Pot_2 A7
#define button_1 2
#define button_2 3
#define button_3 1
#define button_4 0
#define Joy1But 4
#define Joy2But 5
#define SW_1 6
#define SW_2 7
#define User_LED 8

class jlinker
{
  public:
    void pinSet(void);
    
    float joyLeftX(void);

    float joyLeftY(void);

    float joyRightX(void);

    float joyRightY(void);

    int POT_1(void);
    
    int POT_2(void);

    float Button_1(void);

    float Button_2(void);

    float Button_3(void);

    float Button_4(void);
    
    float joyLeftButton(void);

    float joyRightButton(void);

    float Switch_1(void);

    float Switch_2(void);

  private:
};

#endif

