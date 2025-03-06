#include <Servo.h> // подключаем библиотеку для работы с сервоприводом
int analogfotoLeft = A2; // порт левого фоторезистора
int analogfotoRight = A0;// порт правого фоторезистора
int analogfotoback = A1; // порт левого фоторезистора
int analogfotoface = A3;// порт правого фоторезистора
int kr1 = 30; // меньший порог для 9го
int kr2 = 150; // меньший порог для 9го
int kr3 = 45; // меньший порог для 10го
int kr4 = 135;  // меньший порог для 10го
//Servo servo1; // объявляем переменную servo типа "servo1"
Servo servo2; // объявляем переменную servo типа "servo1"
void setup() {
              // servo1.attach(9); // привязываем сервопривод к аналоговому выходу 11
              servo2.attach(10); // привязываем сервопривод к аналоговому выходу 11
              Serial.begin(9600); // чтоб сериал работал
              // servo1.write(90); // ставим 9й в начальное положение
              servo2.write(90); // ставим 10й в начальное положение
              }// скобка

void loop() {
              //delay(2000);
              //int servov1 = servo1.read(); // читаем градусы с 9го
              int servov2 = servo2.read(); // читаем градусы с 10го
              //int fLeft = analogRead(analogfotoLeft); // присваиваем переменной показания левого фоторезистора
              //int fRight = analogRead(analogfotoRight);// присваиваем переменной показания правого фоторезистора
              int fback = analogRead(analogfotoback); // присваиваем переменной показания левого фоторезистора
              int fface = analogRead(analogfotoface);// присваиваем переменной показания правого фоторезистора
              /* Serial.println("----------");
              Serial.print("Right:"); //вывод показаний фоторезистора
              Serial.println(fRight); //вывод показаний фоторезистора
              Serial.println(' '); //вывод показаний фоторезистора
              Serial.print("Left:"); //вывод показаний фоторезистора
              Serial.println(fLeft); //вывод показаний фоторезистора
              Serial.println(' '); //вывод показаний фоторезистора
              Serial.print("back:"); //вывод показаний фоторезистора
              Serial.println(fback); //вывод показаний фоторезистора
              Serial.println(' '); //вывод показаний фоторезистора
              Serial.print("face:"); //вывод показаний фоторезистора
              Serial.println(fface); //вывод показаний фоторезистора
              Serial.println(' '); //вывод показаний фоторезистора*/
              //servo1.write(90); // ставим угол поворота под 90
              /*if(fLeft < fRight){ //если разница между прказаниями больше 75, то...
                            servo1.write(servov1 - 10);// крутим в лево
              }else if(fLeft > fRight) { // иначе
                            servo1.write(servov1 + 10);// крутим в право
              }*/
              if(abs(fback - fface) > 20 and servov2 + 5 < kr2 and fback <= fface){ //если разница между прказаниями больше 20, то...
                            servo2.write(servov2 + 5);// крутим в лево
              }else if(abs(fback - fface) > 20 and fback > fface and servov2 - 5 > kr1) { // иначе
                            servo2.write(servov2 - 5);// крутим в право
              }
              /*if(abs(fLeft - fRight) > 20 and servov1 + 5 < kr4 and fLeft <= fRight){ //если разница между прказаниями больше 20, то...
                            servo2.write(servov1 + 5);// крутим в лево
              }else if(abs(fLeft - fRight) > 20 and fLeft > fRight and servov1 - 5 > kr3) {
                            servo2.write(servov1 - 5);// крутим в право*/
              //}
              //if(abs(fLeft - fRight) < 100 and (servov2 > kr1 and servov2 < kr2)){ 
                            // int q = abs(fLeft - fRight); // записываем разницу показаний
                            //servo2.write(servov2 - 5); // крутим мотор на 5 градусов
              //if(q < abs(fLeft - fRight) and (servov2 > kr1 and servov2 < kr2)){ // если новая  разница показаний меньше чем старая, то...
                            // servo2.write(servov2 + 5);// поворачиваем обратно на 5 градусов
                            //servo2.write(servov2 + 5); // крутим вправа
              //}else{
                            //  servo2.write(servov2 + 5);// поворачиваем обратно на 5 градусов
                            //servo2.write(servov2 - 5); // крутим вправа
              //}
              //}/*
              delay(200);// задержка 50 милисек
              // delay(2000); // ждем 2 секунды
              //servo1.write(180); // ставим угол поворота под 180
              //  delay(2000); // ждем 2 секунды
              }