void setup(){
  pinMode(A2,INPUT); //definisemo pin za potenciometar koji mora biti analogan
  Serial.begin(9600); //omogucava nam serijsku komunikaciju
}
float stanjePot; //promenljiva namenjena za potenciometar
float ocitajNapon(int pinNo){ //metoda koja ocitava vrednost prosledjenog pina
  stanjePot=analogRead(pinNo); //buduci da je analogni pin onda mora ici analogRead
  float stanje=stanjePot*(5./1023); //vrsimo prebacivanje u mV
  stanje=round(stanje*100) / 100.0; //omogucava nam zapis sa decimalnim vrednostima
  return stanje; 
}

void loop(){
 float stanje=ocitajNapon(A2); //pozivamo metodu, prosledjujemo odgovarajuci pin i odmah rezultat smestamo u promenljivu
 Serial.print("Vrednost u milivoltima je: ");
 Serial.println(stanje); //ispisujemo rezultat
  delay(2000);
}
