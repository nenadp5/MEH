void setup(){
 Serial.begin(9600); //omogucava serijsku komunikaciju
 pinMode(3,INPUT); //definisemo taster kao INPUT
 pinMode(5,INPUT); //definisemo taster kao INPUT
}

bool taster1=false; //logicka promenljiva za taster, koja je definisana kao FALSE
bool taster2=false; //postaje TRUE kada je taster pritisnut
int staroStanje=-1; //staro stanje sa kojim vrsimo poredjenje, kako bi znali da li je taster stvarno pritisnut
int brojac=0; //brojac koji nam je od interesa

void loop(){
  taster1=digitalRead(3); //ucitavamo stanje tastera
  taster2=digitalRead(5); //buduci da je taster povezan na digitalni pin, onda imamo "digitalRead"
  if(taster1){ 
    brojac++; //ako je pritisnut prvi taster, uvecava se brojac
    delay(200); //delay je stavljen kako bi simulator lepse radio
  }
  if(taster2){ //ako je pritisnut drugi taster
    if(brojac>0){ //proveravamo da li brojac pozitivna vrednost, i ukoliko jeste onda se smanjuje vrednost
      brojac--;
    }
    delay(200); //delay je stavljen kako bi simulator lepse radio
  }
  
  if(brojac!=staroStanje){ //proveravamo da li je brojac razlicit od starog stanje, jer cemo tako utvrditi da li je stanje promenjeno
   Serial.print("Stanje brojaca je: ");
   Serial.println(brojac); //ispisujemo stanje brojaca
   staroStanje=brojac; //staro stanje postaje prethodno stanje brojaca sto ima smisla
  }
  delay(100);
}
