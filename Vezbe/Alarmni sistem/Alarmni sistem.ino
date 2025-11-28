/*
Simulirati sistem uz pomoc PIR senzora, zujalice i serijskog monitora
U zavisnosti od toga da li je PIR aktivan ispisuje se odgovarajuca poruka na serijskom monitoru,
aktivira se dioda i zujalica zuji.
*/

int b=0; //uvodimo brojač

void setup()
{
  pinMode(2, OUTPUT); //definišemo diodu
  pinMode(8, OUTPUT); //definišemo zujalicu
  pinMode(5, INPUT);  //definišemo senzor
  Serial.begin(9600); //omogućavamo rad monitora
}

void loop()
{
  int PIR=digitalRead(5);  //uvodimo vrednost PIR i određujemo odakle da čita vrednost
  
  if(PIR==HIGH) //ukoliko senzor nešto detektuje obavlja se sledeća operacija
  {
    digitalWrite(2,HIGH);
    tone(8,1000);         //dioda počinje da svetli i zujalica da zuji
    b++;
    Serial.print("UPOZORENJE "); //na monitoru se ispisuje UPOZORENJE i stanje brojača
    Serial.println(b);
    delay(150);
  }
  
  else //ukoliko senzor ništa ne detektuje obavlja se sledeća operacija
  {
    digitalWrite(2,LOW);
    noTone(8);
    Serial.println("BEZBEDNO "); //ništa ne svetli i ništa ne zuji
    delay(150);                  //na monitoru se ispisuje BEZBEDNO
  }

}
