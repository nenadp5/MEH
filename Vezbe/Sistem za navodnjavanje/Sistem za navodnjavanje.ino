/* 
Realizovati sistem za navodnjavanje koriscenjem senzora vlaznosti, LCD ekrana i servo motora.
U zavisnosti od nivoa vlaznosti motor se pomera za odredjeni polozaj i ispisuje se poruka na ekranu
*/

#include <LiquidCrystal.h>  //uvodimo biblioteku za LCD
#include <Servo.h>          //uvodimo biblioteku za servo motor

LiquidCrystal lcd (12,11,5,4,3,2); //definišemo pinove za LCD
Servo motor;  //uvodimo SERVO motor

void setup()
{
  lcd.begin(16,2);   //omogućavamo rad LCD displeja
  pinMode(9,OUTPUT); //izlazni pin na senzoru
  pinMode(A1,INPUT); //ulazni pin na senzoru
  Serial.begin(9600); //omogućava rad serijskog monitora
  motor.attach(9);    //omogućava rad servo motora
  lcd.clear();        //čist ispis na početku
}

void loop()
{
  int senzor=analogRead(A1); //određujemo pin za čitanje
  int procenat=map(senzor,0,1023,0,100); //vršimo mapiranje senzora
  Serial.println(procenat); //na monitoru se ispisuje vrednost vlažnosti

  if (procenat<=60) //ukoliko je procenat u ovoj granici obavlja se sledeća operacija
  {
    lcd.setCursor(0,0); 
    lcd.print("SUVA ZEMLJA"); //na LCD se ispisuje suva zemlja i motor se okreće
    motor.write(30);          //okretanje motora predstavlja podizanje brane ili otvaranje sistema
    delay(1000);
    motor.write(150);
    delay(200);
  }
  else  //ukoliko je procenat različit od prethodnog obavlja se sledeća operacija
  {
    lcd.setCursor(0,0);
    lcd.print("VLAZNA ZEMLJA"); //na LCD se ispisuje suva zemlja i servo motor se ne pokreće
    delay(200);
  }
  lcd.clear();
}
