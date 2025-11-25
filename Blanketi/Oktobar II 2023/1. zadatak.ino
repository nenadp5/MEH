void setup(){
  pinMode(A2,INPUT); //definisemo pin za potenciometar(mora biti analogan)kao INPUT
  pinMode(8,INPUT); //definisemo pin za taster kao INPUT
  Serial.begin(9600); //omogucava serijsku komunikaciju
  Serial.println("Sistem je spreman, pritisni taster da prosledis boju!");
}

bool taster=false; //promenljiva koja odredjuje da li je taster ukljucen
int boja; //promenljiva u koju se smesta vrednost za boju

void loop(){
  taster=digitalRead(8); //ucitavamo da li je taseter pritisnut
  if(taster){ //ako je taster pritisnut obavljaju se sledece operacije
    boja=analogRead(A2); //ucitavamo vrednost sa potenciometra i smestamo u promenljivu boja
    Serial.print("Boja je: ");
    Serial.println(boja); //ispisujemo vrednost na serijskom monitoru koju smo dobili
  }
  delay(500);
}
    
/*Buduci da je u zadataku receno SETUP funkciju, mozemo staviti samo
void setup(){
  pinMode(A2,INPUT); //definisemo pin za potenciometar(mora biti analogan)kao INPUT
  pinMode(8,INPUT); //definisemo pin za taster kao INPUT
  Serial.begin(9600); //omogucava serijsku komunikaciju
  Serial.println("Sistem je spreman, pritisni taster da prosledis boju!");
}
sto ce biti prihvaceno kao tacan odgovor
*/
