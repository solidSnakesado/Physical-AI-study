#include <SPI.h>
#include <MFRC522.h>

const int RST_PIN = 9;
const int SS_PIN = 10;

MFRC522 rc522(SS_PIN, RST_PIN);

void setup() 
{
  Serial.begin(9600);

  SPI.begin();
  rc522.PCD_Init();

  Serial.println("start");
}

MFRC522::StatusCode checkAuth(int index, MFRC522::MIFARE_Key key)
{
  MFRC522::StatusCode status = rc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, index, &key, &(rc522.uid));

  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("Authentication Failed : ");
    Serial.println(rc522.GetStatusCodeName(status));
  }

  return status;
}

MFRC522::StatusCode writeString(int index, MFRC522::MIFARE_Key key, String data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }

  char buffer[16];
  memset(buffer, 0x00, sizeof(buffer));
  data.toCharArray(buffer, data.length() + 1);

  status = rc522.MIFARE_Write(index, (byte*)&buffer, 16);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("Write Failed : ");
    Serial.println(rc522.GetStatusCodeName(status));
  }

  return status;
}

MFRC522::StatusCode readString(int index, MFRC522::MIFARE_Key key, String& data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }
}

void loop() 
{
  String cmd = "";
  while (Serial.available() > 0)
  {
    cmd = Serial.readStringUntil('\n');
  }

  if (!rc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if (!rc522.PICC_ReadCardSerial())
  {
    return;
  }

  if (cmd.length() > 0 && cmd == "w")
  {
    Serial.print("cmd : ");
    Serial.println(cmd);
  }
  else
  {
    return;
  }

  const int index = 60;
  MFRC522::StatusCode status;

  MFRC522::MIFARE_Key key;
  for (int i = 0; i < 6; ++i)
  {
    key.keyByte[i] = 0xFF;
  }

  if (cmd.length() > 0)
  {
    Serial.print("cmd : ");

    switch(cmd[0])
    {
      case 'w':
        Serial.println("write");
        status = writeString(60, key, "nomaefg");
        break;
      default:
        Serial.println("unknown");
        status = MFRC522::STATUS_ERROR;
        break;
    }

    if (status == MFRC522::STATUS_OK)
    {
      Serial.println("success!");
    }
  }
}
