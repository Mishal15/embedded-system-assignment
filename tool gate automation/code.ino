// C++ code
//
#include <Servo.h>
#include <LiquidCrystal.h>

#define echoPin 11
#define trigPin 12

Servo myServo;
int buzzer = 6;

long duration;
int distance;

LiquidCrystal lcd(10,9,2,3,4,5);

void setup()
{
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  myServo.attach(13);
  myServo.write(90);  

  lcd.begin(16, 2);   
  lcd.home();
 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(3, 0);
  lcd.print("Distance: ");
  if (distance < 345) {
   lcd.print(distance);
   lcd.print("cm  ");
  }
  
  if (distance <= 25)
  {
    tone(buzzer, 1000);
    myServo.write(0); 

    lcd.setCursor(0, 1);
    lcd.print("Gate: OPEN       ");
  }
  else
  {
    noTone(buzzer);
    myServo.write(90);  

    lcd.setCursor(0, 1);
    lcd.print("Gate: CLOSED     ");
  }

  delay(200);
}

