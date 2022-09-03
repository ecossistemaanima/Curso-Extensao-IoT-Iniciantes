// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  digitalWrite(4, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(4, LOW);
  delay(100); // Wait for 100 millisecond(s)
}