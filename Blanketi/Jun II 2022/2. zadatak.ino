float prethodnoVreme=0;

void ukljuciNavodnjavanje(){ //simulacija funkcije za ukljucivanje navodnjavanja
	Serial.println("Ukljucen je sitem!");
}
void iskljuciNavodnjavanje(){ //simulacija funkcije za iskljucivanje navodnjavanja
	Serial.println("Iskljucen je sistem!");
}

float trajanjeNavodnjavanja=0; //promenljive koje koristimo kako bi odredili pravo vreme navodnjavanja
float vremeIzmedjuNavodnjavanja=0;
float trenutnoVreme=0;

void setup(){
  pinMode(A0,INPUT); //definisemo analogan pin za potenciometar kao INPUT
  pinMode(A1,INPUT); //definisemo analogan pin za potenciometar kao INPUT
  Serial.begin(9600); //omogucava serijsku komunikaciju
  prethodnoVreme=millis(); //uz pomoc komande "millis()" ocitavamo u kojoj sekundi se nalazi Arduino
}

void loop(){
  trajanjeNavodnjavanja=analogRead(A0); //ucitavamo vrednosti sa potenciometra
  vremeIzmedjuNavodnjavanja=analogRead(A1); //buduci da je potenciometar povezan preko analognih pinova onda se koristi AnalogRead
  float trajanje=map(trajanjeNavodnjavanja,0,1023,1000,10000); //uz pomoc komande "map" vrsimo mapiranje sa vrednosti potenciometra na vremenske vrednosti od 1 do 10 sekundi
  float vremeIzmedju=map(vremeIzmedjuNavodnjavanja,0,1023,60000,600000); //mapiramo vrednosti potenciometra na opseg od 1min do 10min
  trenutnoVreme=millis(); //ucitavamo trenutno vreme
  float protekloVreme=trenutnoVreme-prethodnoVreme; //racunamo vremensku razliku
  if(protekloVreme>=trajanjeNavodnjavanja){
    iskljuciNavodnjavanje(); //ako je proteklo vreme vece ili jednako od vremena predvidjenog za navodnjavanje onda se vrsi njegovo iskljucivanje
  }
  if(protekloVreme>=vremeIzmedjuNavodnjavanja){
    ukljuciNavodnjavanje(); //ako je proteklo vreme vece ili jednako od pauze izmedju navodnjavanja onda se ukljucuje sistem za navodnjavanje
  }
  if(protekloVreme>60000){
    prethodnoVreme=trenutnoVreme; //obezbedjuje da nemamo kasnjenje vece od 1min
  }
  delay(500); //kratka pauza radi normalnog rada sistema
}
