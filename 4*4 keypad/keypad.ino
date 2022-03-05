#include <Key.h>
#include <Keypad.h>

char keys[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte col[4]={9,8,7,6};//1~4行
byte row[4]={13,12,11,10};//1~4列
Keypad keypad = Keypad( makeKeymap(keys), row, col, 4, 4 );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char input = keypad.getKey();
  if(input != NO_KEY){
    Serial.println(input);
  }
}
