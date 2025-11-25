void setup(){
 Serial.begin(9600); //aktiviramo serijsku komunikaciju
}

float izracunaj_sumu(int k,int n){ //kreiramo funkciju koja kao prosledjene parametre ima parametre n i k
  float sum=0; //pomocna promenljiva u koju ce biti smestena vrednost na kraju
  for(int i=2; i<=n; i++){ //brojac nam krece od 2 i ide do n, jer se u okviru zadatka trazi suma od 2 do n
	sum+=i*(k+2); //sumiramo vrednost na osnovu datog izraza
  }
  return sum; //vracamo vrednost izracunate sume
}

void loop(){
 float rezultat; //promenljiva suma
 rezultat=izracunaj_sumu(2,5); //pozivamo prethodno kreirano sumu, i njen rezultat smestamo u promenljivu
 Serial.print("Rezultat je: ");
 Serial.println(rezultat); //ispisujemo dobijeni rezultat na serijski monitor
 delay(500); //stavili smo delay kako bi malo bolje izgledalo na serijskom monitoru
}

/*Buduci da je u zadatku trazena samo funkcija, mozemo napisati
float izracunaj_sumu(int k,int n){ //kreiramo funkciju koja kao prosledjene parametre ima parametre n i k
  float sum=0; //pomocna promenljiva u koju ce biti smestena vrednost na kraju
  for(int i=2; i<=n; i++){ //brojac nam krece od 2 i ide do n, jer se u okviru zadatka trazi suma od 2 do n
	sum+=i*(k+2); //sumiramo vrednost na osnovu datog izraza
  }
  return sum; //vracamo vrednost izracunate sume
}
ali uz pomoc ostatka koda, mi omogucavamo rad na Arduino platformi */
