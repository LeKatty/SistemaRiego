#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;
#define DHT11_PIN 9

int relayPin = 8;
int sensor_pin = A0; // El sensor de humedad conectado al pin A0
int output_value;

LiquidCrystal lcd(7,6,5,4,3,2);

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
    //TEMPERATURA//
  DHT.read11(DHT11_PIN);
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature);
  Serial.println(" C");
 output_value = analogRead(sensor_pin);
 output_value = map(output_value,550,10,0,100);
 Serial.print("Humedad: ");
 Serial.print(output_value);
 Serial.println("%");
 if(output_value>20){
  digitalWrite(relayPin, LOW);
 }
 else
 {
  digitalWrite(relayPin, HIGH);       
 }

lcd.setCursor(0,0);
 lcd.print("Santiago mamon");
 delay(1000);
}
