//pumpulle ledit
int greenLED = 12;
int redLED = 13;
#define LEDON HIGH
#define LEDOFF LOW

//kosteusmittareille 
const int sensori1 = A0;
const int sensori2 = A1;
const int sensori3 = A2;
const int sensori4 = A3;

//venttiilit
const int valve1 = 3;
const int valve2 = 4;
const int valve3 = 5;
const int valve4 = 6;

//valve
#define valveClose  LOW
#define valveOpen  HIGH

// Pumppu
#define pumppuOpen  HIGH
#define pumppuClose LOW
#define KRUKA1 1
#define KRUKA2 2
#define KRUKA3 4
#define KRUKA4 8

const int pump = 2;

int thresholdValue = 800;


void setup() {
  pinMode(sensori1, INPUT);
  pinMode(sensori2, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  
  pinMode(valve1, OUTPUT);
  pinMode(valve2, OUTPUT);
  pinMode(valve3, OUTPUT);
  pinMode(valve4, OUTPUT);
 
  
  digitalWrite(valve1, valveClose);
  digitalWrite(valve2, valveClose);
  digitalWrite(valve3, valveClose);
  digitalWrite(valve4, valveClose);
  
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
  void kosteusMittari() {
  
  int sensorValue = analogRead(sensori1);
  
  if(sensorValue < thresholdValue){
    Serial.println("Ei tarvi vettä ");
    digitalWrite (valve1,valveClose);
    pumpON = pumpON & ~KRUKA1;
    Serial.println(pumpON);
    delay(1000);
    
  }
  else {
    Serial.println("Tarvii vettä"); 
    digitalWrite (valve1,valveOpen);
     
     pumpON = pumpON | KRUKA1;
    Serial.println(pumpON); 
    
  }
  }

//kutsuu funktiot
void loop() {
  
  Pumppu ();
  kosteusMittari();
  Serial.print(analogRead(A0));
  
   
}
