void setup(){
 Serial.begin(9600); //aktivira serijsku komunikaciju
}

float percentil(int n){
 return (n/10000.0)*100; //metoda za racunanje percentila
}

int brojManjihOdK(int K,int S[]){ //prosledjuje se niz i visina
  int br=0; //pomocna promenljiva u koju smestamo broj ljudi
  for(int i=0; i<5; i++){
    if(S[i]<K){ //prolazimo kroz ceo niz i racunamo koliko ljudi je nize od prosledjene visine
      br++;
    }
  }
  return br;
}
  
float per=0;
int manji=0; //promenljive u koje ce biti smesteni rezultati
int niz[5]={123,189,151,111,132}; //niz vrednosti za visine

void loop(){
  manji=brojManjihOdK(150,niz); //pozivamo metodu za racunanje broja ljudi manjih od visine i odmah smestamo u promenljivu
  per=percentil(manji); //pozivamo metodu za racunanje percentila
  Serial.print("Percentil vrednosti u nizu je: ");
  Serial.println(per);
  Serial.print("Broj ljudi nizih od 150: ");
  Serial.println(manji); //prikazujemo dobijene rezultate
  delay(2000);
}

/*
float percentil(int visina,int S[]){
  int manji=brojManjihOdK(visina,S[]);
  return (manji/10000)*100;
}
Ovaj kod je ispravniji, jer smo u okviru metode za racunanje 
percentila ubacili metodu za racunanje broja ljudih manjih od prosledjene vrednosti
*/
