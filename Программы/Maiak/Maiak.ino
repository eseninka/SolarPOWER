#define RELAY_IN 4 
void setup() {
  // пин реле как выход
  pinMode(RELAY_IN, OUTPUT);
  pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}
void loop() {
  // "мигаем"
  analogWrite(3, 255);
analogWrite(5, 255);
analogWrite(6, 255);
  digitalWrite(RELAY_IN, HIGH);

}