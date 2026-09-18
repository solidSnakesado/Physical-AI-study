enum LED_COLOR
{
  LED_BLUE = 3,
  LED_YELLOW,
  LED_RED
};

unsigned long prevLedBlueMillis;
unsigned long prevLedYellowMillis;
unsigned long prevLedRedMillis;

int ledBlueInterval;
int ledYellowInterval;
int ledRedInterval;

int ledBlueState;
int ledYellowState;
int ledRedState;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  ledBlueInterval   = 1000;
  ledYellowInterval = 3000;
  ledRedInterval    = 6000;

  ledBlueState      = LOW;
  ledYellowState    = LOW;
  ledRedState       = LOW;
}

void setLedState(LED_COLOR ledType, unsigned long& prevMillis, int ledInterval, int& ledState)
{
  unsigned long curMillis = millis();

  if (curMillis - prevMillis > ledInterval)
  {
    prevMillis = curMillis;

    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }

    digitalWrite(ledType, ledState);
  }
}

void loop() 
{
  setLedState(LED_BLUE, prevLedBlueMillis, ledBlueInterval, ledBlueState);
  setLedState(LED_YELLOW, prevLedYellowMillis, ledYellowInterval, ledYellowState);
  setLedState(LED_RED, prevLedRedMillis, ledRedInterval, ledRedState);
}
