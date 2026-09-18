const int TRIG          = 9;        // TRIG 핀 설정 (초음파 보내는 핀)
const int ECHO          = 8;        // TRIG 핀 설정 (초음파 받는 핀)
const int BAUD          = 9600;
const int LED           = 7;        // 7번판에 추가한 LED
const int CHECK_LENGTH  = 15;

void setup() 
{
  Serial.begin(BAUD);
  pinMode(TRIG, OUTPUT);            // TRIG 에서 보내고
  pinMode(ECHO, INPUT);             // ECHO 에서 받는다
  pinMode(LED, OUTPUT);             // 7번 LED도 출력용
}

void loop() 
{
  long duration = 0;
  long distance = 0;
  int  isLEDOn  = 0;

  // LOW > HIGH > LOW 펄스를 만들어 보내고
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  // 시간을 거리(cm)로 계산 (34000 / 1000000 / 2 를 간단하게)
  distance = duration * 17 * 0.001;

  // 출력
  Serial.print("Duration : ");
  Serial.print(duration);
  Serial.print(", Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < CHECK_LENGTH)
  {
    isLEDOn = 1;
  }
  else
  {
    isLEDOn = 0;
  }

  digitalWrite(LED, isLEDOn);
  delay(500);
}
