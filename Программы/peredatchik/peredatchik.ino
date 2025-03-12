#include <Gyver433.h>
Gyver433_TX<2> tx;  // указали пин
#define PIN_PHOTO_SENSOR A0
void setup() {
  Serial.begin(9600);
}
//char data[] = "Hello from #xx"; // строка для отправки
//byte count = 0;                 // счётчик для отправки
void loop() {
  
  // добавляем счётчик в строку
    int val = analogRead(PIN_PHOTO_SENSOR);
      Serial.println(val);
  //data[12] = (count / 10) + '0';
  //data[13] = (count % 10) + '0';
  //if (++count >= 100) count = 0;

  tx.sendData(val);
//Serial.println(val);
  delay(100);
}
