// FFT


#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <arduinoFFT.h>


#define SERIAL_PORT 9600
#define VIBRATE_PIN 13
#define BUTTON_PIN 2
#define AUDIO_DATA A0

#define BABY_VOL 100
#define BABY_FREQ 300
#define BABY_TXT "Baby Crying"

#define ALARM_VOL 100
#define ALARM_FREQ 200
#define ALARM_TXT "Alarm"

#define PHONE_VOL 100
#define PHONE_FREQ 150
#define PHONE_TXT "Phone"

#define VIBRATING_TIME 1000
bool isVibrating = false;
unsigned long vibratingTime = 0;

#define STOPPED_TIME 10000
bool isStopped = false;
unsigned long stoppedTime = 0;

double vol = 0;
double freq = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
String content = "";

// FFT
ArduinoFFT<double> FFT = ArduinoFFT<double>();

#define SAMPLES 128              //SAMPLES-pt FFT. Must  be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 9600  //Ts = Based on Nyquist, must be 2 times the highest expected frequency.

unsigned int samplingPeriod = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
unsigned long microSeconds;

double vReal[SAMPLES];  //create vector of size SAMPLES to hold real values
double vImag[SAMPLES];  //create vector of size SAMPLES to hold imaginary values

double findPeak() {
  for (int i = 0; i < SAMPLES; i++) {
    microSeconds = micros();  //Returns the  number of microseconds since the Arduino board began running the current script.

    vReal[i] = analogRead(AUDIO_DATA);  //Reads the value from analog pin  0 (A0), quantize it and save it as a real term.
    vImag[i] = 0;                       //Makes  imaginary term 0 always


    /*remaining wait time between samples if  necessary*/
    while (micros() < (microSeconds + samplingPeriod)) {
      //do nothing
    }
  }

  /*Perform FFT on samples*/
  FFT.windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.complexToMagnitude(vReal, vImag, SAMPLES);


  /*Find peak frequency and print peak*/
  double peak = FFT.majorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
  return peak;
}
// End of FFT

void setup() {
  pinMode(VIBRATE_PIN, OUTPUT);
  pinMode(AUDIO_DATA, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(SERIAL_PORT);


  lcd.init();
  lcd.backlight();
}

void loop() {
  if (isStopped) {
    if (millis() - stoppedTime > STOPPED_TIME) {
      isStopped = false;
      lcd.clear();
    }
    return;  // stop sensoring because user is acknowledged
  }

  if (digitalRead(BUTTON_PIN) == HIGH) {
    isStopped = true;
    isVibrating = false;
    stoppedTime = millis();
    digitalWrite(VIBRATE_PIN, LOW);
    return;  // user tap stop button
  }

  if (isVibrating && (millis() - vibratingTime < VIBRATING_TIME)) {
    return;  // keep vibrating for a while
  }

  // use Vol to set vibrating state
  vol = analogRead(AUDIO_DATA);

  if (vol > BABY_VOL) {
    content = BABY_TXT;
    isVibrating = true;
  }

  if (vol > ALARM_VOL) {
    content = ALARM_TXT;
    isVibrating = true;
  }

  if (vol > PHONE_VOL) {
    content = PHONE_TXT;
    isVibrating = true;
  }

  // use freq to set vibrating state
  freq = findPeak();

  if (freq > BABY_FREQ) {
    content = BABY_TXT;
    isVibrating = true;
  }

  if (freq > ALARM_FREQ) {
    content = ALARM_TXT;
    isVibrating = true;
  }

  if (freq > PHONE_FREQ) {
    content = PHONE_TXT;
    isVibrating = true;
  }

  handleVibrating();
}

void handleVibrating() {
  // decide vibrating
  if (isVibrating) {
    vibratingTime = millis();
    digitalWrite(VIBRATE_PIN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print(content);
  } else {
    digitalWrite(VIBRATE_PIN, LOW);
    lcd.clear();
  }
}
