void setup(){ 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); //definisemo diode kao OUTPUT
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600); //omogucava serijsku komunikaciju
}
int brojac=0; //promenljiva namenjena za brojac
void loop(){
  int inkrementiranje=digitalRead(7); //ocitavamo stanje tastera
  int dekrementiranje=digitalRead(8); //vezani su za digitalni ulaz pa je zato digitalRead
  if(inkrementiranje==HIGH){
    brojac++; //ako je taster namenje za inkrementiranje aktivan povecava se brojac
    if(brojac>7){ //granicna vrednost je do 7 jer se sa tri bita maksimalno ta vrednost moze podesiti
      brojac=0; //kada predje 7 vrsi se restartovanje vrednosti
    }
    azurirajPrikaz(); //pozivamo metodu za azuriranje prikaza
  }
  if(dekrementiranje==HIGH){
    brojac--; //ako je aktivan taster za dekrementiranje smanjuje se vrednost brojaca
    if(brojac<0){
      brojac=7; //kada brojac dodje do negativnog stanja, restartujemo vrednost
    }
    azurirajPrikaz(); //pozivamo metodu za prikaz
  }
  Serial.println(brojac); //ispisujemo trenutno stanje brojaca
  delay(500); //imamo delay radi regulacije prikaza
}

void azurirajPrikaz(){ //metoda za azuriranje prikaza
  for(int i=0; i<=3; i++){ //idemo od 0 do 3 zato sto imamo tri diode
    int bitVrednosti=bitRead(brojac,i); //koristimo komandu bitRead koja pretvara dobijeni broj u binarnu notaciju 
    digitalWrite(4+i,bitVrednosti); //imamo 4+i jer su diode smestene od 4 pina pa na dalje, takodje dioda je aktivna ukoliko je bitVrednosti na osnovu prethodne komande pozitivan
  }
}
   
/* Ponovo u tekstu zadatka kaze da treba samo setup() funkcija, sto znaci da mozemo napisati
void setup(){ 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); //definisemo diode kao OUTPUT
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600); //omogucava serijsku komunikaciju
}
medjutim ostatak koda je dobar kako bi bolje razumeli kako funkcionise sistem
*/
