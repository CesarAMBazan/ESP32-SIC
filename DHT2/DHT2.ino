/* Conexión con el modulo DHT11 con la ESP32-CAM
 * Por: Paloma Vilchis
 * Modificado por: Cesar Arturo Mejia Bazan
 *
 * Este programa realiza una conexión con el módulo  DHT11 de temperatura
 * Componente     PinESP32CAM
 * DHT11----------GPIO 12
 */
#include "DHT.h" /*Se añade la libreria DHT*/

#define DHTPIN 12  /*Se define el pin en donde estara conectado el módulo*/

#define DHTTYPE DHT11  /*Se define el tipo de módulo DHT, en este caso es el DHT11*/

 
DHT dht(DHTPIN, DHTTYPE); /*Se crea un objeto dht de la clase DHT con el pin y el tipo de módulo definidos anteriormente*/

void setup() {
  Serial.begin(115200); /*Se comienza declarando un serial.begin para imprimir en la pantalla debug*/
  Serial.println(F("Prueba de conexion")); /*Se imprime "Prueba de conexion", se utiliza la funcion F() para enviar una cadena a la memoria del programa en lugar de la RAM de la placa*/ 

  dht.begin(); /*Se inicializa el módulo dht*/
}

void loop() {
  delay(2000);

  float t = dht.readTemperature(); /*Se lee la temperatura del dht en °C*/
  float f = dht.readTemperature(true); /*Se lee la temperatura del dht en °F*/
  
  if ( isnan(t) || isnan(f)) { /*En caso de que alguno de los dos valores NO sea numerico*/
    Serial.println(F("No hay conexion")); /*Se imprimira que no hay conexión con el módulo*/
    return; /*Se termina el programa*/
  }

  /*Se imprimen las temperaturas en °C y °F*/
  Serial.println(F("Temperatura en °C "));
  Serial.print(t);
  Serial.println(F("Temperatura en °F "));
  Serial.print(f);
  
}
