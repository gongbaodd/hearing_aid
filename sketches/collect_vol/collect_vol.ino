#define AUDIO_PIN A0
#define SAMPLE_RATE 16000  // Hz
#define SAMPLE_INTERVAL_US (1000000 / SAMPLE_RATE)  // 62.5us

void setup() {
  Serial.begin(115200);  // 确保你的波特率足够快
}

void loop() {
  static unsigned long lastMicros = 0;
  unsigned long now = micros();
  
  if (now - lastMicros >= SAMPLE_INTERVAL_US) {
    lastMicros = now;
    int audioValue = analogRead(AUDIO_PIN);
    Serial.println(audioValue);  // 只发音频值，PC 端加时间戳也可以
  }
}