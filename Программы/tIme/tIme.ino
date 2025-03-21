#include <ThreeWire.h>                                // Подключаем библиотеку ThreeWire
#include <RtcDS1302.h>                                // Подключаем библиотеку RtcDS1302

ThreeWire myWire(7,6,8);                              // Указываем вывода IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup () 
{
    Serial.begin(9600);                              // Установка последовательной связи на скорости 9600
    Serial.print("Data: ");                          // Отправка данных на последовательный порт
    Serial.println(__DATE__);                        // Получение даты и времени с ПК
    Serial.print("Time: ");                          // Отправка данных на последовательный порт
    Serial.println(__TIME__);                        // Получение даты и времени с ПК
    Rtc.Begin();                                     // Инициализация RTC
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); // Копирование даты и времени в compiled
    Rtc.SetDateTime(compiled);                       // Установка времени
    Serial.println();                                // Отправка данных на последовательный порт
} 

void loop () 
{
  Rtc.GetDateTime();
  RtcDateTime now = Rtc.GetDateTime();
  Serial.print("DATA RTC ");                         // Отправка данных на последовательный порт
  Serial.print(now.Day());                           // Отправка дня 
  Serial.print(now.Month());                         // Отправка месяца 
  Serial.print(".");                                 // Отправка данных на последовательный порт
  Serial.print(".");                                 // Отправка данных на последовательный порт
  Serial.print(now.Year());                          // Отправка года 
  Serial.print(" TIME RTC ");                        // Отправка данных на последовательный порт
  Serial.print(now.Hour());                          // Отправка часа 
  Serial.print(":");                                 // Отправка данных на последовательный порт
  Serial.print(now.Minute());                        // Отправка минут 
  Serial.print(":");                                 // Отправка данных на последовательный порт
  Serial.println(now.Second());                      // Отправка секунд 
  delay(1000);                                       // Пауза 1 с
}