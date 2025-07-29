#define SERIAL_PORT 9600
#define AUDIO_DATA A0

double vol = 0;

void setup() {
  pinMode(AUDIO_DATA, INPUT);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  vol = analogRead(AUDIO_DATA);
  Serial.println(vol);
}
