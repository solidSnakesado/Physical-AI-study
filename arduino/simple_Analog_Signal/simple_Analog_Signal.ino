#include <Servo.h>
Servo servo;

const int interval = 150;

const int interval1 = 100;
int bgCheck = 0;

int maxVal;
int minVal;
int avgCheckCount;
int avgValue;
int sumValue;
int servoVal;
int timeCheck;
int backGroundLight = 0;
unsigned long prevMillis = 0;
unsigned long prevMillis1 = 0;

int ck1 = 0;
long ckSum = 0;
int ckAvg = 0;

void setup() 
{
  Serial.begin(9600);
  servo.attach(3);
  servo.write(0);

  maxVal = 0;
  minVal = 1023;
  avgCheckCount = 0;
  avgValue = 0;
  sumValue = 0;
  timeCheck = 0;
}

void setAvg(int curVal)
{
  if (avgCheckCount < 10)
  {
    avgCheckCount += 1;
    sumValue += curVal;
  }
  else
  {
    // 사실 이 연산 전에 sumValue 와 avgValue 의 값이 
    avgValue = sumValue / avgCheckCount;
    sumValue = 0;
    avgCheckCount = 0;
  }
}

void setBackGroundLight(int light)
{
  if(ck1 < 100)
  {
    ++ck1;
    ckSum += light;
  }
  else
  {
    ckAvg = (int)(ckSum / ck1);
    ckSum = 0;
    ck1 = 0;
  }
}

void loop() 
{
  int light = analogRead(A0);      
  unsigned long curMillis = millis();                              

  if (maxVal < light)
  {
    maxVal = light;
  }
  else if(minVal > light)
  {
    minVal = light;
  }
  
  //if (avgValue < minVal)
  {
    setAvg(light);
    setBackGroundLight(light);
  }

  // if (ckAvg > 300)
  // {
  //   if ((avgValue * 0.9) > light)
  //   {
  //     servoVal = 20;
  //   }
  // }
  // else if (ckAvg < 50)
  // {
  //   if ((maxVal * 0.8) < light)
  //   {
  //     servoVal = 20;
  //   }
  // }

  int temp = avgValue - light;
  if (temp < 0)
  {
    temp = temp * -1;
  }

  if (temp > 30)
  {
    servoVal = 20;
  }
  

  if (servoVal > 0 && timeCheck == 0)
  {
    prevMillis = millis();  
    timeCheck = 1;
    servo.write(servoVal);
  }
  else if (timeCheck == 1)
  {
    // 여기서 부터 타임 쳌,해서 0.2초 후에 모터 제자리
    if (curMillis - prevMillis >= interval)
    {
      prevMillis = curMillis;
      timeCheck = 0;
      servoVal = 0;
      servo.write(servoVal);
    }
  }

  Serial.print(ck1);
  Serial.print(", ");
  Serial.print(ckSum);
  Serial.print(", ");
  Serial.println(ckAvg);
}
