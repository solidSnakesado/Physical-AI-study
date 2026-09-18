const int BAUD = 9600;

void setup() 
{
  Serial.begin(BAUD);
}

void loop() 
{
  int light = analogRead(A0);
  Serial.println(light);

  delay(20);
}
