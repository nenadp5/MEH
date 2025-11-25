void setup(){
  Serial.begin(9600); //omogucava serijsku komunikaciju
}
String novaSifra; //string u koji ce se smestiti uneti podatak
bool velikoSlovo=true; //logicke promenljive koje nam definisu uslove koji se traze
bool broj=true; //primenjena je obrnuta logika, pa je zbog toga sve stavljeno kao TRUE
bool uzvicnik=true;
bool tacka=true;
bool duzina=true;

void loop(){
  Serial.println("Unesi sifru: ");
  while(true){ //petlja se izvrsava sve dok je tacna
    if(Serial.available()>0){ //komanda "Serial.available()" broji koliko elemeanta je smesteno u registre mikroprocesora
      break; //kada se neki podatak unese, vrednost u registru se povecava i uz pomoc "break" prekidamo petlju
    }
  }
 novaSifra=Serial.readString(); //unetu vrednost smestamo u string novaSifra
 int Duzina=novaSifra.length(); //brojimo duzinu unetog stringa preko komande .length()
  if(Duzina>=8){
    duzina=false; //ako je duzina veca od 8 elemenata, onda se promenljiva duzina menja i nema greske u tom delu 
  }
  if(novaSifra[0]>'A' && novaSifra[0]<'Z'){
    velikoSlovo=false; //ako se prvi element sifre nalazi u opsegu velikih slova, promenljiva velikoSlovo se menja u false i nema greske u tom delu
  }
  int Tacka=novaSifra.indexOf('.'); //trazimo da li negde u sifri postoji .
  int Uzvicnik=novaSifra.indexOf('!'); //trazimo da li negde u sifri postoji !
  if(Tacka!=-1){ //ako nadje . onda upisuje njen indeks, ukoliko ne nadje onda je vrednost -1, i zbog toga je ovde uslov da bude razlicito od -1
    tacka=false; //menja se vrednost parametra tacka i onda nema greske u tom delu
  }
  if(Uzvicnik!=-1){ //ukoliko je nasao ! u sifri, upisuje se indeks, dok ako nema ! onda upisuje -1
    uzvicnik=false; //ako je naslo ! menja se vrednost parametra uzvicnik i onda nema greske u tom delu
  }
  for(int i=0; i<novaSifra.length(); i++){ //prolazimo kroz celu duzinu sifre i proveravamo svaki element sifre
    if(novaSifra[i]>='0' && novaSifra[i]<='9'){ //proveravamo da li se svaki element nalazi u opsegu brojeva
      broj=false; //receno je da jedan karakter mora da bude broj i zato prolazimo kroz celu sifru kao kroz niz
    } //vrsi se promena ukoliko je uslov zadovoljen i onda nema greske u tom delu koda
  }
  if(velikoSlovo||broj||uzvicnik||tacka||duzina){ //proveravamo koji uslov nije ispunjen
    if(velikoSlovo){ //ukoliko je velikoSlovo TRUE to znaci da je tu prisutna greska i ispisuje odgovarajucu poruku
		Serial.println("Sifra ne pocinje sa velikim slovom!");
    }
    if(broj){
		Serial.println("Sifra nema broj u sebi!");
    }
    if(uzvicnik){
		Serial.println("Sifra nema uzvicnik u sebi!");
    }
    if(tacka){
		Serial.println("Sifra nema tacku u sebi!");
    }
    if(duzina){
		Serial.println("Sifra nije dovoljno dugacka");
    }
  } //uglavnom proverava koja vrednost je ostala na TRUE kako bi utvrdio koja greska je u pitanju i ispisuje odgovarajucu poruku
  else{
    Serial.print("Uneta je dobra sifra!"); //ako su sve vrednosti FALSE to znaci da je uneta dobra sifra
  }
    velikoSlovo=true;
	broj=true;
	uzvicnik=true;
	tacka=true; //restartujemo vrednosti na pocetne
	duzina=true;
}
