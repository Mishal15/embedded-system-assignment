// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);

void setup()
{
  LCD.begin(16,2);
  LCD.home();
}

void loop()
{
  LCD.blink();
  LCD.cursor();
  LCD.setCursor(4,0);
  LCD.print("Welcome");
  delay(1000);
 
  LCD.setCursor(0,1); 
  LCD.print("Sure Trust ProEd");
  delay(1000);
  for(int i=0;i < 5;i++){
    LCD.scrollDisplayRight();
    delay(400);
  }
  delay(1000);
  LCD.clear();
  
  LCD.setCursor(0,1);
  LCD.autoscroll();
  for(int i=0;i < 10;i++){
    LCD.print(i);
    delay(500);
  }
  LCD.noAutoscroll();
  delay(1000);
  LCD.clear();
  
  LCD.noBlink();
  LCD.noCursor();
  LCD.noDisplay();
  delay(1000);
  LCD.display();
  LCD.clear();
}
