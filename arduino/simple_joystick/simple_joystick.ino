#include <Servo.h>

const int X_AXIS      = A0;
const int Y_AXIS      = A1;
const int ZERO_POS_X  = 507;
const int ZERO_POS_Y  = 536;
const int SERVO       = 9;  

Servo servo;

void setup() 
{
  Serial.begin(9600);
  servo.attach(SERVO);

  servo.write(0);
}

void loop() 
{
  int x = analogRead(X_AXIS);
  int y = analogRead(Y_AXIS);

  // 영점 보정
  x = x - ZERO_POS_X;
  y = (y - ZERO_POS_Y) * -1;

  if (abs(x) < 10)
  {
    x = 0;
  }

  if (abs(y) < 10)
  {
    y = 0;
  }

  // int x_pos = map(x, ZERO_POS_X * -1, ZERO_POS_X, 0, 180);
  // servo.write(x_pos);

  double degree = atan2(y, x) * 180 / PI;
  if (degree < 0)
  {
    degree = degree * -1;
  }

  // degree = 180 - degree;
  servo.write(degree);

  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  // Serial.print(", ");
  // Serial.println(degree);
  Serial.print(", ");
  Serial.println(degree);
  delay(100);
}
