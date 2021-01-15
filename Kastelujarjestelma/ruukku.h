#ifndef ruukku_h
#define ruukku_h

#include "Arduino.h"

const int _valveClose =  LOW;
const int _valveOpen = HIGH;



class ruukku
{
  public:
  ruukku (int sensor, int valve);
  bool kosteusMittari();
  
  private:
  int _sensor;
  int _valve;
  int _thresholdValue;
  };


  #endif
