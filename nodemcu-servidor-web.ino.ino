/*
Terceiro exemplo de NodeMCU
Um servidor web usando o NODEMCU (ESP8266)
Autor: Henrique Poyatos (adaptando um exemplo de terceiros na Internet)
Data: 24/09/2022
*/

//Vamos incluir uma biblioteca ESP8266 (nodemcu) com conversa com WIFI
#include <ESP8266WiFi.h>

//Vou declarar o SSID e Senha da minha rede....
const char* ssid="SSID DA REDE";
const char* password="SENHA DA REDE";

//Para declarar um servidor Web na porta 80
WiFiServer server(80);

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

  delay(2000); // espera 2 segundos
  server.begin(); // inicializa o servidor web da plaquinha...

  Serial.println("Servidor WEB inicializado no NodeMCU");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  
}

void loop() {

  WiFiClient client = server.available(); //VERIFICA SE ALGUM CLIENTE ESTÁ CONECTADO NO SERVIDOR
  if (!client) { //SE NÃO EXISTIR CLIENTE CONECTADO, FAZ
    return; //REEXECUTA O PROCESSO ATÉ QUE ALGUM CLIENTE SE CONECTE AO SERVIDOR
  }

  Serial.println("Novo cliente se conectou!"); //ESCREVE O TEXTO NA SERIAL
  while(!client.available()){ //ENQUANTO CLIENTE ESTIVER CONECTADO
    delay(1); //INTERVALO DE 1 MILISEGUNDO
  }

  client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
  client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
  client.println("");
  client.println("<!DOCTYPE HTML>"); //INFORMA AO NAVEGADOR A ESPECIFICAÇÃO DO HTML
  client.println("<html>"); //ABRE A TAG "html"
  client.println("<h1><center>Olá cliente!</center></h1>"); //ESCREVE "Ola cliente!" NA PÁGINA
  client.println("<center><font size='5'>Seja bem-vindo!</center>"); //ESCREVE "Seja bem vindo!" NA PÁGINA
  client.println("</html>");

  delay(1); //INTERVALO DE 1 MILISEGUNDO
  Serial.println("Cliente desconectado"); //ESCREVE O TEXTO NA SERIAL
  Serial.println("");
}
