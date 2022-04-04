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
int count = 0;
void setup() {
    // put your setup code here, to run once:
    tm.begin();
    Serial.begin(115200);
    Serial.println("Started");
    tm.displayCache[0] = 0x00;
    tm.displayCache[1] = 0x3c;
    tm.displayCache[2] = 0x42;
    tm.displayCache[3] = 0x42;
    tm.displayCache[4] = 0x42;
    tm.displayCache[5] = 0x42;
    tm.displayCache[6] = 0x3c;
    tm.displayCache[7] = 0x00;
    for( uint8_t b=0; b<8; b++){
        tm.setBrightness(b);
        delay(500);
    }
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    buttonState = digitalRead(BUTTON_PIN);  //讀取按鍵的狀態
    if(buttonState == LOW){          //如果按鍵按了
        count++;  
    }
    if(count==1){
        tm.displayCache[0] = 0x00;
        tm.displayCache[1] = 0xfc;
        tm.displayCache[2] = 0x26;
        tm.displayCache[3] = 0x22;
        tm.displayCache[4] = 0x26;
        tm.displayCache[5] = 0xfc;
        tm.displayCache[6] = 0x00;
        tm.displayCache[7] = 0x00;
    }
    if(count==2){
        tm.displayCache[0] = 0x00;
        tm.displayCache[1] = 0xfe;
        tm.displayCache[2] = 0x92;
        tm.displayCache[3] = 0x92;
        tm.displayCache[4] = 0x92;
        tm.displayCache[5] = 0x6c;
        tm.displayCache[6] = 0x00;
        tm.displayCache[7] = 0x00;
    }
    for( uint8_t b=0; b<8; b++){
        tm.setBrightness(b);
        delay(500);
    }
}
