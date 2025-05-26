// C++ code
//
#define echo_pin 6
#define trigger_pin 7

long duration;
int distance;

void setup(){
  Serial.begin(9600);
  pinMode(echo_pin,INPUT);
  pinMode(trigger_pin,OUTPUT);
}

void loop(){
  digitalWrite(trigger_pin,LOW);
  delay(100);
  digitalWrite(trigger_pin,HIGH);
  delay(100);
  digitalWrite(trigger_pin,LOW);
   
  duration =pulseIn(echo_pin,HIGH);
  distance =duration * 0.034/2;
  
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
}