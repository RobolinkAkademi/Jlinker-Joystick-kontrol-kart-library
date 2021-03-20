#include "jlinker.h"

void jlinker::pinSet(void)
{
  pinMode(Joy1X, INPUT);
  pinMode(Joy1Y, INPUT);
  pinMode(Joy2X, INPUT);
  pinMode(Joy2Y, INPUT);
  pinMode(Pot_1, INPUT);
  pinMode(Pot_2, INPUT);
  pinMode(Joy1But, INPUT_PULLUP);
  pinMode(Joy2But, INPUT_PULLUP);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_4, INPUT_PULLUP);
  pinMode(SW_1, INPUT);
  pinMode(SW_2, INPUT);
  pinMode(User_LED , OUTPUT);
}
float jlinker::joyLeftX(void)
{
  return analogRead(Joy1X);
  }
  float jlinker::joyLeftY(void)
{
  return analogRead(Joy1Y);
  }
float jlinker::joyRightX(void)
{
  return analogRead(Joy2X);
  }
float jlinker::joyRightY(void)
{
  return analogRead(Joy2Y);
  }
  int jlinker::POT_1(void)
{
  return analogRead(Pot_1);
  }
  int jlinker::POT_2(void)
{
  return analogRead(Pot_2);
  }  
  float jlinker::Button_1(void)
{
  return digitalRead(button_1);
  }
  float jlinker::Button_2(void)
{
  return digitalRead(button_2);
  }
  float jlinker::Button_3(void)
{
  return digitalRead(button_3);
  }
  float jlinker::Button_4(void)
{
  return digitalRead(button_4);
  }
  float jlinker::joyLeftButton(void)
{
  return digitalRead(Joy1But);
  }
  float jlinker::joyRightButton(void)
{
  return digitalRead(Joy2But);
  }    
  float jlinker::Switch_1(void)
{
  return digitalRead(SW_1);
  }    
  float jlinker::Switch_2(void)
{
  return digitalRead(SW_2);
  }    


  


