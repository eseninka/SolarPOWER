#include <Gyver433.h>
Gyver433_RX<2, 20> rx;  // указали пин и размер буфера
void setup() {
  Serial.begin(9600);  
  attachInterrupt(0, isr, CHANGE);  // прерывание пина радио по CHANGE
}
// спец. тикер вызывается в прерывании
void isr() {
  rx.tickISR();
}
void loop() {
  int q;
  if (rx.gotData()) {  
    rx.readData(q);                 // если успешно принято больше 0
    Serial.println(q);
   // Serial.write(rx.buffer, rx.size);   // выводим
   // Serial.println();
  }
}
















