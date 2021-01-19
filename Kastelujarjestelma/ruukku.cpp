#include "Arduino.h"
#include "ruukku.h"


int ruukku::getVal(){
  return map(_sensorValue,0,1023,0,9);
  }


ruukku::ruukku (int sensor, int valve)
{
  pinMode (sensor,INPUT);
  _sensor = sensor;

  pinMode (valve,OUTPUT);
  _valve = valve;
  _thresholdValue = 800;
  }
ruukku::ruukku (int sensor, int valve, int threshold)
{
  pinMode (sensor,INPUT);
  _sensor = sensor;

  pinMode (valve,OUTPUT);
  _valve = valve;
  _thresholdValue = threshold;
  }


  bool ruukku::kosteusMittari()
  {
    
  
  _sensorValue = analogRead(_sensor);
  
  if(_sensorValue < _thresholdValue){
    Serial.println("Ei tarvi vettä ");
    digitalWrite (_valve,_valveClose);
    return false;
    
    
    
    
  }
  else {
    Serial.println("Tarvii vettä"); 
    digitalWrite (_valve,_valveOpen);
    return true;
     
     
    
  }
  }
    
