/*
Zadatak ove vežbe je da se prilikom promene vrednosti na potenciometru određena dioda uključi i zujalica zazuji. 
Ono što je bitno, jeste da morate dobro podesiti delay kako vam ne bi dolazilo do blicanja određene diode. 
Takođe polako okrećite potenciometar kako bi sve radilo kako treba.
*/

void setup() //definišemo elemente
{
  pinMode(13,OUTPUT);  //dioda na pinu 13 (izlazna informacija)
  pinMode(12,OUTPUT);  //dioda na pinu 12 (izlazna informacija)
  pinMode(11,OUTPUT);  //dioda na pinu 11 (izlazna informacija)
  pinMode(10,OUTPUT);  //zujalica na pinu 10 (izlazna informacija)
  pinMode(A0,INPUT);   //potenciometar na analognom pinu A0 (ulazna informacija)
}

void loop() 
{
  int pot=analogRead(A0);      //uvodimo celobrojnu vrednost za potenciometar
                               //i dajemo naredbu da čita vrednosti sa pina A0
  int led=map(pot,0,1023,0,255); //vršimo mapiranje potenciometra i diode
  
  if (led<=50) //ukoliko je vrednost na potenciometru ovakva obavlja se sledeća naredba
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW); //sve diode svetle i ništa ne zuji
    digitalWrite(11,LOW);
    noTone(10);
  }
  else if (led>51 && led<=125)  //ukoliko je vrednost na potenciometru ovakva obavlja se sledeća naredba
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW); //dioda na pinu 13 svetli i zujalica zuji određenom frekvencijom
    digitalWrite(11,LOW);
    tone(10,500);
  }
  else if (led>126 && led<=200)  //ukoliko je vrednost na potenciometru ovakva obavlja se sledeća naredba
  {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);  //dioda na pinu 12 svetli i zujalica zuji određenom frekvencijom
    digitalWrite(11,LOW);
    tone(10,1000);
  }
  else //ukoliko je vrednost na potenciometru neka koja nije navedena od prethodnih obalja se sledeća naredba
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);  //dioda na pinu 11 svetli i zujalica zuji određenom frekvencijom
    digitalWrite(11,HIGH);
    tone(10,500);
  }
}
