/*
Realizovati sistem uz pomoc LCD, gde se na samom LCD ispisuje odredjena poruka i njeno blicanje
*/

#include <LiquidCrystal.h>        //određujemo bazu za LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definišemo obavezne pinove na LCD displeju
                                  //RS/E/DB4/DB5/DB6/DB7 pinovi po redu

void setup() {
  lcd.begin(16,2);  //definišemo LCD displej
}

void loop()
{
  for (int I=1; I<=9; I++) //uvodimo for petlju zbog blicanja
  {
    lcd.display();         //uključuje LCD displej
    lcd.setCursor(3,0);    //određujemo poziciju na displeju
    lcd.print("Arduino");  //ispisuje željeni tekst
    lcd.setCursor(3,1);    //određujemo poziciju na displeju
    lcd.print("Kurs/Vezbe"); //ispisuje željeni tekst
    delay(500);
    lcd.noDisplay();        //isključuje displej
    delay(500);             //pravi pauzu
  }

}
