void setup(){
	Serial.begin(9600); //omogucava serijsku komunikaciju
}
int jmbg[13]={1,5,0,2,0,0,5,1,2,3,4,5,6}; //niz koji predstavlja JMBG definsan kao globalna promenljiva
int godina;
int danR; //promenljive u koje cemo smestiti vrednosti
int mesecR;
int godinaR;
bool maloletno=true; //logicka promenljiva koja se trazi u tekstu
void loop(){
  danR=jmbg[0]*10+jmbg[1]; //dan dobijamo uz pomoc ove formule
  mesecR=jmbg[2]*10+jmbg[3]; //mesec dobijamo uz pomoc date metode
  godina=jmbg[4]*100+jmbg[5]*10+jmbg[6];
  if(godina>=900){ //ako je godina veca od 900 na nju dodajemo 1000 kako bi zadatak imao smisla
    godinaR=1000+godina;
  }
  else{
    godinaR=2000+godina; //u suprotnom dodajemo 2000 
  }
  
  Serial.println("Podaci: ");
  Serial.print("Dan rodjenja: ");
  Serial.println(danR);
  Serial.print("Mesec rodjenja: ");
  Serial.println(mesecR);
  Serial.print("Godina rodjenja: ");
  Serial.println(godinaR);
  delay(599); //ispisujemo date podatke i stavljamo delay samo radi ispravnog zapisa
  if(godinaR<2007){ //stavljamo uslov koji se trazi u okviru zadatka
	maloletno=false;
  }
  else{
    maloletno=true;
  }
}
  
