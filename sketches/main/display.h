#include <Wire.h>
#include "HT_SSD1306Wire.h"
#include "image.h"

#define image_width 60
#define image_height 60
#define BABY_TXT "Baby Crying"
#define PHONE_TXT "Phone"
#define ALARM_TXT "Alarm"
#define DISPLAY_DELAY 1000

static SSD1306Wire display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);

class Display {
private:
  void displayText(String text, const unsigned char* figure) {
    display.clear();
    display.drawXbm(0, 0, 60, 60, figure);
    display.setFont(ArialMT_Plain_16);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    int x = display.width() - 6;
    int y = display.height() - 20;
    display.drawString(x, y, text);
    display.display();
  }

  void displayClock() {
    display.clear();
    display.setFont(ArialMT_Plain_24);
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    int x = display.width() / 2;
    int y = display.height() / 2 - 5;
    display.drawString(x, y, "12:00");
    display.display();
  }
  void displayBabyCrying() {
    this->displayText(BABY_TXT, baby_cry_bits);
  }
  void displaySiren() {
    this->displayText(ALARM_TXT, siren_bits);
  }
  void displayPhone() {
    this->displayText(PHONE_TXT, telephone_bits);
  }

  enum State {
    IDLE,
    BABY_CRYING,
    SIREN,
    PHONE
  };

  State state;

  unsigned long warningStartTime;

public:
  Display() {
    display.init();
    state = IDLE;
  }

  void loop() {
    switch (state) {
      case IDLE:
        this->displayClock();
        break;
      case BABY_CRYING:
        this->displayBabyCrying();
        break;
      case SIREN:
        this->displaySiren();
        break;
      case PHONE:
        this->displayPhone();
        break;
    }
    this->transitionToIdleWhenWarningEnds();
  }

  void warningStart() {
    this->warningStartTime = millis();
  }

  void transitionToIdleWhenWarningEnds() {
    if (!this->isWarningHappening()) {
      this->transitionToIdle();
    }
  }

  bool isWarningHappening() {
    return millis() - this->warningStartTime < DISPLAY_DELAY;
  }

  void transitionToIdle() {
    if (this->state == IDLE) return;
    this->state = IDLE;
    Serial.println("[display STATE]: IDLE");
    this->loop();
  }
  void transitionToBabyCrying() {
    if (this->state == BABY_CRYING) return;
    if (this->isWarningHappening()) return;

    this->warningStart();
    this->state = BABY_CRYING;
    Serial.println("[display STATE]: BABY_CRYING");
    this->loop();
  }
  void transitionToSiren() {
    if (this->state == SIREN) return;
    if (this->isWarningHappening()) return;

    this->warningStart();
    this->state = SIREN;
    Serial.println("[display STATE]: SIREN");
    this->loop();
  }
  void transitionToPhone() {
    if (this->state == PHONE) return;
    if (this->isWarningHappening()) return;

    this->warningStart();
    this->state = PHONE;
    Serial.println("[display STATE]: PHONE");
    this->loop();
  }
};
