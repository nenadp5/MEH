int usmeni[]={13,25,44,2,15}; //definisemo nizove kao globalne promenljive
int pismeni[]={22,26,34,45,22};
int polozili=0; //promenljiva za broj osoba koje su polozile
float uspesnost=0; //promenljiva za uspesnost
void setup(){
  Serial.begin(9600); //omogucava serijsku komunikaciju
  int n=sizeof(usmeni)/sizeof(usmeni[0]); //predstavlja ukupan broj elemenata u nizovima, sizeof(usmeni) racuna velicinu celog niza, dok sizeof(usmeni[0]) samo velicinu jednog elementa
  for(int i=0; i<n; i++){ //prolazimo kroz nizove
    if(usmeni[i]>=25 && pismeni[i]>=25){ //istovremeno moraju da budu zadovoljeni uslovi da su vrednosti u oba niza veca od 25
      polozili++; //povecavamo broj osoba koje su polozili ispit
    }
  }
  float m=sizeof(usmeni); //racunamo velicinu niza usmeni, treba nam zbog racunanja procenta
  uspesnost=((polozili/m)*100.); //formula po kojoj racunamo procenat osoba koje su polozile
  Serial.print("Broj osoba koji su polozili ispit je: ");
  Serial.println(polozili);
  Serial.print("Uspesnost: "); //ispisujemo odgovarajuce poruke
  Serial.println(uspesnost);
  delay(2000);
}

void loop(){} //sve smo smestili u okviru setup funkcije kako bi se izvrsilo jednom a ne bespotrebno veliki broj puta
