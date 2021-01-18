#include "ruukku.h"

ruukku ruukku1(A0,3);
ruukku ruukku2(A1,4);
ruukku ruukku3(A2,5);
ruukku ruukku4(A3,6);


//pumpulle ledit
int greenLED = 13;
int redLED = 13;
#define LEDON HIGH
#define LEDOFF LOW



// Pumppu
#define pumppuOpen  HIGH
#define pumppuClose LOW
#define RUUKKU1 1
#define RUUKKU2 2
#define RUUKKU3 4
#define RUUKKU4 8

const int pump = 2;




void setup() {
 
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  
  pinMode(pump, OUTPUT);
  
  Serial.begin(9600);

}

int pumpON=0;
void Pumppu ()
{
    if (pumpON == 0){
      
    digitalWrite(pump,pumppuClose);
    digitalWrite(redLED, LEDOFF);
    digitalWrite(greenLED, LEDON);
    Serial.println(pumpON); 
    }else{

    digitalWrite(pump,pumppuOpen);
    digitalWrite(redLED, LEDON);
    digitalWrite(greenLED, LEDOFF);
    Serial.println(pumpON); 
    }

    }
  
//kutsuu funktiot
void loop() {
  
  Pumppu ();
  
  if (ruukku1.kosteusMittari ()){
    pumpON = pumpON | RUUKKU1;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU1 ;
    }
  Serial.print(analogRead(A0));
  delay(1000);

  if (ruukku2.kosteusMittari ()){
    pumpON = pumpON | RUUKKU2;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU2 ;
    }
  Serial.print(analogRead(A1));
  delay(1000);

  if (ruukku3.kosteusMittari ()){
    pumpON = pumpON | RUUKKU3;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU3 ;
    }
  Serial.print(analogRead(A2));
  delay(1000);

  if (ruukku4.kosteusMittari ()){
    pumpON = pumpON | RUUKKU4;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU4 ;
    }
  Serial.print(analogRead(A3));
  delay(1000);
   
}
