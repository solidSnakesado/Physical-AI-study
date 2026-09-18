const int BAUD    = 9600;
const int BUTTON  = 2;

enum ColorType
{
  OFF   = 8,
  RED   = 9,
  GREEN = 10,
  BLUE  = 11,
};

int prevBtnVal;
ColorType color;

void setup() 
{
  Serial.begin(BAUD);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);

  prevBtnVal  = LOW;
  color       = OFF;
}

void getNextColor()
{
  if (color == BLUE)
  {
    color = OFF;
  }
  else
  {
    color = (ColorType) (color + 1);
  }
}

void setColor(ColorType type, int state)
{
  if (state == HIGH)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    digitalWrite(type, state);
  }
}

void loop() 
{
  int input = digitalRead(BUTTON);  // Button 입력값 체크

  if (prevBtnVal != input && input == HIGH)                // Button 이 눌러졌으면
  {
    getNextColor();
    setColor(color, HIGH);
  }

  prevBtnVal = input;

  Serial.println(input);
  delay(100);
}
