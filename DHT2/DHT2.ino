#include "DHT.h"

#define DHTPIN 12   

#define DHTTYPE DHT11   

 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Prueba de conexion"));

  dht.begin();
}

void loop() {
  delay(2000);

  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if ( isnan(t) || isnan(f)) {
    Serial.println(F("No hay conexion"));
    return;
  }

 
  Serial.println(F("Temperatura en °C "));
  Serial.print(t);
  Serial.println(F("Temperatura en °F "));
  Serial.print(f);
  
}
