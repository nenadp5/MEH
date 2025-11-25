#include <LiquidCrystal.h> //ukljucujemo biblioteku koja omogucava rad sa LCD ekranom
LiquidCrystal lcd(12,11,7,6,5,4); //definisemo pinove koji se koriste kod LCD

void setup(){ 
  pinMode(A2,INPUT); //definisemo pin za temperaturni senzor,u pitanju je analogni i to INPUT
  lcd.begin(16,2); //obavezan deo gde definisemo broj kolona i vrsta kod LCD ekrana
}

int senzor; 
float readTemp(){ //funkcija za citanje temperature
  senzor=analogRead(A2); //ucitavamo vrednost sa temperaturnog senzora, buduci da je analogni pin, ide analogRead
  float napon=senzor*(5.0/1023.0); //formula za racunanje napona na osnovu vrednosti sa senzora
  float temperatura=(napon/0.1)+13.54; //formula za racunanje temperature na osnovu napona
  return temperatura; //povratna vrednost je rezultat temperature
}

void loop(){
  float temp=readTemp(); //pozivamo metodu za racunanje temperature
  lcd.setCursor(0,0); //pozicioniramo kursor na LCD ekranu
  lcd.print("Temp: "); //ispisujemo poruku na LCD ekranu, zato i imamo ovo lcd. ispred svake narede vezane za LCD
  lcd.print(temp);
}
