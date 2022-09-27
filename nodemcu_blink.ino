/*
Primeiro exemplo de NodeMCU
Piscando o led embarcado de um ESP8266
Autor: Henrique Poyatos
Data: 24/09/2022
*/

// declarando uma constante LED e guardando o número 2
const byte LED = 2;

void setup() {
  // declarar o LED como OUTPUT
  pinMode(LED, OUTPUT);
}

void loop() {
  // acende o led
  digitalWrite(LED, HIGH);
  // aguarde (1 segundos)
  delay(1000);
  // apaga o led
  digitalWrite(LED, LOW);
  // aguarde (1 segundos)
  delay(1000);
}
