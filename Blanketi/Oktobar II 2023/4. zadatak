void setup(){
  Serial.begin(9600); //omogucava serijsku komunikaciju
}

int posX[10]={2,1,3,5,2,3,4,5,0,9}; //definisemo nizove kao globalne promenljive kako bi mogli da im pristupimo
int posY[10]={1,2,4,5,3,2,1,8,1,9};

int x,y; //takodje definisemo i koordinate X i Y koje korisnik unosi
String unos; //promenljiva tipa string koju unosi korisnik putem serijske komunikacije
bool pogodak=false; //logicka promenljiva koja nam potvrdjuje da smo ostvarili pogodak

void loop(){
  Serial.println("Unesi X koordinatu: ");
  while(true){ //sve dok je petlja tacna onda ce se izvrsavati
    if(Serial.available()>0){ //komanda Serial.available() broji vrednosti smestene u registar mikrokontrolera
      break; //ta vrednost ce biti 0 sve dok korisnik ne unese neku vrednost, nakon toga se povecava, gde mi sa "break" nagovestavamo kraj petlje
    }
  }
  unos=Serial.readString(); //prethodno uneti podatak smestamo u String unos
  x=unos.toInt(); //konvertujemo taj string u INT format i smestamo u promenljivu X
   
  Serial.println("Unesi Y koordinatu: ");
  while(true){ //dok je petlja tacna onda ce se izvrsavati
    if(Serial.available()>0){ //komanda Serial.available() broji vrednost smestenu u registar mikrokontrolera
      break; //ta vrednost ce biti 0 sve dok korisnik ne unese vrednost, gde se povecava, nakon toga mi preko "break" nagovestavamo kraj petlje
    }
  }
  unos=Serial.readString(); //prethodno unetu vrednost smestamo kao String u promenljivu unos
  y=unos.toInt(); //konvertujemo String u INT format i smestamo u promenljivu Y
  Serial.print("Unete koordinate su: ");
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y); //ispisujemo unete koordinate
  
  for(int i=0; i<10; i++){
    if(x==posX[i] && y==posY[i]){ //prolazimo kroz ceo niz, i istovremeno proveravamo da li se nasi parametri nalaze u nizovima
      pogodak=true; //ukoliko
    }
  }
  if(pogodak){
    Serial.println("POGODJEN JE PAR KOORDINATA");
  }else{
    Serial.println("PROMASEN JE PAR KOORDINATA");
  }
  
  pogodak=false;
  delay(200);
}
