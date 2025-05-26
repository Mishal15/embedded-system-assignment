int gassensor = 0;
const int gassensorPin =A5;
const int threshold = 400;
int green_led = 6;
int red_led = 7;
int buzzer_pin = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(green_led , OUTPUT);
  pinMode(red_led  , OUTPUT);
  pinMode(buzzer_pin , OUTPUT);
}

void loop()
{
  gassensor = analogRead(gassensorPin);
  Serial.print("Gas Sensor Reading:");
  Serial.println(gassensor);
  
  if(gassensor > threshold){
    digitalWrite(red_led,LOW);
    digitalWrite(green_led,HIGH);
    tone (buzzer_pin, 200, 500);
  }
  else{
    digitalWrite(red_led,HIGH);
    digitalWrite(green_led,LOW);
    noTone (buzzer_pin);
  }
  delay(100);
}