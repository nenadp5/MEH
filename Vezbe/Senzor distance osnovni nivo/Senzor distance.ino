/*
Simulirati sistem za merenje distance uz pomoc senzora distance i LCD ekrana, gde se na LCD ispisuje distanca u centimetrima i incima
*/

#include <LiquidCrystal.h>  //uvodimo biblioteku za LCD
LiquidCrystal lcd (12,11,5,4,3,2); //definišemo pinove na LCD
int trig=8;    //pin koji smo koristili za trig kod senzora
int echo=9;    //pin koji smo koristili za echo kod senzora

float vreme,distanca,inch; //uvodimo decimalne vrednosti za određene elemente

void setup()
{
  lcd.begin(16,2);      //definišemo LCD
  pinMode(trig,OUTPUT); //određujemo stanje za trig
  pinMode(echo,INPUT);  //određujemo stanje za echo
  Serial.begin(9600);   //omogućavamo rad serijskom monitora
}

void loop() {
  digitalWrite(trig,LOW); //omogućavamo rad trig elementa
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
   vreme=pulseIn(echo,HIGH);  //definišemo način računanja vremena
   distanca=(vreme*0.0343)/2; //definišemo način računanja distance preko centimetra
   inch=distanca/2.54;        //definišemo način računanja distance preko inča
  Serial.print("Distanca: "); 
  Serial.print(distanca);     //u serijskom monitoru ispisujemo vrednost distance
  Serial.println();
  lcd.setCursor(0,0);
  lcd.print("Distanca je: "); //na LCD monitoru ispisuje vrednost distance
  lcd.setCursor(0,1);
  lcd.print(distanca);
  lcd.print("cm");      //distanca se ispisuje u centimetrima na LCD
  delay(10);
  lcd.setCursor(8,1);
  lcd.print(inch);
  lcd.print("inca"); //distanca se ispisuje u inčima na LCD
  delay(1000); //pauza

}
