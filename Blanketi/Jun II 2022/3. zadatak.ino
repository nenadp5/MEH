void setup(){
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(2,INPUT); //definisemo digitalne pinove za tastere kao INPUT
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(10,OUTPUT); //predstavlja izlaz za motor, ovde nije hardverski realizovan jer nema takve komponente
  Serial.begin(9600); //omogucava serijsku komunikaciju
}
int osovina=0; //promenljiva namenjena za brojanje pomeranja osovine

void kontrolaMotora(){ //metoda za promenu polozaja motora i osovine
  int taster0=digitalRead(5);
  int taster1=digitalRead(6); //ucitavamo koji pin je aktivan, buduci da su povezani na digitalne pinove, onda ide "digitalRead"
  int taster2=digitalRead(2);
  int taster3=digitalRead(3);
  int taster4=digitalRead(4);
  if(osovina>-45 && osovina<40){ //receno je da je opseg izmedju -45 i 40
    if(taster0==HIGH){
      osovina=osovina-5; //ako je aktivan taster0 osovina se smanjuje za 5
          Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
    }
    if(taster1==HIGH){
      osovina=osovina-1; //ako je aktivan taster1 osovina se smanjuje za 1
          Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
    }
    if(taster2==HIGH){
      osovina=0; //ako je aktivan taster2 osovina se restartuje na nulti polozaj
          Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
    }
    if(taster3==HIGH){ //ako je aktivan taster3 osovina se poveca za 1
      osovina=osovina+1;
          Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
    }
    if(taster4==HIGH){ //ako je aktivan taster3 osovina se povecava za 10
      osovina=osovina+10;
          Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
    }
  }
  else{ //ako se prekoraci definisan opseg onda se ispisuje odgovarajuca poruka
	Serial.println("Prekoracen je opseg osovina!");
    Serial.print("Trenutni opseg je:");
    Serial.println(osovina);
  }
}

void loop(){
  kontrolaMotora(); //u okviru loop samo pozivamo metodu za kontrolu motora
  delay(200);
}
