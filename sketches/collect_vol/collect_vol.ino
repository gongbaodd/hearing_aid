

#define AUDIO_PIN 7
#define SAMPLE_RATE 16000
#define SAMPLE_INTERVAL_US (1000000 / SAMPLE_RATE)

void setup() {
  Serial.begin(115200); 
}

void loop() {
  static unsigned long lastMicros = 0;
  unsigned long now = micros();
  
  if (now - lastMicros >= SAMPLE_INTERVAL_US) {
    lastMicros = now;
    int audioValue = analogRead(AUDIO_PIN);
    Serial.println(audioValue); 
  }

}