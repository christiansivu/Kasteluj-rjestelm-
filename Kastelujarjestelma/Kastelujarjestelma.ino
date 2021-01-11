int greenLED = 12;
int redLED = 13;
int sensori = A0;

int thresholdValue = 800;
void setup() {
  pinMode(sensori, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.begin(9600);

}

void toggleled() {
  
  int sensorValue = analogRead(sensori);
  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
    Serial.println(" Ei tarvi vettä");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  else {
    Serial.println(" Tarvii vettä");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  delay(500);
}

void loop() {
  toggleled();
  Serial.println(analogRead(A0));
  delay(1000);

}
