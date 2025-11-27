void setup(){
  pinMode(7,INPUT); //definisemo pinove za tastere, moraju biti INPUT
  pinMode(10,INPUT);
  Serial.begin(9600); //omogucava serijski prenos
}

bool taster1=false;
bool taster2=false; //logicke promenljive koje odredjuju koji taster je pritisnut
int stanje=0;

void loop(){
  taster1=digitalRead(7); //buduci da su povezani na digitalne pinove, onda imamo digitalRead
  taster2=digitalRead(10);
  if(taster1){ //ako je aktivan prvi taster onda se obavlja inkrementiranje stanja
    stanje++;
    delay(200);
  }
  if(taster2){ //ako je aktivan drugi taster obavlja se dekrementiranje vrednosti
    stanje--;
    delay(200); //imamo delay kako bi se brojac normalno menjao
  }
  Serial.print("Stanje brojaca je: ");
  Serial.println(stanje); //ispisujemo stanje
  delay(100);
}
