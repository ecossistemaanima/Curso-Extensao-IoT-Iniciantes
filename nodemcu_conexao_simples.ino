/*
Segundo exemplo de NodeMCU
Conectando o NODEMCU (ESP8266) em uma Rede Wifi
Autor: Henrique Poyatos
Data: 24/09/2022
*/

//Vamos incluir uma biblioteca ESP8266 (nodemcu) com conversa com WIFI
#include <ESP8266WiFi.h>

//Vou declarar o SSID e Senha da minha rede....
const char* ssid="SSID DA REDE";
const char* password="SENHA DA REDE";

void setup() {
  //Inicializar a Serial.
  Serial.begin(115200);
  delay(100); // espera 0.1 segundo....
  
  //Realizar conexão com a rede WIFI
  Serial.print("\nConectando a "); //ESCREVE O TEXTO NA SERIAL
  Serial.print(ssid);

  WiFi.begin(ssid, password); // Passa o ssid e a senha para a biblioteca de conexão

  while (WiFi.status() != WL_CONNECTED)  //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
  { 
    delay(500); //INTERVALO DE 500 MILISEGUNDOS
    Serial.print("\nVou tentar de novo..."); //ESCREVE O CARACTER NA SERIAL
  }

  Serial.print("\nConectado a rede sem fio "); //ESCREVE O TEXTO NA SERIAL
  Serial.println(ssid);
}

void loop() {

}
