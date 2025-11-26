void setup(){
  Serial.begin(9600);
}

String unos;
void loop(){
  Serial.println("Unesi sestocifrenu sifru: ");
  while(true){
    if(Serial.available()>0){ //uz pomoc Serial.available() brojimo koliko elemenata je smesteno u registe Arduina
      break; //cim unesemo nesto, prekida se izvrsenje petlje
    }
  }
  unos=Serial.readString(); //unetu vrednost prebacujemo u string
  if(unos.length()<6){ //proveravamo da li je zadovoljena duzina
    Serial.println("Uneta je krakta neispravna sifra");
    delay(200);
  }
  
  else if(unos.length()>6){
    Serial.println("Uneta je predugacka neispravna sifra");
    delay(200);
  }
  
  else{
    Serial.print("Uneta je ispravna sifra: ");
    Serial.println(unos); //ukoliko je uneta ispravna sifra, vrsimo prikaz poruke i sifre
    delay(200);
  }
}
