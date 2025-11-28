/*
Realizovati senzor distance uz pomoc senzora daljine i dioda. U zavisnosti od daljine ukljucuje se odgovarajuca dioda i ispisuje poruka na serijskom monitoru
*/

int echo=9;  //određujemo pin za echo na senzoru
int trig=10; //određujemo pin za trig na senzoru

float vreme,distanca; //uvodimo decimalne vrednosti za određene elemente

void setup()
{ 
  Serial.begin(9600);   //omogućavamo rad serijskog monitora
  pinMode(13,OUTPUT);   //pin za diodu
  pinMode(12,OUTPUT);   //pin za diodu
  pinMode(11,OUTPUT);   //pin za diodu
  pinMode(trig,OUTPUT); //određujemo stanje trig elementa
  pinMode(echo,INPUT);  //određujemo stanje echo elementa
}

void loop()
{
  digitalWrite(trig,LOW); //omogućava rad senzora
  delayMicroseconds(2);   
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  vreme=pulseIn(echo,HIGH);  //način dobijanja vrednosti za vreme
  distanca=(vreme*0.0343)/2; //način dobijanja vrednosti za distancu
  
  if(distanca>=28 && distanca<=32) //ukoliko se objekat nalazi u ovoj distanci obavlja se
  {
    Serial.println("Srednja distanca");
    digitalWrite(12,HIGH); //na serijskom monitoru se ispisuje SREDNJA DISTANCA
    digitalWrite(13,LOW);  //odgovarajuća dioda svetli
    digitalWrite(11,LOW);
  }
  if (28>=distanca) //ukoliko se objekat nalazi u ovoj distanci obavlja se
  { 
    Serial.println("Previse blizu" );
    digitalWrite(12,LOW); //na serijskom monitoru se ispisuje PREVIŠE BLIZU
    digitalWrite(13,LOW); //odgovarajuća dioda svetli
    digitalWrite(11,HIGH);
  }
  if(distanca>=32) //ukoliko se objekat nalazi u ovoj distanci obavlja se
  {
    Serial.println("Daleko" );
    digitalWrite(12,LOW);  //na serijskom monitoru se ispisuje PREVIŠE BLIZU
    digitalWrite(13,HIGH); //odgovarajuća dioda svetli
    digitalWrite(11,LOW);
  }
  delay(100);
}
