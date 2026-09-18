#include <Servo.h>                    // Servo 모터는 라이브러리가 필요
Servo servo;                          // Servo 객체 선언

const int PIR               = 2;
const int LEDBLUE           = 3;
const int SERVO_PIN_NUMBER  = 4;      // servo 핀번호

unsigned long prevMillis;
int ledInterval;
int servoInterval;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(LEDBLUE, OUTPUT);
  servo.attach(SERVO_PIN_NUMBER);     // servo 초기화 (핀번호)
  servo.write(0);

  prevMillis    = 0;
  ledInterval   = 5000;
  servoInterval = 10000;
}

void loop() 
{
  int           input     = digitalRead(PIR);
  unsigned long curMillis = millis();

  if (input == HIGH)
  {
    prevMillis = millis();
    digitalWrite(LEDBLUE, input);
    Serial.println(input);
    servo.write(180);
  }

  if (curMillis - prevMillis >= ledInterval)
  {
    digitalWrite(LEDBLUE, LOW);
    Serial.println(LOW);
    
  }

  if (curMillis - prevMillis >= servoInterval)
  {
    servo.write(0);
  }
  
  delay(100);
}
