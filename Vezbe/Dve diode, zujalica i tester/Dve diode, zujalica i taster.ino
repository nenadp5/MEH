/*
Zadatak ove vežbe je da se prilikom pritiska na jedan taster određena dioda uključi i zujalica zazuji. 
Ono što je bitno, jeste da će dioda svetleti i zujalica zujati sve dok mi fizički držimo taster pritisnut, odmah nakon puštanja tastera dioda i zujalica se gase.
*/

int t1=0; //definišemo početnu vrednost tastera 
int t2=0; //dajemo vrednosti 0

void setup() //definišemo elemente
{
  pinMode(13,OUTPUT); //dioda na pinu 13 (izlazna informacija)
  pinMode(12,OUTPUT); //dioda na pinu 12 (izlazna informacija)
  pinMode(7,OUTPUT);  //zujalica na pinu 7 (izlazna informacija)
  pinMode(6,OUTPUT);  //zujalica na pinu 6 (izlazna informacija)
  pinMode(4,INPUT);   //taster na pinu 4 (ulazna informacija)
  pinMode(3,INPUT);   //taster na pinu 3 (ulazna informacija)
}

void loop() {
  t1=digitalRead(4); //čita digitalnu naredbu sa pina 4, odnosno tastera 1
  t2=digitalRead(3); //čita digitalnu naredbu sa pina 3, odnosno tastera 2
  
  if(t1==HIGH) //ukoliko je taster t1 pritisnut dešava se sledeća naredba
  {
    digitalWrite(13,HIGH); //dioda na pinu 13 se uključuje, druga je isključena
    digitalWrite(12,LOW);
    tone(7,1000);          //zujalica na pinu 7 zuji određenom frekvencijom
    delay(1000);           //vremenski rok koliko zuji
    noTone(7);             //zujalica više ne zuji
    noTone(6);             //zujalica na pinu 6 ne zuji
  }
  else  //ukoliko taster nije pritisnut dešava se sledeća naredba
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW); //sve je isključeno i ništa ne zuji
    noTone(7);
    noTone(6);
  }
  if (t2==HIGH) //ukoliko je taster t2 pritisnut dešava se sledeća naredba
  {
    digitalWrite(12,HIGH); //dioda na pinu 12 se uključuje, druga je isključena
    digitalWrite(13,LOW);
    tone(6,500);   //zujalica na pinu 6 zuji određenom frekvencijom
    delay(500);    //vremenski rok koliko zuji
    noTone(6);     //zujalica više ne zuji
    noTone(7);     //zujalica na pinu 7 ne zuji
  }
 else   //ukoliko taster nije pritisnut dešava se sledeća naredba
 {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW); //sve je isključeno i ništa ne zuji
    noTone(7);
    noTone(6);
 }
}
