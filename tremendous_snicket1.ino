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

int item = 0;
int mode = 0;
int player = 0;

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

  lcd.setCursor(0, 0);
  lcd.print("Rock Paper Scissors");
  lcd.setCursor(0, 1);
  lcd.print("Choose Mode: ");
  if (changemode == HIGH) {
  	mode = mode + 1;
    delay(500);
    Serial.println("mode = " + String(mode));
    lcd.print(mode);
  }
  changeitem = digitalRead(buttonPin1);
  changemode = digitalRead(buttonPin2);
  changeplayer = digitalRead(buttonPin3);
  if (changeitem == HIGH) {
  	item = item + 1;
    if (item == 4) {
    	item = 1;
    }
    delay(500);
    Serial.println("item = " + String(item));
  }
  
  if (changeplayer == HIGH) {
  	player = player + 1;
    delay(500);
    Serial.println("player = " + String(player));
  }
  if (mode == 1) {
    if (item == 1) {
    	lcd.setCursor(0, 0);
      	lcd.print("8<");
    }
    if (item == 2) {
    	lcd.setCursor(0, 0);
      	lcd.print("O ");
    }
    if (item == 3) {
    	lcd.setCursor(0, 0);
      	lcd.print("P ");
    }
  }
}