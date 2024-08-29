// C++ code
//

#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
const int contrast = 2;

const int buttonPin1 = 9;
const int buttonPin2 = 10;
const int buttonPin3 = 11;

int changeitem = 0;
int changemode = 0;
int changeplayer = 0;
int buttonpressed1 = 0;
int buttonpressed2 = 0;
int buttonpressed3 = 0;

void setup()
{
  Serial.begin(9600);
  
  analogWrite(contrast, 100);
  lcd.begin(16, 2);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop()
{
  changeitem = digitalRead(buttonPin1);
  changemode = digitalRead(buttonPin2);
  changeplayer = digitalRead(buttonPin3);
}