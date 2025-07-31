#define SERIAL_PORT 115200
#define VIBRATE_PIN 20

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  Serial.println("vibrating...");
  digitalWrite(VIBRATE_PIN, HIGH);
}
