#include <arduinoFFT.h>

#define SERIAL_PORT 9600
#define AUDIO_DATA A0

double freq = 0;

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
  pinMode(AUDIO_DATA, INPUT);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  freq = findPeak();
  Serial.println(freq);
}
