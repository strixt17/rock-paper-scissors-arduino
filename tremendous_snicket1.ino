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
int item2 = 0;

String modetxt;

long randNumber;

void setup()
{
  Serial.begin(9600);
  
  analogWrite(contrast, 100);
  lcd.begin(16, 2);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  randomSeed(analogRead(0));
}

void loop()
{
  changeitem = digitalRead(buttonPin1);
  changemode = digitalRead(buttonPin2);
  changeplayer = digitalRead(buttonPin3);
  if (changemode == HIGH) {
  	mode = mode + 1;
    delay(500);
    if (mode = 3) {
    	mode = 0;
    }
    if (mode = 0) {
    	modetxt = "   ";
    }
    if (mode = 1) {
    	modetxt = "1v1";
    }
    if (mode = 2) {
    	modetxt = "AI";
    }
    Serial.println("mode = " + String(mode));    
    lcd.setCursor(0, 0);
  	lcd.print("Rock Paper Scissors");
  	lcd.setCursor(0, 1);
  	lcd.print("Mode: " + modetxt);
    
  }
  if (changeplayer == HIGH) {
  	player = player + 1;
    if (player  == 4){
    	player = 1;
    }
    delay(500);
    Serial.println("player = " + String(player));
  }
  if (mode == 1 && player == 1) {
    if (changeitem == HIGH) {
  	item = item + 1;
    if (item == 4) {
    	item = 1;
    }
    delay(500);
    Serial.println("item = " + String(item));
  	}
    if (item > 0) {
      lcd.clear();
    if (item == 1) {
      lcd.setCursor(0, 1);
      	lcd.print("8<");
    }
    if (item == 2) {
    	lcd.setCursor(0, 1);
      	lcd.print("O ");
    }
    if (item == 3) {
    	lcd.setCursor(0, 1);
      	lcd.print("P ");
    }
    }
  }
  if (mode == 1 && player == 2){
  	if (changeitem == HIGH) {
  	item2 = item2 + 1;
    if (item2 == 4) {
    	item2 = 1;
    }
    delay(500);
    Serial.println("item2 = " + String(item));
  	}
    
    if (item2 == 1) {
    	lcd.setCursor(14, 1);
      	lcd.print(">8");
    }
    if (item2 == 2) {
    	lcd.setCursor(14, 1);
      	lcd.print("O ");
    }
    if (item2 == 3) {
    	lcd.setCursor(14, 1);
      	lcd.print("P ");
    }
    
  }
  if (mode == 1 && player == 3) {
    if (item2 == item) {
      lcd.setCursor(0,1);
      lcd.print("tie game"); 
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 1 && item == 2) {
      lcd.setCursor(5,0);
      lcd.print("player 1 wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 2 && item == 1) {
      lcd.setCursor(5,0);
      lcd.print("player 2 wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 2 && item == 3) {
      lcd.setCursor(5,0);
      lcd.print("player 1 wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 3 && item == 2){
      lcd.setCursor(5,0);
      lcd.print("player 2 wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
  }
  if (mode == 2 && player == 1) {
  	
    if (changeitem == HIGH) {
  	item = item + 1;
    if (item == 4) {
    	item = 1;
    }
    delay(500);
    Serial.println("item = " + String(item));
  	}
    if (item > 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You           AI");
    if (item == 1) {
      lcd.setCursor(0, 1);
      	lcd.print("8<");
    }
    if (item == 2) {
    	lcd.setCursor(0, 1);
      	lcd.print("O ");
    }
    if (item == 3) {
    	lcd.setCursor(0, 1);
      	lcd.print("P ");
    }
    }
  }
  if (mode == 2 && player == 2) {
  	item2 = random(1, 4);
    if (item2 == 1) {
      lcd.setCursor(14, 1);
      	lcd.print(">8");
    }
    if (item2 == 2) {
    	lcd.setCursor(14, 1);
      	lcd.print("O ");
    }
    if (item2 == 3) {
    	lcd.setCursor(14, 1);
      	lcd.print("P ");
    }
    player = 3;
  }
  if (mode == 2 && player == 3) {
    if (item2 == item) {
      lcd.setCursor(5,0);
      lcd.print("tie game"); 
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 1 && item == 2) {
      lcd.setCursor(5,0);
      lcd.print("You Won");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 2 && item == 1) {
      lcd.setCursor(5,0);
      lcd.print("AI wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 2 && item == 3) {
      lcd.setCursor(5,0);
      lcd.print("You won");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
    if (item2 == 3 && item == 2){
      lcd.setCursor(5,0);
      lcd.print("AI wins");
      delay(5000);
      mode = 0;
      item = 0;
      player = 0;
      item2 = 0;
    }
}
}