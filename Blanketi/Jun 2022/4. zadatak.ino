void setup(){
 Serial.begin(9600); //omogucava serijsku komunikaciju
}
String unos;
float pk;
float index;
bool status=false;
void loop(){
  Serial.println("Unesi decimalni broj: ");
  while(true){ //petlja se izvrsava sve dok je uslov ispunjen
    if(Serial.available()>0){ //Serial.available() broji koliko elemenata ima u registru mikroprocesora
      break; //odmah cim se ucita neka vrednost, izvrsava se break i prekida se prethodna while petlja
    }
  }
  unos=Serial.readString(); //prethodno unetu vrednost prebacujemo u string
  index=unos.indexOf("."); //trazimo da li postoji negde . uz pomoc indexOf()
  if(unos.length()==5 && index==2){ //ako je duzina (odredjujemo uz pomoc .lenght()) jednaka sa 5 i imamo prisutnu tacku
    status=true; //stavljamo da je zadovoljen trazen uslov
    for(int i=0; i<unos.length(); i++){ //prolazimo kroz ceo broj kao kroz niz
      if(i==index){
        continue; //kada brojac i naidje na indeks onda ga presakce da ne bi izbacilo gresku
      }
      if(!isDigit(unos[i])){ //proverava da li su elementi brojevi uz pomoc komande "isDigit"
        status=false;
      }
    }
  }
  if(status){ //na osnovu statusa koji smo definisali u prethodnom koraku odredjujemo da li broj tacan
    pk=unos.toFloat(); //konvertujemo unetu vrednost u format sa decimalnom vrednoscu
    Serial.print("Uneti broj je: ");
    Serial.println(pk); //ispisujemo podataka
  }
  else{
    Serial.println("Greska pri unosu!"); //ispisujemo poruku ukoliko imamo gresku
  }
 status=false; //restartujemo na pocetnu vrednost
}
