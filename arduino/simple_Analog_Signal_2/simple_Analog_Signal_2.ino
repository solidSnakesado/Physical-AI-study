const int LED           = 9;
const int LED_MAX       = 255;
const int LED_MIN       = 0;
const int LED_CHECK_VAL = 10;
const int DELAY_VAL     = 10;

int maxVal;
int minVal;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  maxVal = 0;
  minVal = 1023;
  analogWrite(LED, 0);
}

void loop() 
{
  int light = analogRead(A0);
  if (maxVal < light)
  {
    maxVal = light;
  }
  else if(minVal > light)
  {
    minVal = light;
  }

  int output = LED_MAX - map(light, minVal, maxVal, LED_MIN, LED_MAX);
  
  if (output > LED_CHECK_VAL)
  {
    analogWrite(LED, output);
    delay(DELAY_VAL);
  }
  else
  {
    analogWrite(LED, LED_MIN);
    delay(DELAY_VAL);
    output = LED_MIN;
  }

  Serial.print(maxVal);
  Serial.print(", ");
  Serial.print(output);
  Serial.print(", ");
  Serial.println(minVal);
}
