void setup(){
  Serial.begin(9600); //omogucava serijsku komunikaciju
  pinMode(A3,INPUT); //definisemo pin za potenicometar kao INPUT i obavezno je analogan
}

float ucitaj(int pin){ //metoda za racunanje vrednosti, prosledjeni parametar je broj pina
  float x=analogRead(pin); //uz pomoc analogRead citamo vrednost sa prosledjenog pina
  float mV=x*(5/1023.0); //pretvaramo ocitanu vrednost u mV
  float y=mV*3-2*(mV*mV); //racunamo vrednost po formuli
  return y; 
}

void loop(){
  float y=ucitaj(A3); //pozivamo metodu za racunanje vrednosti i to odmah smestamo u promenljivu y
  Serial.print("Ucitana vrednost je: ");
  Serial.println(y); //ispisujemo podatke
}
  
