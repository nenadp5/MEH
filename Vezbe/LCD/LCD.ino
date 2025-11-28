/*
Zadatak ove vežbe je da vas upoznamo sa osnovama LCD displeja, uz pomoć ovog displeja možete na zanimljiv način prikazati šta vam god padne na pamet. 
Veliku primenu nalazi kod masovnog broja simulacija, kojima daje značaj i izgled.
*/

#include <LiquidCrystal.h>        //određujemo bazu za LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definišemo obavezne pinove na LCD displeju
                                  //RS/E/DB4/DB5/DB6/DB7 pinovi po redu
void setup() 
{
  lcd.begin(16,2);  //definišemo LCD displej
}

void loop()
{
  lcd.setCursor(3,0);    //odredimo poziciju na displeju
  lcd.print("TEHNOMAN"); //stavimo šta hoće da se ispisuje
  lcd.blink();           //omogućava blicanje
  delay(3000);           //pauza
  lcd.clear();           //briše se sve sa displeja
  lcd.setCursor(3,1);    //nova pozicija na displeju
  lcd.print("ARDUINO");  //stavimo šta hoće da se ispisuje
  lcd.blink();           //blicanje
  delay(3000);           //pauza
  lcd.clear();         //briše se sve sa displeja
}
