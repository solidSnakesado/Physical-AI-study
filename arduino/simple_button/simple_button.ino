const int BUTTON    = 2;            // Push Button 이 연결된 PIN 번호
const int LED       = 7;            // 7번판에 추가한 LED
int       pre_state;                // Push Button 의 이전 상태를 저장할 변수

void setup() 
{
  Serial.begin(9600);               // Serial 통신 시작 (baud : 9600)
  pinMode(LED_BUILTIN, OUTPUT);     // LED 는 출력용

  pinMode(LED, OUTPUT);             // 7번 LED도 출력용

  pinMode(BUTTON, INPUT);           // Button 은 입력용
  pre_state = LOW;                  // 최초의 상태는 LOW
}

void loop() 
{
  int input = digitalRead(BUTTON);  // Button 입력값 체크

  // if (input == HIGH)                // Button 이 눌러졌으면 
  // {
  //   digitalWrite(LED_BUILTIN, HIGH);
  // }
  // else                              // Button 이 눌러지지 않았으면
  // {       
  //   digitalWrite(LED_BUILTIN, LOW);
  // }

  // digitalWrite(LED_BUILTIN, input);
  // Serial.println(input);

  if (input != pre_state)
  {
    pre_state = input;

    if (input == HIGH)
    {
      Serial.println("13 On / 7 Off");
    }
    else
    {
      Serial.println("13 Off / 7 On");
    }
    
    digitalWrite(LED_BUILTIN, input);
    digitalWrite(LED, !input);
  }
}
