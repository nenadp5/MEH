void setup(){
  pinMode(A1,INPUT); //definisemo pinove za potenciometar i temperaturni senzor
  pinMode(A2,INPUT); //oba moraju biti analogni i to INPUT
  pinMode(4,OUTPUT); //izlazni signal u vidu diode
  Serial.begin(9600); //omogucava serijsku komunikaciju
}

int potTemp=0; //globalne promenljive od interesa
float tempSenz=0;
void loop(){
  int pot=analogRead(A2); //ucitavamo vrednost sa potenciometra, analogni pin i zato ine analogRead
  int temp=analogRead(A1); //ucitavamo vrednost sa senzora, analogni pin i zato ide analogRead
  potTemp=map(pot,0,1023,0,25); //mapiramo vrednost sa potenciometra, sa opsega 0-1023 na 0-25
  tempSenz=map(temp,0,1023,0,40); //mapiramo vrednost sa senzora, sa opsega 0-1023 na 0-40 
  
  Serial.print("Temperatura senzora: ");
  Serial.println(tempSenz); //ispisujemo temperature koje smo dobili
  Serial.print("Temperatura potenciometra je: ");
  Serial.println(potTemp);
  delay(1000);
  
  if(potTemp>=tempSenz){ //poredimo temperature sa senzora i potenciometra
    digitalWrite(4,LOW); //signaliziramo stanje na diodi
    Serial.println("Zadata temperatura na potenciometru je veca!"); //ispisujemo odgovarajucu poruku
    delay(500);
  }
  else{
    digitalWrite(4,HIGH);
    Serial.println("Zadata temperatura na potenciometru je manja!");
    delay(500);
  }
  delay(2000);
}
