/*
Realizovati sistem koji omogucava merenje napona i temperature i njihov prikaz na LCD displeju.
Napon i temperaturu predstavljaju dodatni potenciometar, koji kada vršimo promenu njegove vrednosti, zapravo predstavlja promenu napona i temperature. 
*/

#include <LiquidCrystal.h>        //određujemo bazu za LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definišemo obavezne pinove na LCD displeju
                                  //RS/E/DB4/DB5/DB6/DB7 pinovi po redu

void setup()
{
  lcd.begin(16,2);    //definišemo LCD displej
  pinMode(A0,INPUT);  //definišemo potenciometar
}

void loop()
{
  int pot=analogRead(A0); //uvodimo celobrojnu vrednost za potenciometar
                          //i dajemo naredbu da čita vrednosti sa pina A0
                          
  float u=(0.0048875855)*(pot); //uvodimo decimalnu vrednost za novu promenljivu 
                                //u predstavlja napon čiju smo vrednost prethodno objasnili kako se dobija
                              
  lcd.setCursor(1,0);      //određujemo poziciju na displeju
  lcd.print("Napon je: "); //ispisuje se
  lcd.setCursor(11,0);     //određujemo poziciju na displeju
  lcd.print(u);            //ispisuje se vrednost napona

  float y=(u-0.5)/(0.05); //uvodimo decimalnu vrednost za novu promenljivu 
                          //y predstavlja temperaturu čiju smo vrednost prethodno objasnili kako se dobija
                              
  lcd.setCursor(1,1);      //određujemo poziciju na displeju
  lcd.print("Temp. je: "); //ispisuje se
  lcd.setCursor(11,1);     //određujemo poziciju na displeju
  lcd.print(y);            //ispisuje se vredost temperature
}
