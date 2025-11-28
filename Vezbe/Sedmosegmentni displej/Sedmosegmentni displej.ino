/*
Zadatak ove vežbe je da vas upoznamo sa osnovama rada sedmosegmentnog displeja, uz pomoć ovog displeja možete na zanimljiv i razumljiv način prikazati željene brojke. 
*/

int A=0;   
int B=1;  //definišemo elemente i pozicije sedmosegmentnog displeja
int C=2;  
int D=3;  
int E=4; 
int F=5;    
int G=6;    

void setup() {
  pinMode(A,OUTPUT); //definišemo stanje dioda koje se nalaze u samom displeju
  pinMode(B,OUTPUT); //sve diode su izlaznog tipa
  pinMode(C,OUTPUT); 
  pinMode(D,OUTPUT);   
  pinMode(E,OUTPUT); 
  pinMode(F,OUTPUT);  
  pinMode(G,OUTPUT);   
}

void loop() 
{
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);  //svi elementi na displeju su isključeni
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  delay(500);
  digitalWrite(A,HIGH); //pali se dioda kojoj smo dodelili vrednost A
  delay(500);
  digitalWrite(B,LOW);  //dioda kojoj smo dodelili vrednost B je ugašena
  delay(500);
  digitalWrite(F,HIGH); //pali se dioda kojoj smo dodelili vrednost C
  delay(500);
  digitalWrite(E,LOW);  //dioda kojoj smo dodelili vrednost E je ugašena
  delay(500);
  digitalWrite(G,HIGH); //pali se dioda kojoj smo dodelili vrednost D
  delay(500);
  digitalWrite(C,HIGH); //pali se dioda kojoj smo dodelili vrednost F
  delay(500);
  digitalWrite(D,HIGH); //pali se dioda kojoj smo dodelili vrednost G
  delay(500);
}
