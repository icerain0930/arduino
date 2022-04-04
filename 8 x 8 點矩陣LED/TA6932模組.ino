#include <TA6932.h>

// Power should go to 3.3-5v and GND
// Power MUST be 5v in case using Blue color LED

#define PIN_TA6932_STB   8
#define PIN_TA6932_CLK   9
#define PIN_TA6932_DIN  10

TA6932 tm(PIN_TA6932_STB, PIN_TA6932_CLK, PIN_TA6932_DIN);
//------------------------
const int BUTTON_PIN = 2;
int buttonState = 0;

void setup() {
    // put your setup code here, to run once:
    tm.begin();
    Serial.begin(115200);
    Serial.println("Started");
    tm.displayCache[0] = 0x51; //20~27設定圖案
    tm.displayCache[1] = 0x21;
    tm.displayCache[2] = 0xd1;
    tm.displayCache[3] = 0x22;
    tm.displayCache[4] = 0xa4;
    tm.displayCache[5] = 0x72;
    tm.displayCache[6] = 0x15;
    tm.displayCache[7] = 0x90;
    tm.updateDisplay();
    for( uint8_t b=0; b<8; b++)
    {
        tm.setBrightness(b);
        delay(1000);
    }

    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    buttonState = digitalRead(BUTTON_PIN);  //讀取按鍵的狀態

  if(buttonState == LOW){          //如果按鍵按了
    tm.displayCache[0] = 0x51;
    tm.displayCache[1] = 0x21;
    tm.displayCache[2] = 0xd1;
    tm.displayCache[3] = 0x22;
    tm.displayCache[4] = 0xa4;
    tm.displayCache[5] = 0x72;
    tm.displayCache[6] = 0x15;
    tm.displayCache[7] = 0x90;
    for( uint8_t b=0; b<8; b++)
    {
        tm.setBrightness(b);
        delay(100);
    }
  }else{                           //如果按鍵是未按下
    tm.displayCache[0] = 0x00;
    tm.displayCache[1] = 0x00;
    tm.displayCache[2] = 0x00;
    tm.displayCache[3] = 0x00;
    tm.displayCache[4] = 0x00;
    tm.displayCache[5] = 0x00;
    tm.displayCache[6] = 0x00;
    tm.displayCache[7] = 0x00;
    for( uint8_t b=0; b<8; b++)
    {
        tm.setBrightness(b);
        delay(100);
    }
  }
}
