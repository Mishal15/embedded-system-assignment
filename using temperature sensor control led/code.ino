// C++ code
//
int sensorPin =A0;
int ledBlue=5;
int ledYellow=4;
int ledGreen=3;
int ledRed=2;

void setup()
{
  Serial.begin(9600);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop()
{
  int reading = analogRead(sensorPin);
  float voltage = reading * 4.68 / 1024.0; // Adjust 4.68 to your actual 5V line if needed
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  
   if (temperatureC >= -40.86 && temperatureC < 1) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
  } 
  else if (temperatureC >= 1 && temperatureC <=50) {
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
  } 
  else if (temperatureC >= 51 && temperatureC <=75) {
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
  } 
  else {
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
  }

  delay(1000); 
}