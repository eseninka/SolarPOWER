#include <DHT.h>
#include <DHT_U.h>
#include <FastBot.h>

#define WIFI_SSID "Kosta" // Имя wifi
#define WIFI_PASS "aztj5781" // Пароль wifi
#define BOT_TOKEN ""//Токен бота
DHT dht(32, DHT11);  // сообщаем на каком порту будет датчик
int q = 0;
int q1 = 0;
int q2 = 0;
int q3 = 0;
bool rele = 0;
FastBot bot(BOT_TOKEN);
const int relay = 23;
const int sensorPin = 35;
void setup() {
  pinMode(33, OUTPUT);
  pinMode(35, INPUT);
  Serial.begin(9600);
  dht.begin();                // запускаем датчик DHT11
  connectWiFi();
  bot.attach(newMsg);
  pinMode(relay, OUTPUT);
  pinMode(25, OUTPUT);
pinMode(26, OUTPUT);
pinMode(27, OUTPUT);
}

void newMsg(FB_msg& msg) {
  Serial.print(msg.chatID);     // ID чата
  Serial.print(", ");
  Serial.print(msg.username);   // логин
  Serial.print(", ");
  Serial.println(msg.text);     // текст

  //  Убрали setChatID, чтобы бот отвечал всем.
  //  bot.setChatID(5445795880);

  //  Показывать меню при каждом новом сообщении
if(msg.text == "/start" || msg.text == "<-- в меню"){
  showMainMenu(msg.chatID);
}else if (msg.text == "Вкл/выкл прожектор") {
    bot.sendMessage("Состояние изменено", msg.chatID);
    rele = !rele;
    digitalWrite(relay, rele);
} else if (msg.text == "Управление светом") {
show2Menu(msg.chatID);
 } else if (msg.text == "Включить свет") {
    bot.sendMessage("Свет включен на всех этажах", msg.chatID);
q  = 255;
analogWrite(25, 255);
analogWrite(26, 255);
analogWrite(27, 255);    //  Убираем меню
} else if (msg.text == "Выключить свет") {
    bot.sendMessage("Свет на всех этажах выключен", msg.chatID);
q = 0;
analogWrite(25, 0);
analogWrite(26, 0);
analogWrite(27, 0);    //  Убираем меню
} else if(msg.text == "Cделать светлее"){
  bot.sendMessage("Свет +++", msg.chatID);
q += 85;
analogWrite(25, q);
analogWrite(26, q);
analogWrite(27, q);    //  Убираем меню
} else if(msg.text == "Сделать темнее"){
  bot.sendMessage("Свет ---", msg.chatID);
q -= 85;
analogWrite(25, q);
analogWrite(26, q);
analogWrite(27, q);    //  Убираем меню
}else if(msg.text == "Управление этажами"){
show3Menu(msg.chatID);


} else if(msg.text == "1й этаж"){
show4Menu(msg.chatID);
} else if(msg.text == "2й этаж"){
show5Menu(msg.chatID);
}else if(msg.text == "3й этаж"){
show6Menu(msg.chatID);
} else if(msg.text == "Сделать ярче на 1ом этаже"){
q1 += 85;
analogWrite(25, q1);
} else if(msg.text == "Сделать тускнее на 1ом этаже"){
q1 -= 85;
analogWrite(25, q1);
}
else if(msg.text == "Сделать ярче на 2ом этаже"){
q2 += 85;
analogWrite(27, q2);
}
else if(msg.text == "Сделать тускнее на 2ом этаже"){
q2 -= 85;
analogWrite(27, q2);
}else if(msg.text == "Сделать ярче на 3ем этаже"){
q3 += 85;
analogWrite(26, q3);
}
else if(msg.text == "Сделать тускнее на 3ем этаже"){
q3 -= 85;
analogWrite(26, q3);
}else if("Показания датчиков", msg.chatID){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int val = analogRead(sensorPin);
  String stat = "Статус системы:\n";
  stat += "Реле: " + String(rele ? "ВЫКЛ" : "ВКЛ") + "\n";
  stat += "Температура: " + String(t) + " C\n";
  stat += "Влажность: " + String(h) + " %\n";
  stat += "Уровень освещения: " + String(val) + " \n";
    bot.sendMessage(stat, msg.chatID);
} 
}
void loop() {
  bot.tick();
}
void show2Menu(String chatID){
  String menu1= "Cделать светлее \n Сделать темнее \n Управление этажами \n <-- в меню\n";
    bot.showMenu(menu1, chatID);
}
void showMainMenu(String chatID){
  String menu2= "Вкл/выкл прожектор \n Управление светом \n Показания датчиков \n";
    bot.showMenu(menu2, chatID);
}
void show3Menu(String chatID){
  String menu3= "1й этаж \n 2й этаж \n 3й этаж \n <-- \n";
    bot.showMenu(menu3, chatID);
}
void show4Menu(String chatID){
  String menu4= "Сделать ярче на 1ом этаже \n Сделать тускнее на 1ом этаже \n <-- в меню\n";
    bot.showMenu(menu4, chatID);
}
void show5Menu(String chatID){
  String menu5= "Сделать ярче на 2ом этаже \n Сделать тускнее на 2ом этаже \n <-- в меню\n";
    bot.showMenu(menu5, chatID);
}
void show6Menu(String chatID){
  String menu6= "Сделать ярче на 3ем этаже \n Сделать тускнее на 3ем этаже \n <-- в меню\n";
    bot.showMenu(menu6, chatID);
}
void connectWiFi() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
}
