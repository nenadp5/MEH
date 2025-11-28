/*
Realizovati sistem za senzor distance, uz pomoc senzora za daljinu, LCD ekrana, zujalice i dioda.
U zavisnosti od daljine treba se ukljucivati odgovarajuca dioda, a kada blizina postane veoma mala, onda se ukljcuje i zujalica.
Sve je propraceno ispisivanjem odgovarajuce poruke na LCD ekranu
*/

#include <LiquidCrystal.h> //određujemo bibilioteku za lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //definišemo pinove za LCD ekran

int trig=10; //određujemo pin za trig na senzoru
int echo=9;  //određujemo pin za echo na senzoru
float vreme,distanca,inc; //uvodimo decimalne vrednosti za određene elemente

void setup()
{
  lcd.begin(16,2);      //omogućavamo rad LCD displeja
  Serial.begin(9600);   //omogućavamo rad serijskog monitora
  pinMode(trig,OUTPUT); //određujemo stanje trig elementa
  pinMode(echo,INPUT);  //određujemo stanje echo elementa
  pinMode(8,OUTPUT);    //pin za zujalicu
  pinMode(7,OUTPUT);    //pin za diodu
  pinMode(6,OUTPUT);    //pin za diodu
  pinMode(13,OUTPUT);   //pin za diodu
}

void loop()
{
  digitalWrite(trig,LOW); //omogućava rad senzora
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  vreme=pulseIn(echo,HIGH);  //način dobijanja vrednosti za vreme
  distanca=(vreme*0.0343)/2; //način dobijanja vrednosti za distancu u cm
  inc=(distanca)/2.54;       //način dobijanja vrednosti za distancu u inčima
  
  Serial.println();
  Serial.print("Distanca je: "); //na serijskom monitoru se ispisuje kolika je distanca
  Serial.print(distanca);        //u centimetrima i inčima
  Serial.print("cm");
  Serial.println();
  Serial.print("Distanca je: ");
  Serial.print(inc);
  Serial.print("inca");
  
  if(distanca>=50) //ukoliko distanca odgovara uslovu
  {
    lcd.clear();
    digitalWrite(13,HIGH);  //svetli zelena dioda dok su sve ostale ugašene
    digitalWrite(7,LOW);    
    digitalWrite(6,LOW);
    noTone(8);              //dioda ne zuji
    lcd.setCursor(0,1);
    lcd.print("DOBRA DALJINA"); //na LCD monitoru se ispisuje DOBRA DALJINA
    delay(1000);
  }
  else if (distanca>=30 && distanca<50) //ukoliko distanca odgovara uslovu
  {
    lcd.clear();
    tone(8,1000);          //dioda zuji određenom frekvencijom
    digitalWrite(6,HIGH);  //svetli žuta dioda dok su sve ostale ugašene
    digitalWrite(7,LOW);
    digitalWrite(13,LOW);
    lcd.setCursor(0,1);
    lcd.print("SREDNJA DALJINA"); //na LCD monitoru se ispisuje SREDNJA DALJINA
    delay(1000);
  }
  else if (distanca<30) //ukoliko distanca odgovara uslovu
  {
    lcd.clear();
    tone(8,1500);          //dioda zuji određenom frekvencijom
    digitalWrite(7,HIGH);  //svetli crvena dioda dok su sve ostale ugašene
    digitalWrite(13,LOW);
    digitalWrite(6,LOW);
    lcd.setCursor(0,1);
    lcd.print("PAZI");    //na LCD monitoru se ispisuje PAZI
    delay(1000);
  }
  delay(1000);
}
