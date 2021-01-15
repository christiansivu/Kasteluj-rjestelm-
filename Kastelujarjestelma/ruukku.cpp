#include "Arduino.h"
#include "ruukku.h"

ruukku::ruukku (int sensor, int valve)
{
  pinMode (sensor,INPUT);
  _sensor = sensor;

  pinMode (valve,OUTPUT);
  _valve = valve;
  _thresholdValue = 800;
  }


  bool ruukku::kosteusMittari()
  {
    
  
  int _sensorValue = analogRead(_sensor);
  
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
    
