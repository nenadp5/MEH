#include <LiquidCrystal.h> //uvodimo biblioteku za rad sa LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definisemo pinove za LCD
void setup(){
  lcd.begin(16,2); //definisemo broj redova i kolona za lcd
  pinMode(A0,INPUT); //namenjeno za naponski razdelnik i zato je analogni ulaz
}

float minV=7.2; //date vrednosti u okviru zadatka
float maxV=9.6;
float stanje;
float procenat;
void loop(){
  stanje=analogRead(A0); //ucitavamo vrednost sa naponskog razdelnika
  stanje=(stanje*5/1023.)*2; //prebacujemo u mV i imamo *2 jer je u pitanju naponski razdelnik
  procenat=((stanje-minV)/(maxV-minV))*100; //racunanje procenta po datoj formuli
  procenat=round(procenat); //uz pomoc round vrsimo zaokruzivanje vrednosti
  lcd.setCursor(0,0); //postavljamo kursor LCD na zeljenu poziciju i potom ispisujemo vrednosti
  lcd.print("Napon: ");
  lcd.print(stanje);
  lcd.setCursor(0,1);
  lcd.print("Procenat: ");
  lcd.print(procenat);
}
