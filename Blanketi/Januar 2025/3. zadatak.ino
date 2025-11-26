void setup(){
  Serial.begin(9600); //omogucava nam serijsku komunikaciju 
}

int posX[10]={2,1,3,5,2,3,4,5,0,9};
int posY[10]={1,2,4,5,3,2,1,8,1,9}; //globalne promenljive namenjene nizovima
int unosX;
int unosY; //promenljive u koje ce biti smestene unete vrednosti
bool pogodak=false; //logicki podataka na osnovu koja odredujemo da li je ostvaren pogodak 
String unos;
void loop(){
  Serial.println("Unesi X koordinatu: ");
  while(true){ //petlja se izvrsava sve dok je tacna
    if(Serial.available()>0){ //uz pomoc Serial.available() brojimo koliko elemenata ima u registru
      break; //cim unesemo neku vrednost, broj elemenata u registru se povecava i aktivira se break
    }
  }
  unos=Serial.readString(); //unetu vrednost prebacujemo u string
  unosX=unos.toInt(); //potom prebacujemo u INT 
  Serial.println("Unesi Y koordinatu: ");
  while(true){ //petlja se izvrsava sve dok je tacna
    if(Serial.available()>0){ //brojimo koliko elemenata ima u registru
      break; //cim unesemo neki podatak broj elemenata u registru se povecava i aktivira se break
    }
  }
  unos=Serial.readString();
  unosY=unos.toInt(); //uneti podatak prebacujemo u string a potom u drugu INT promenljivu
  for(int i=0; i<10; i++){ //prolazimo kroz ceo niz
    if(unosX==posX[i] && unosY==posY[i]){ //proveravamo da li se vrednosti istovremeno poklapaju
      pogodak=true; //ako smo uboli koordinate vrednost se postavlja na true
    }
  }
  if(pogodak){ //u zavisnosti od logicke promenljive vrsimo ispisivanje odgovarajuce poruke
    Serial.println("Koordinate su pogodjene");
  }
  else{
    Serial.println("Koordinate su promasene");
  }
  pogodak=false; //restartujemo vrednost kako u narednom ciklusu ne bi zapamtilo prethodni rezultat
}
