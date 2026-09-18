#include <Servo.h>                                  // Servo 모터는 라이브러리가 필요
Servo servo;                                        // Servo 객체 선언

const int BAUD                  = 9600;
const int SERVO_PIN_NUMBER      = 3;                // servo 핀번호
const int BUTTON                = 4;                // Push Button 이 연뎔된 PIN 번호
const int ROTATION_VALUE        = 10;               // 회전 값
int       prevButtonValue;                          // 버튼의 이전 값 저장 변수
int       currentServoValue;                        // 모터의 현재 값 저장 변수
int       currentServoDirection;                    // 모터의 회전 반향

void setup() 
{
  Serial.begin(BAUD);
  servo.attach(SERVO_PIN_NUMBER);                   // servo 초기화 (핀번호)
  servo.write(0);

  pinMode(BUTTON, INPUT);                           // Button은 입력용

  prevButtonValue       = HIGH;
  currentServoValue     = 0;
  currentServoDirection = 1;                        // 1이면 증가, 0이면 감소
}

void setServoDir()
{
  if(currentServoValue + ROTATION_VALUE > 180)
  {
    currentServoDirection = -1;
  }
  else if (currentServoValue - ROTATION_VALUE < 0)
  {
    currentServoDirection = 1;
  }
}

void servoRotation()
{
  currentServoValue += (ROTATION_VALUE * currentServoDirection);

  Serial.println(currentServoValue);
  servo.write(currentServoValue);
}

void loop() 
{
  int input = digitalRead(BUTTON);                    // Button 입력값 체크

  if (input != prevButtonValue && input == LOW)
  {
    setServoDir();
    servoRotation();
    
    delay(15);
  }

  prevButtonValue = input;
}


