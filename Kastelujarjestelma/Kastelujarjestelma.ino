#include "ruukku.h"
#include <LiquidCrystal.h>

ruukku ruukku1(A0,3);
ruukku ruukku2(A1,4);
ruukku ruukku3(A2,5);
ruukku ruukku4(A3,6,600);

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//pumpulle ledit
int greenLED = 13;
int redLED = 13;
#define LEDON HIGH
#define LEDOFF LOW



// Pumppu
#define pumppuOpen  HIGH
#define pumppuClose LOW
#define RUUKKU1 1  // 0001
#define RUUKKU2 2  // 0010
#define RUUKKU3 4  // 0100
#define RUUKKU4 8  // 1000

const int pump = 2;




void setup() {
 
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  
  pinMode(pump, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("");
}

int pumpON=0;
void Pumppu ()
{
    if (pumpON == 0){
      
    digitalWrite(pump,pumppuClose);
    digitalWrite(greenLED, LEDON);
    Serial.println(pumpON); 
    }else{

    digitalWrite(pump,pumppuOpen);  
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
  

  if (ruukku2.kosteusMittari ()){
    pumpON = pumpON | RUUKKU2;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU2 ;
    }
  

  if (ruukku3.kosteusMittari ()){
    pumpON = pumpON | RUUKKU3;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU3 ;
    }
  

  if (ruukku4.kosteusMittari ()){
    pumpON = pumpON | RUUKKU4;
    }
    else{ 
    
    pumpON = pumpON & ~RUUKKU4 ;
    }
  

   lcd.setCursor(0, 0);
   lcd.print("R1");
   lcd.setCursor( 5,0);
   lcd.print(ruukku1.getVal());
   lcd.setCursor( 8,0);
   lcd.print("R2");
   lcd.setCursor( 12,0);
   lcd.print(ruukku2.getVal());

   lcd.setCursor(0, 1);
   lcd.print("R3");
   lcd.setCursor( 5,1);
   lcd.print(ruukku3.getVal());
   lcd.setCursor( 8,1);
   lcd.print("R4");
   lcd.setCursor( 12,1);
   lcd.print(ruukku4.getVal());
}
