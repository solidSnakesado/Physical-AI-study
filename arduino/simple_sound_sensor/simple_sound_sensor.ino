enum LEDS
{
  LED1 = 2,
  LED2,
  LED3,
  LED4,
  LED5,
  LED6,
  LED7,
  LED8,
};

unsigned long prevLed1Millis;
unsigned long prevLed2Millis;
unsigned long prevLed3Millis;
unsigned long prevLed4Millis;
unsigned long prevLed5Millis;
unsigned long prevLed6Millis;
unsigned long prevLed7Millis;
unsigned long prevLed8Millis;

int led1Interval;
int led2Interval;
int led3Interval;
int led4Interval;
int led5Interval;
int led6Interval;
int led7Interval;
int led8Interval;

int min, max;
int lightCount;
int curLightCount;
int lightState;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  min = 1023;
  max = 0;  
  lightCount = 0;
  lightState = 0;
  curLightCount = 0;
}

void loop() 
{
  unsigned long curMillis = millis();

  int volume = analogRead(A0);
  min = (min > volume) ? volume : min;
  max = (max < volume) ? volume : max;

  int light = map(volume, min, 300, 0, 255);    // 평화로운 테스트를 위해 최대값을 300 으로 지정

  if (volume > 1000)
  {
    lightCount = 8;
  }

  if (lightState == 0 && lightCount == 8) 
  {
    lightState = 1;
    prevLed1Millis = millis();
    prevLed2Millis = millis();
    prevLed3Millis = millis();
    prevLed4Millis = millis();
    prevLed5Millis = millis();
    prevLed6Millis = millis();
    prevLed7Millis = millis();
    prevLed8Millis = millis();
    analogWrite(LED1, 255);
    curLightCount = 1;
  }

  if (lightState == 1 && lightCount == 8)
  {
    if (curMillis - prevLed2Millis > 300)
    {
      analogWrite(LED2, 255);
      curLightCount = 2;
    }
    if (curMillis - prevLed3Millis > 600)
    {
      analogWrite(LED3, 255);
      curLightCount = 3;
    }
    if (curMillis - prevLed4Millis > 900)
    {
      analogWrite(LED4, 255);
      curLightCount = 4;
    }
    if (curMillis - prevLed5Millis > 1200)
    {
      analogWrite(LED5, 255);
      curLightCount = 5;
    }
    if (curMillis - prevLed6Millis > 1500)
    {
      analogWrite(LED6, 255);
      curLightCount = 6;
    }
    if (curMillis - prevLed7Millis > 1800)
    {
      analogWrite(LED7, 255);
      curLightCount = 7;
    }
    if (curMillis - prevLed8Millis > 2100)
    {
      analogWrite(LED8, 255);
      curLightCount = 8;
    }
  }

  if (lightState == 1 && lightCount == curLightCount)
  {
    lightState = 0;
    prevLed1Millis = millis();
    prevLed2Millis = millis();
    prevLed3Millis = millis();
    prevLed4Millis = millis();
    prevLed5Millis = millis();
    prevLed6Millis = millis();
    prevLed7Millis = millis();
    prevLed8Millis = millis();
  }

  if (lightState == 0 && lightCount > 8)
  {
    if (curMillis - prevLed1Millis > 300)
    {
      analogWrite(LED1, 0);
      curLightCount--;
    }

    if (curMillis - prevLed2Millis > 600)
    {
      analogWrite(LED2, 0);
      curLightCount--;
    }
    if (curMillis - prevLed3Millis > 900)
    {
      analogWrite(LED3, 0);
      curLightCount--;
    }
    if (curMillis - prevLed4Millis > 100)
    {
      analogWrite(LED4, 0);
      curLightCount--;
    }
    if (curMillis - prevLed5Millis > 1500)
    {
      analogWrite(LED5, 0);
      curLightCount--;
    }
    if (curMillis - prevLed6Millis > 1800)
    {
      analogWrite(LED6, 0);
      curLightCount--;
    }
    if (curMillis - prevLed7Millis > 2100)
    {
      analogWrite(LED7, 0);
      curLightCount--;
    }
    if (curMillis - prevLed8Millis > 2400)
    {
      analogWrite(LED8, 0);
      curLightCount--;
    }

    lightCount = curLightCount;
  }

  // {
  //   analogWrite(LED1, light);
  //   analogWrite(LED2, light);
  //   analogWrite(LED3, light);
  //   analogWrite(LED4, light);
  //   analogWrite(LED5, light);
  //   analogWrite(LED6, light);
  //   analogWrite(LED7, light);
  //   analogWrite(LED8, light);

  //   prevLed1Millis = millis();
  //   prevLed2Millis = millis();
  // }
  // else
  // {
  //   analogWrite(LED1, LOW);
  //   analogWrite(LED2, LOW);
  //   analogWrite(LED3, LOW);
  //   analogWrite(LED4, LOW);
  //   analogWrite(LED5, LOW);
  //   analogWrite(LED6, LOW);
  //   analogWrite(LED7, LOW);
  //   analogWrite(LED8, LOW);
  // }

  // if (curMillis - prevLed1Millis > 1000)
  // {
  //   analogWrite(LED1, LOW);
  // }

  // if (curMillis - prevLed2Millis > 2000) 
  // {
  //   analogWrite(LED2, LOW);
  // }

  Serial.print(volume);
  Serial.print(", ");
  Serial.print(lightState);
  Serial.print(", ");
  Serial.print(lightCount);
  Serial.print(", ");
  Serial.println(curLightCount);
  delay(50);
}
