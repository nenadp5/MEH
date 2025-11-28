/*
Realizovati proces brojenja ljudi unutar jedne prostorije. Ova simulacije je poznata pod nazivom "Korona brojač" gde je bilo važno koliko se ljudi nalazi unutar prostorije.
Prilikom pritiska odgovarajućeg tastera broj se povećava ili smanjuje. Kada dostigne maksimum, u našem slučaju 5, ispisuje se ZABRANJEN ULAZ i taj tekst treperi.
*/

#include <LiquidCrystal.h>        //određujemo bazu za LCD
LiquidCrystal lcd(12,11,5,4,3,2); //definišemo obavezne pinove na LCD displeju
                                  //RS/E/DB4/DB5/DB6/DB7 pinovi po redu

int t1=0; //uvodimo celobrojnu vrednost za taster t1
int t2=0; //uvodimo celobrojnu vrednost za taster t2
int br=0; //uvodimo brojač

void setup()
{
  lcd.begin(16,2);   //definišemo LCD displej
  pinMode(7,INPUT);  //definišemo diodu
  pinMode(6,INPUT);  //definišemo diodu
  lcd.setCursor(0,0);        //određujemo poziciju na displeju
  lcd.print("Broj osoba: "); //ispisuje se
  lcd.print(br);             //stanje brojača
}

void loop() 
{
  t1=digitalRead(7);  //čita vrednost sa tastera t1 
  t2=digitalRead(6);  //čita vrednost sa tastera t2
  
  if(t1==HIGH && br<5) //ukoliko je taster t1 pritisnut i brojač manji od 5 obavlja se
  {
    br++;           //vrednost brojača se povećava
    lcd.setCursor(12,0);
    lcd.print(br);  //ispisuje se vrednost brojača 
  }

 if(t2==HIGH && br>0) //ukoliko je taster t2 pritisnut i brojač veći od 0 obavlja se
  {
    br--; //vrednost brojača se smanjuje
    lcd.clear();
    lcd.print("Broj osoba: "); //briše sve sa LCD ekrana
    lcd.setCursor(12,0);
    lcd.print(br);   //ispisuje se vrednost brojača
  }

 if (br==5) //ukoliko je vrednost brojača jednaka sa 5
  {
    lcd.clear();         //sav tekst se briše sa displeja
    lcd.setCursor(0,1);  //nova pozicija na displeju
    lcd.print("Zabranjen ulaz"); //ispisuje se nov tekst na displeju
    lcd.noDisplay(); 
    delay(250);         //obavlja se treperenje samog tekst
    lcd.display();
    delay(250);
  }
  delay(330); //pauza
}
