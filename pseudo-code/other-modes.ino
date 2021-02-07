#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//The address is 0x27. Number of columns is 16 and number of rows is 2.


void setup() {
  lcd.begin(); //if throws error use lcd.begin(16,2)
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5,0); // for aligning a bit center
  lcd.print("Other-Modes");// put your setup code here, to run once
}

void loop() {
  Serial.begin(9600);
  String Alphabets[100] = {"A  ,  a", "B  ,  b", "C  ,  c", "D  ,  d", "E  ,  e", "F  ,  f", "G  ,  g", "H  ,  h", "I  ,  i", "J  ,  j", "K  ,  k",  "L  ,  l", "M  ,  m", "N  ,  n", "O  ,  o", "P  ,  p", "Q  ,  q", "R  ,  r", "S  ,  s", "T  ,  t", "U  ,  u", "V  ,  v", "W  ,  w", "X  ,  x", "Y  ,  y", "Z  ,  z"};// put your main code here, to run repeatedly:
  String Alpha_Name[100] = {"Apple" , "Ball", "Cat", "Dog", "Elephant", "Fan", "Glass", "Horse", "Icecream", "Jackle", "Kite", "Lion", "Monkey", "Nest", "Orange", "Peacock", "Queen", "Rabbit", "Sandwitch", "Turtle", "Umberella", "Van", "Watch", "Xylophone", "Yak", "Zebra"};
  String Numbers[100] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  String Num_Name[100] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  //Hindi-Varn = []

  int i;
  for (i=0; i<26; i++)
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print(Alphabets[i]);
    lcd.setCursor(5,1);
    lcd.print(Alpha_Name[i]);
  }

  for (i=0; i<9; i++)
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print(Numbers[i]);
    lcd.setCursor(5,1);
    lcd.print(Num_Name[i]);
  }
  
} 
