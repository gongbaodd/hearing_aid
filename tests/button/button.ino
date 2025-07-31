#define SERIAL_PORT 115200
#define BUTTON_PIN 4

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("Button pressed");
  }
}
