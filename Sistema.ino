#include <LiquidCrystal.h>


float porcentaje;
int valorAbs;

int tiempoS = 0;
int tiempoM = 0;
int tiempoH = 0;

int tiempoS2 = 0;
int tiempoM2 = 0;
int tiempoH2 = 0;

int relayPin = 8;
int sensor_pin = A0; // El sensor de humedad conectado al pin A0
int output_value;


const int rs = 7, en = 6, d4= 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4,d5,d6,d7);

void setup()         
{ 
  Serial.begin(9600);                 
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  pinMode(9, INPUT);
  Serial.println("Leyendo desde el sensor...");
  delay(2000);

   //setup Pantalla
  lcd.begin(16, 2);

}

void loop()
{
 output_value = analogRead(sensor_pin);
valorAbs = abs((output_value) - 1024);
porcentaje = (valorAbs/1024.0)*100.0;
Serial.print("VA:");
 Serial.print(valorAbs);
 Serial.print(" ");
 Serial.print("OV:");
 Serial.print(output_value);
 Serial.print(" ");
Serial.print("Humedad: ");
 Serial.print(round(porcentaje));
 Serial.println("%");
 if(output_value<307){
  digitalWrite(relayPin, LOW);
    lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Humedad: ");
 lcd.print(round(porcentaje));
 lcd.print("%");
lcd.setCursor(0,1);
 lcd.print("U.R.: ");
 lcd.print(tiempoH);
 lcd.print(tiempoH2);
 lcd.print(":");
  lcd.print(tiempoM);
 lcd.print(tiempoM2);
 lcd.print(":");
   lcd.print(tiempoS);
 lcd.print(tiempoS2);
 }
  else{
  lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Humedad: ");
 lcd.print(round(porcentaje));
 lcd.print("%");
lcd.setCursor(0,1);
 lcd.print("U.R.: ");
 lcd.print(tiempoH);
 lcd.print(tiempoH2);
 lcd.print(":");
  lcd.print(tiempoM);
 lcd.print(tiempoM2);
 lcd.print(":");
   lcd.print(tiempoS);
 lcd.print(tiempoS2);
 }
 
 if (output_value>819){
  digitalWrite(relayPin, HIGH);
  delay(1500);
  digitalWrite
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("Humedad: ");
 lcd.print(round(porcentaje));
 lcd.print("%");
 lcd.setCursor(0,1);
  lcd.print("Regando...");
  tiempoS = 0;
  tiempoS2 = 0;
  tiempoM = 0;
  tiempoM2 = 0;
  tiempoH = 0;
  tiempoH2 = 0;
  ;       
 }

 tiempoS2 = tiempoS2 + 1;
 if (tiempoS2 == 10){
  tiempoS = tiempoS + 1;
  tiempoS2 = 0;
 }

if (tiempoS == 6){
  tiempoM2 = tiempoM2 + 1;
  tiempoS = 0;
  tiempoS2 = 0;
}

 if (tiempoM2 == 10){
  tiempoM = tiempoM + 1;
   tiempoM2 = 0;
 }

 if (tiempoM == 6){
  tiempoH2 = tiempoH2 + 1;
  tiempoM = 0;
  tiempoM2 = 0;
  tiempoS = 0;
  tiempoS2 = 0;
}

 if (tiempoH2 == 10){
  tiempoH = tiempoH + 1;
   tiempoH2 = 0;
 }
  
 Serial.print(tiempoH);
 Serial.print(tiempoH2);
 Serial.print(":");
 Serial.print(tiempoM);
Serial.print(tiempoM2);
Serial.print(":");
   Serial.print(tiempoS);
 Serial.print(tiempoS2);
 delay(1000);
}
