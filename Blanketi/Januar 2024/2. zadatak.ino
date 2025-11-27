int polozili=0;
float uspesnost; //globalne promenljive u koje ce biti smestene vrednosti

int pismeni[5]={30,20,100,13,43};
int usmeni[5]={33,22,98,49,20}; //nizovi sa 5 rezultata, ovo je drugi nacin gde smo mi jasno odredili koliko imamo elemenata
void setup()
{
  Serial.begin(9600); //omogucava serijsku komunikaciju
  for(int i=0; i<5; i++){ //prolazimo kroz sve elemente niza, ovde nismo koristili sizeof jer smo striktno rekli da imamo 5 elemenata
    if(pismeni[i]>=25 && usmeni[i]>=25){
      polozili++; //istovremeno oba elemenata niza moraju biti veci od 25 kako bi zadovoljili uslov i obavili inkrementiranje
    }
  }
  uspesnost=(polozili/5.0)*100;  //procenat=(deo/celo)*100
  Serial.print("Ukupan broj studenata koji su polozili je: ");
  Serial.println(polozili); //ispisujemo podatke
  Serial.print("Procenat uspesnosti je: ");
  Serial.println(uspesnost);
  delay(2000);
}

void loop(){} //sve je smesteno u setup kako ne se ne bi bespotrebno vise puta izvrsavalo
