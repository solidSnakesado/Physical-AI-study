#include <SPI.h>
#include <MFRC522.h>

const int RST_PIN = 9;
const int SS_PIN = 10;

String cmd = "";   // loop 밖, 전역

MFRC522 rc522(SS_PIN, RST_PIN);

struct TagData
{
  char name[16];
  long total;
  long payment;
};

TagData structData;
String  srtTemp;
String  strData;
int     nData;



void setup() 
{
  Serial.begin(9600);

  SPI.begin();
  rc522.PCD_Init();
  // rc522.PCD_SetAntennaGain(rc522.RxGain_max);

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

  // read data
  byte buffer[18];
  byte length = 18;

  status = rc522.MIFARE_Read(index, buffer, &length);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("Read Failed: ");
    Serial.println(rc522.GetStatusCodeName(status));
  }
  else
  {
    data = String((char*)buffer);
  }

  return status;
}

void toBytes(byte* buffer, int data, int offset = 0)
{
  buffer[offset] = data & 0xFF;
  buffer[offset + 1] = (data >> 8) & 0xFF;
}

MFRC522::StatusCode writeInteger(int index, MFRC522::MIFARE_Key key, int data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }

  // write integer
  byte buffer[16];
  memset(buffer, 0x00, sizeof(buffer));
  toBytes(buffer, data);

  status = rc522.MIFARE_Write(index, buffer, sizeof(buffer));
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("Write Failed: ");
    Serial.println(rc522.GetStatusCodeName(status));
  }

  return status;
}

int toInterger(byte* buffer, int offset = 0)
{
  return (buffer[offset + 1] << 8 | buffer[offset]);
}

MFRC522::StatusCode readInterger(int index, MFRC522::MIFARE_Key key, int& data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }

  byte buffer[18];
  byte length = 18;

  status = rc522.MIFARE_Read(index, buffer, &length);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("Read Failed: ");
    Serial.println(rc522.GetStatusCodeName(status));
  }
  else
  {
    data = toInterger(buffer);
  }

  return status;
}

MFRC522::StatusCode writeTagData(int index, MFRC522::MIFARE_Key key, TagData data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }

  byte buffer[32];
  memset(buffer, 0x00, sizeof(buffer));
  memcpy(buffer, &data, sizeof(data));

  for (int i = 0; i < 2; ++i)
  {
    status = rc522.MIFARE_Write(index + i, buffer + (i * 16), 16);
    if (status != MFRC522::STATUS_OK)
    {
      Serial.print("Write Failed: ");
      Serial.println(rc522.GetStatusCodeName(status));
    }
  }

  return status;
}

MFRC522::StatusCode readTagData(int index, MFRC522::MIFARE_Key key, TagData& data)
{
  MFRC522::StatusCode status = checkAuth(index, key);
  if (status != MFRC522::STATUS_OK)
  {
    return status;
  }

  byte buffer[34];
  byte length = 18;

  for (int i = 0; i < 2; ++i)
  {
    status = rc522.MIFARE_Read(index + i, buffer + (i * 16), &length);
    if (status != MFRC522::STATUS_OK)
    {
      Serial.print("Read Failed: ");
      Serial.println(rc522.GetStatusCodeName(status));
    }
  }

  memcpy(&data, buffer, sizeof(data));
  return status;
}

void loop() 
{
  while (Serial.available() > 0)
  {
    cmd = Serial.readStringUntil('\n');
    cmd.trim();
  }

  if (cmd.length() == 0)
  {
    return;
  }

  if (!rc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if (!rc522.PICC_ReadCardSerial())
  {
    return;
  }

  // if (cmd.length() > 0)
  // {
  //   Serial.print("cmd : ");
  //   Serial.println(cmd);
  // }
  // else
  // {
  //   return;
  // }

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

    if (cmd.length() < 3)
    {
      switch(cmd.charAt(0))
      {
        case 'w':
          Serial.print("write ");
          switch (cmd.charAt(1))
          {
            case 's':
              Serial.println("string");
              status = writeString(60, key, "nomaefg");
              break;
            case 'i':
              Serial.println("integer");
              status = writeInteger(61, key, 32767);
              rc522.PICC_DumpToSerial(&(rc522.uid));
              break;
            case 't':
              Serial.println("struct");
              srtTemp = "nomaefg";
              srtTemp.toCharArray(structData.name, srtTemp.length() + 1);
              structData.total = 2147483647;
              structData.payment = 2000000000;
              status = writeTagData(56, key, structData);
              rc522.PICC_DumpToSerial(&(rc522.uid));
              break;
            default:
              Serial.println("unknown type");
              status = MFRC522::STATUS_ERROR;
              break;
          }
          break;
        case 'r':
          Serial.print("read ");
          switch (cmd.charAt(1))
          {
            case 's':
              Serial.println("string");
              status = readString(60, key, strData);
              Serial.println(strData);
              break;
            case 'i':
              Serial.println("integer");
              status = readInterger(61, key, nData);
              Serial.println(nData);
              break;
            case 't':
              Serial.println("struct");
              status = readTagData(56, key, structData);
              if (status == MFRC522::STATUS_OK)
              {
                Serial.print(" name: ");
                Serial.println(String(structData.name));
                Serial.print(" total: ");
                Serial.println(String(structData.total));
                Serial.print(" payment: ");
                Serial.println(String(structData.payment));
              }
              
              break;
            default:
              Serial.println("unknown type");
              status = MFRC522::STATUS_ERROR;
              break;
          }
          break;
          
        default:
          Serial.println("unknown");
          status = MFRC522::STATUS_ERROR;
          break;
      }
    }
    else
    {
      Serial.println("string input");
      Serial.println("struct");
      srtTemp = cmd;
      srtTemp.toCharArray(structData.name, srtTemp.length() + 1);
      structData.total = 2147483647;
      structData.payment = 2000000000;
      status = writeTagData(56, key, structData);
      rc522.PICC_DumpToSerial(&(rc522.uid));
    }

    if (status == MFRC522::STATUS_OK)
    {
      Serial.println("success!");
    }
  }

  rc522.PICC_HaltA();
  rc522.PCD_StopCrypto1();
  cmd = "";
}
