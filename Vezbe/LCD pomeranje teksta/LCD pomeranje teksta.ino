/*
Zadatak ove vežbe je da se na displeju ispisuje TEHNOMAN i taj tekst pomera levo-desno određeno vreme, nakon čega će ga zameniti tekst DOBAR DAN. 
Takođe, kada pritisnemo taster ispisuje ZDRAVO i broj pritisaka na taster. Ubacićemo neku petlju kako bi vaš rad dobio lepši izgled. 
Naravno pored petlje dodajemo i jedan hardverski element, u pitanju je taster.
*/

#include <LiquidCrystal.h>        //određujemo bazu za LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definišemo obavezne pinove na LCD displeju
                                  //RS/E/DB4/DB5/DB6/DB7 pinovi po redu

int t1=0; //uvodimo celobrojnu vrednost za taster t1
int br=0; //uvodimo brojač

void setup()
{
  lcd.begin(16,2);           //definišemo LCD displej
  lcd.setCursor(0,0);        //određujemo poziciju na displeju
  lcd.print("TEHNOMAN ");   //ispisuje se
  pinMode(7,INPUT);          //određujemo t1

  for (int I=0; I<5; I++)  //pravimo petlju da bi se obavljala sledeća radnja
  {
    lcd.scrollDisplayRight();
    delay(600);            //tekst se pomera u desnu stranu
  }
  for (int I=0; I<5; I++)  //pravimo petlju da bi se obavljala sledeća radnja
  {
    lcd.scrollDisplayLeft();
    delay(600);            //tekst se pomera u levu stranu
  }
}

void loop() {
  int t1=digitalRead(7); //definišemo odakle t1 čita vrednost
  
  if (t1==HIGH)  //ukoliko je taster pritisnut
  {
    lcd.clear();
    delay(2);   //ispisuje se ZDRAVO umesto prethodnog DOBAR DAN
    br++;       //pored toga se ispisuje vrednost brojača
    lcd.setCursor(0,0);
    lcd.print("ZDRAVO");
    lcd.setCursor(0,1);
    lcd.print(br);
  }
  else  //ukoliko taster nije pritisnut
  {
    lcd.clear();  //ispisuje se ista vrednost DOBAR DAN i pomera levo-desno
    delay(2);
    lcd.setCursor(0,0);
    lcd.print("DOBAR DAN");
  }
  delay(300);

}
